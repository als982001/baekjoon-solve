#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;

char result;
int score = 0;
int answer;

int main()
{
    for (int i = 0; i < 6; ++i)
    {
        cin >> result;

        if (result == 'W')
            ++score;
    }

    switch(score)
    {
        case 6:
        case 5:
            answer = 1;
            break;
        case 4:
        case 3:
            answer = 2;
            break;
        case 2:
        case 1:
            answer = 3;
            break;
        default:
            answer = -1;
    }

    cout << answer << endl;

 
    return 0;
}