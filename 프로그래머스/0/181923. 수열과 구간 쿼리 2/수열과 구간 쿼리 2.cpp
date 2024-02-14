#include <string>
#include <vector>
#define INF 987654321

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int i = 0; i < queries.size(); ++i)
    {
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2];
        
        int targetNum = INF;
        
        for (int arrIdx = s; arrIdx <= e; ++arrIdx)
        {
            int num = arr[arrIdx];
            
            if (num > k && targetNum > num)
                targetNum = num;
        }
        
        if (targetNum == INF)
            answer.push_back(-1);
        else
            answer.push_back(targetNum);
    }
    
    return answer;
}