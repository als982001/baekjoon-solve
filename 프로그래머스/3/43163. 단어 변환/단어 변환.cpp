#include <string>
#include <vector>
#include <map>
#include <queue>

#define INF 987654321

using namespace std;

map<string, int> changeCount;

bool CanChange(string a, string b)
{
    int diffCount = 0;
    
    for (int idx = 0; idx < a.size(); ++idx)
    {
        if (a[idx] != b[idx])
        {
            ++diffCount;
            
            if (diffCount > 1)
                break;
        }
    }
    
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = INF;
    
    changeCount[begin] = 0;
    
    for (string word : words)
        changeCount[word] = INF;
    changeCount[target] = INF;
    
    queue<pair<string, int>> q;
    
    q.push({ begin, 0 });
    
    while(!q.empty())
    {
        string curWord = q.front().first;
        int cutCount = q.front().second;
        q.pop();
        
        if (curWord == target)
        {
            if (answer > cutCount)
                answer = cutCount;
        }
        
        for (string nxtWord : words)
        {
            int nxtCount = cutCount + 1;
            
            if (CanChange(curWord, nxtWord) && changeCount[nxtWord] > nxtCount)
            {
                changeCount[nxtWord] = nxtCount;
                q.push({ nxtWord, nxtCount });
            }
        }
    }
    
    if (answer == INF)
        return 0;
    
    return answer;
}







/*

#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int visited[51];

bool CanChange(string a, string b)
{
    int diffCnt = 0;
    
    for (int idx = 0; idx < a.size(); ++idx)
    {
        if (a[idx] != b[idx])
        {
            diffCnt++;
            
            if (diffCnt > 1)
                break;
        }
    }
    
    return diffCnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = INF;
    
    for (int idx = 0; idx < words.size(); ++idx)
        visited[idx] = INF;
    
    queue<pair<string, int>> q;
    q.push({ begin, 0 });
    
    while(!q.empty())
    {
        string word = q.front().first;
        int t = q.front().second;
        
        q.pop();
        
        if (word == target && answer > t)
        {
            answer = t;
            break;
        }
        
        for (int idx = 0; idx < words.size(); ++idx)
        {
            string nxtWord = words[idx];
            
            if (CanChange(word, nxtWord) && visited[idx] > t + 1)
            {
                visited[idx] = t + 1;
                q.push({ nxtWord, t + 1 });
            }
        }
    }
    
    if (answer == INF)
        return 0;
    
    return answer;
}

*/