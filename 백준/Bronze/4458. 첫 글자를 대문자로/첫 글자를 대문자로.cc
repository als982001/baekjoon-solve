#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;

int N;
vector<string> sentences;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int n = 0; n < N; ++n)
	{
		string sentence;
		getline(cin, sentence);

		sentence[0] = toupper(sentence[0]);
		
		sentences.push_back(sentence);
	}

	for (auto sentence : sentences)
		cout << sentence << endl;
	
    return 0;
}
