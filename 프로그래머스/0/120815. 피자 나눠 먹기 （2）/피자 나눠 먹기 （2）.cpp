#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int n) {    
    return n / gcd(n, 6);
}