#include <iostream>
#include<cmath>

using namespace std;

int answer = 0;
string hexadecimal;

int HexaToDec(char item) 
{
    switch(item)
    {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            return item - 'A' + 10;
        default:
            return max(item - '0', 0);
    }
}

int Change(char item, int order)
{
    int num = HexaToDec(item);
    
    return num * pow(16, order);
}

int main()
{
    
    cin >> hexadecimal;
    
    for (int i = hexadecimal.size() - 1, order = 0; i >= 0; --i, ++order)
    {
        int num = Change(hexadecimal[i], order);
        answer += num;
    }
    
    printf("%d\n", answer);

    return 0;
}