#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    bool 등차수열 = common[2] - common[1] == common[1] - common[0];
    
    if (등차수열)
    {
        int val = common[1] - common[0];
        answer = common.back() + val;
    }
    else
    {
        int val = common[1] / common[0];
        answer = common.back() * val;
    }
    
    return answer;
}