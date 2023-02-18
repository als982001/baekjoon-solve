#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string number;

string DecToBin(long long number)
{
	string result = "";

	while (number > 0)
	{
		number % 2 == 1 ? result += '1' : result += '0';
		number /= 2;
	}

	reverse(result.begin(), result.end());

	return result;
}

int NodeNum(string number)
{
	if (number.size() == 1)
		return 1;

	int len = 2;
	int currentNodeNum = number.size();
	int befNodeNum = 1;

	while (true)
	{
		int nodeNum = pow(2, len) - 1;

		if (befNodeNum < currentNodeNum && currentNodeNum <= nodeNum)
			return pow(2, len) - 1;

		++len;
		befNodeNum = nodeNum;
	}
}

bool Check(int start, int end)
{
	if (end - start == 1)
		return true;

	int parentIdx = (start + end) / 2;

	if (number[parentIdx] == '0')
	{
		int leftChildIdx = (start + parentIdx) / 2;
		int rightChildIdx = (parentIdx + 1 + end) / 2;

		if (number[leftChildIdx] == '1' || number[rightChildIdx] == '1')
			return false;
	}

	return Check(start, parentIdx) && Check(parentIdx + 1, end);
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;

	for (int i = 0; i < numbers.size(); ++i)
	{
		number = DecToBin(numbers[i]);
		
		int nodeNum = NodeNum(number);

		while (number.size() < nodeNum)
			number = "0" + number;
	
		bool success = Check(0, number.size());

		if (success)
			answer.push_back(1);
		else
			answer.push_back(0);
	}

	return answer;
}