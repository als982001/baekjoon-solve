#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int queryIdx = 0; queryIdx < queries.size(); ++queryIdx)
    {
        // query에서 문제의 i, j를 알아낸다.
        int i = queries[queryIdx][0];
        int j = queries[queryIdx][1];
            
        // arr[i]와 arr[j]의 값을 바꾼다.
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    answer = arr;
    
    return answer;
}