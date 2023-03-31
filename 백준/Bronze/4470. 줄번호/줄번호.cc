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

#define TOLOWER 32

int N;
string sentence;
vector<string> sentences;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		getline(cin, sentence);
		sentences.push_back(sentence);
	}	
	
	for (int i = 0; i < sentences.size(); ++i)
		cout << i + 1 << ". " << sentences[i] << endl;

    return 0;
}
