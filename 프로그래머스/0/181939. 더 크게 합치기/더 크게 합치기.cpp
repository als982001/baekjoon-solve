#include <string>
#include <vector>

using namespace std;

int Calc(int a, int b)
{
    string aStr = to_string(a);
    string bStr = to_string(b);
    
    return stoi(aStr + bStr);
}

int solution(int a, int b) {
    int answer = 0;
    
    return max(Calc(a, b), Calc(b, a));
}