#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool Compare(pair<int, int> a, pair<int, int> b)
{
    int diffA = abs(a.first - N);
    int diffB = abs(b.first - N);
    
    if (diffA < diffB)
        return true;
    else if (diffA > diffB)
        return false;
    else
    {
        return a.first > b.first;
    }
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    N = n;
    
    vector<pair<int, int>> numInfos;
    
    for (int i = 0; i < numlist.size(); ++i)
    {
        numInfos.push_back({ numlist[i], i });
    }
    
    sort(numInfos.begin(), numInfos.end(), Compare);
    
    for (int i = 0; i < numInfos.size(); ++i)
    {
        int idx = numInfos[i].second;
        answer.push_back(numlist[idx]);
    }
    
    return answer;
}