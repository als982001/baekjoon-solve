#include <iostream>

using namespace std;

void InputNumbers(int* a, int* b)
{
    scanf("%d %d", a, b);
}

string Compare(int a, int b)
{
    return a > b ? "Yes" : "No";
}

int main()
{
    int a, b;
 
    InputNumbers(&a, &b);
    
    while(a > 0 && b > 0)
    {
        cout << Compare(a, b) << endl;
        
        InputNumbers(&a, &b);
    }


    return 0;
}