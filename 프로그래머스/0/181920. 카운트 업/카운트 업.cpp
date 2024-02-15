#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    
    for (int num = start_num; num <= end_num; ++num)
        answer.push_back(num);
    
    return answer;
}