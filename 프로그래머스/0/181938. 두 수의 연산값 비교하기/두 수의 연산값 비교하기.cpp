#include <string>
#include <vector>

using namespace std;

int XOR(int a, int b)
{
    string strA = to_string(a);
    string strB = to_string(b);
    
    return stoi(strA + strB);
}

int solution(int a, int b) {
    int answer = 0;
    
    int result1 = XOR(a, b);
    int result2 = 2 * a * b;
    
    answer = max(result1, result2);
    
    return answer;
}