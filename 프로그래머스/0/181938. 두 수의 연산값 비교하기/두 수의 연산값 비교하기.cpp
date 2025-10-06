#include <string>
#include <vector>

using namespace std;

int Calc01 (int a, int b)
{
    string numStr = to_string(a) + to_string(b);
    
    return stoi(numStr);
}

int Calc02 (int a, int b)
{
    return 2 * a * b;
}

int solution(int a, int b) {
    int answer = 0;
    
    answer = max(Calc01(a, b), Calc02(a, b));
    
    return answer;
}