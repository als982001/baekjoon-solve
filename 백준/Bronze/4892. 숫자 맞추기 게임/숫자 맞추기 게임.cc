#include <iostream>

using namespace std;

void PrintAnswer(int index, int n1, int n4)
{
    if (n1 % 2 == 0)
        printf("%d. even %d \n", index, n4);
    else
        printf("%d. odd %d \n", index, n4);
}

int GetN4 (int n1)
{
    int n2, n3, n4;

    if (n1 % 2 == 0)
    {
        // n1이 짝수라면 n2 = n1 / 2
        n2 = n1 / 2;    
    }
    else
    {
        // n1이 홀수라면 n2 = (n1 + 1) / 2
        n2 = (n1 + 1) / 2;  
    }
    
    n3 = 3 * n2;
    
    n4 = n3 / 9;
    
    return n4;
}

int main()
{
    int n0;
    
    scanf("%d", &n0);
    
    for (int i = 1; n0 > 0; ++i)
    {
        int n1 = n0 * 3;
        int n4 = GetN4(n1);
        
        PrintAnswer(i, n1, n4);
        
        scanf("%d", &n0);
    }

    return 0;
}