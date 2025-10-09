#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); ++i)
        answer.push_back(arr[i]);

    for (int i = 0; i < queries.size(); ++i) {
        int startIdx = queries[i][0];
        int endIdx   = queries[i][1];

        
        for (int k = startIdx; k <= endIdx; ++k)
            answer[k] = answer[k] + 1;
    }
    
    return answer;
}