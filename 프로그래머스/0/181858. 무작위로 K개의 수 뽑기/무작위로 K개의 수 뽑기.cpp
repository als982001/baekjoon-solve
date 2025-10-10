#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    set<int> checked;
    
    int idx = 0;
    
    while(idx < arr.size() && answer.size() < k)
    {
        int num = arr[idx];
        
        bool isChecked = checked.find(num) != checked.end();
        
        if (isChecked == false)
        {
            checked.insert(num);
            answer.push_back(num);
        }
        
        ++idx;
    }
    
    if (answer.size() < k)
    {
        for (int i = answer.size(); i < k; ++i)
            answer.push_back(-1);
    }
    
    
    
    return answer;
}