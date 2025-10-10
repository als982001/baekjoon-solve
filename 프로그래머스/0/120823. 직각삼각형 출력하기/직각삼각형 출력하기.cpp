#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for (int len = 1; len <= n; ++len)
    {
        string row = "";
        
        for (int c = 0; c < len; ++c)
            row += '*';
        
        cout << row << endl;
    }
    
    return 0;
}