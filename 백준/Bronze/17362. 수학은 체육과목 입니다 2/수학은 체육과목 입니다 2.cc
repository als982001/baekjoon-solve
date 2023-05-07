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

long long n;
int r;
int answer;

int main()
{
    cin >> n;

    r = n % 8;
    
    switch(r)
    {
        case 1:
            answer = 1;
            break;
        case 0:
        case 2:
            answer = 2;
            break;
        case 3: 
        case 7:
            answer = 3;
            break;
        case 4:
        case 6:
            answer = 4;
            break;
        case 5:
            answer = 5;
            break;
        default:
            break;
    }

    cout << answer << endl;
	
    return 0;
}
