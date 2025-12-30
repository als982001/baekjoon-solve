#include <string>
#include <vector>
#include <map>
#include <queue>

#define MAX 51

using namespace std;

int checked[MAX];

bool CanChange(string from, string to)
{
    bool hasDiffLetter = false;
    bool canChange = true;
    
    if (from == to)
        return false;
        
    for (int i = 0; i < to.size(); ++i)
    {
        char fromLetter = from[i];
        int toLetter = to[i];
        
        if (fromLetter != toLetter)
        {
            if (hasDiffLetter)
            {
                canChange = false;
                break;
            }

            hasDiffLetter = true;
        }
    }
    
    return canChange;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    for (int i = 0; i < MAX; ++i)
        checked[i] = MAX * MAX;
    
    queue<pair<string, int>> q;
    
    q.push({ begin, 0 });
    
    while(!q.empty())
    {
        string curWord = q.front().first;
        int times = q.front().second;
        
        q.pop();
        
        int nxtTimes = times + 1;
        
        if (curWord == target)
        {
            answer = times;
            break;
        }
        
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            
            if (CanChange(curWord, word) && checked[i] > nxtTimes)
            {
                checked[i] = nxtTimes;
                q.push({ word, nxtTimes });
            }
        }
    }
    
    
    return answer;
}

















/*

#include <string>
#include <vector>
#include <queue>
#define MAX 12
using namespace std;

bool checked[MAX];


bool CanChange(string from, string to)
{
    int diffNum = 1;
    
    for (int i = 0; i < from.size(); ++i)
    {
        if (from[i] != to[i])
        {
            if (--diffNum < 0)
                return false;
        }
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    queue<pair<string, int>> q;
    q.push({ begin, 0 });
    
    while(!q.empty())
    {
        string curWord = q.front().first;
        int changeTime = q.front().second;
        q.pop();
        
        if (curWord == target)
        {
            answer = changeTime;
            break;
        }
        
        for (int i = 0; i < words.size(); ++i)
        {
            string nxtWord = words[i];
            
            if (checked[i] == false && CanChange(curWord, nxtWord) == true)
            {
                checked[i] = true;
                q.push({ nxtWord, changeTime + 1 });
            }
        }
    }
    
    return answer;
}

*/