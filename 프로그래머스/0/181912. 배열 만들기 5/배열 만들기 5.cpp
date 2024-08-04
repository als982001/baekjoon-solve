#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (int i = 0; i < intStrs.size(); ++i)
    {
        string intStr = intStrs[i];
        
        string slicedIntStr = intStr.substr(s, l);
        int currentNum = stoi(slicedIntStr);
        
        if (currentNum > k) 
        {
            answer.push_back(currentNum);
        }
    }
    
    return answer;
}