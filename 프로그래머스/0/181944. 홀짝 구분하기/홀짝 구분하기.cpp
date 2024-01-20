#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    if (n % 2 == 0)
        printf("%d is even\n", n);
    else
        printf("%d is odd\n", n);
    
    return 0;
}