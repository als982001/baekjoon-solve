#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int queryIdx = 0; queryIdx < queries.size(); ++queryIdx)
    {
        int s = queries[queryIdx][0];
        int e = queries[queryIdx][1];
        int k = queries[queryIdx][2];
        
        for (int arrIdx = s; arrIdx <= e; ++arrIdx)
        {            
            // 만약 arrIdx가 k의 배수일 경우
            if (arrIdx % k == 0)
                ++arr[arrIdx];  // arr[arrIdx]에 1을 더한다.
        }
    }
    
    answer = arr;
    
    return answer;
}