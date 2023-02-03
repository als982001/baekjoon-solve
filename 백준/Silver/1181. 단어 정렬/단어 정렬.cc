#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define CASE 3
#define MAX 20001

int N;
string word;
map<string, bool> existent;
vector<string> words;

bool Compare(string a, string b)
{
	if (a.size() < b.size())
		return true;
	else if (a.size() > b.size())
		return false;
	else
	{
		if (a < b)
			return true;
		else
			return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
	cin >> N;

	for (int n = 0; n < N; ++n)
	{
		cin >> word;

		if (existent[word] == false)
		{
			existent[word] = true;
			words.push_back(word);
		}
	}

	sort(words.begin(), words.end(), Compare);
	
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << endl;

	return 0;
}