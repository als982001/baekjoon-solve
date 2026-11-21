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
