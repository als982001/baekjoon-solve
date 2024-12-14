#include <iostream>

using namespace std;

void InputNumbers(int* a, int* b)
{
    scanf("%d %d", a, b);
}

string Answer(int a, int b)
{
    return a < b ? "NO BRAINS" : "MMM BRAINS";
}

int main()
{
    int N, a, b;
 
    scanf("%d", &N);
    
    for (int i = 0; i < N; ++i)
    {
        InputNumbers(&a, &b);
        
        cout << Answer(a, b) << endl;
    }


    return 0;
}