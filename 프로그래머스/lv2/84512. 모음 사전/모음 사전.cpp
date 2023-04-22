#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;

	int mult[5] = { 781, 156, 31, 6, 1 };

	map<char, int> orders;
	orders['A'] = 0;
	orders['E'] = 1;
	orders['I'] = 2;
	orders['O'] = 3;
	orders['U'] = 4;

	int idx = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		answer += (1 + orders[word[i]] * mult[idx]);
		++idx;
	}

	return answer;
}