#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char changeList[4] = { '0', '1', '2', '4' };

string solution(int n) {
    string answer = "";
    
	while (n > 0)
	{
		int r = n % 3;
		n /= 3;

		if (r == 0)
		{
			r = 3;
			--n;
		}

		answer.push_back(changeList[r]);
	}

	reverse(answer.begin(), answer.end());
    
    return answer;
}