#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int a, int b) {    
    int 최대공약수 = gcd(a, b);
    
    b /= 최대공약수;
    
    while(b % 2 == 0)
        b /= 2;
    while(b % 5 == 0)
        b /= 5;
    
    return (b == 1) ? 1 : 2;
}