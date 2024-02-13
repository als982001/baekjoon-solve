#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    // 모든 원소들의 곱
    int a = 1;
    
    for (int i = 0; i  < num_list.size(); ++i)
        a *= num_list[i];
    
    // 모든 원소들의 합의 제곱
    int b = 0;
    
    for (int i = 0; i < num_list.size(); ++i)
        b += num_list[i];
    b *= b;
    
    if (a < b)
        answer = 1;
    else
        answer = 0;
    
    return answer;
}