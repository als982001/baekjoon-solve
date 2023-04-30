#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool CanChange(string from, string to)
{
    bool changed = false;
    
    for (int i = 0; i < from.size(); ++i)
    {
        if (from[i] != to[i])
        {
            if (changed == true)
                return false;
            changed = true;
        }
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {

    map<string, bool> check;
    queue<pair<string, int>> q;
    
    q.push({ begin, 0 });
    check[begin] = true;
    
    while(!q.empty())
    {
        string curWord = q.front().first;
        int curTime = q.front().second;
        q.pop();
        
        if (curWord == target)
            return curTime;
        
        for (int i = 0; i < words.size(); ++i)
        {
            string nxtWord = words[i];
            
            if (check[nxtWord] == true || curWord == nxtWord)
                continue;
            
            if (CanChange(curWord, nxtWord))
            {
                check[nxtWord] = true;
                q.push({ nxtWord, curTime + 1 });
            }
        }
    }
    
    return 0;
}

/*
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool CanChange(string wordA, string wordB)
{
	int differentAlpNum = 0;

	for (int i = 0; i < wordA.size(); ++i)
	{
		if (wordA[i] != wordB[i])
		{
			++differentAlpNum;

			if (differentAlpNum > 1)
				return false;
		}
	}

	return true;
}

int solution(string begin, string target, vector<string> words)
{
	map<string, bool> checked;

	queue<pair<string, int>> q;
	q.push({ begin, 0 });
	checked[begin] = true;	

	while(!q.empty())
	{
		string curWord = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if (curWord == target)
			return curTime;

		for (int i = 0; i < words.size(); ++i)
		{
			string nxtWord = words[i];

			if (checked[nxtWord] == true)
				continue;

			if (CanChange(curWord, nxtWord))
			{
				checked[nxtWord] = true;
				q.push({ nxtWord, curTime + 1 });
			}
		}
	}

	return 0;
}
*/