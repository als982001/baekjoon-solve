#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    
    string numStr = to_string(num);
    
    answer = numStr.find(to_string(k));
    
    if (answer == -1)
        return -1;
    
    return answer + 1;
}