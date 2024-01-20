#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    
    if (a[0] > b[0])
        return false;
    
    if (a[1] < b[1])
        return true;
    else
        return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), Compare);
    
    int startPos = 0;
    int endPos = 0;
    
    for (int i = 0; i < targets.size(); ++i)
    {
        int targetStartPos = targets[i][0];
        int targetEndPos = targets[i][1];
        
        if (endPos <= targetStartPos)
        {
            ++answer;
            
            startPos = targetStartPos;
            endPos = targetEndPos;
        }
        else if (targetStartPos < endPos)
        {
            startPos = targetStartPos;
            
            if (targetEndPos < endPos)
                endPos = targetEndPos;
        }
    }
    
    
    
    
    return answer;
}