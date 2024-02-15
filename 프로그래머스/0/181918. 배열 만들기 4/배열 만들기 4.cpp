#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    int i = 0;
    
    while(i < arr.size())
    {   
        // 만약 stk가 빈 배열일 경우, arr[i]를 stk에 추가하고 i에 1을 더한다.
        if (stk.size() == 0)
            stk.push_back(arr[i++]);
        else
        {   
            // 만약 stk의 마지막 원소가 arr[i]보다 작을 경우, 
            // arr[i]를 stk의 뒤에 추가하고 i에 1을 더한다.
            if (stk.back() < arr[i])
                stk.push_back(arr[i++]);
            
            // 그렇지 않을 경우, stk의 마지막 원소를 stk에서 제거한다.
            else
                stk.pop_back();
        }
    }
    
    return stk;
}