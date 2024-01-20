#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); ++i)
    {
        if ('a' <= str[i] && str[i] <= 'z')
            cout << char(str[i] - 'a' + 'A');
        else 
            cout << char(str[i] - 'A' + 'a');
    }
    
    return 0;
}