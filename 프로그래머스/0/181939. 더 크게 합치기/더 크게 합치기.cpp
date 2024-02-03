#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
        
    string strA = to_string(a);
    string strB = to_string(b);
    
    int num1 = stoi(strA + strB);
    int num2 = stoi(strB + strA);
    
    if (num1 > num2)
        answer = num1;
    else
        answer = num2;
    
    return answer;
}