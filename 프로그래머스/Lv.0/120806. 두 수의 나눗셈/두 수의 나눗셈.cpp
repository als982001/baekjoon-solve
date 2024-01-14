#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    double n1 = (double)num1;
    double n2 = (double)num2;
    
    return (n1 / n2) * 1000;
}