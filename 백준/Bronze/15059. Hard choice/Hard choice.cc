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

int answer = 0;
int required[3];
int retained[3];

int main()
{   
    for (int i = 0; i < 3; ++i)
        cin >> retained[i];

    for (int i = 0; i < 3; ++i)
        cin >> required[i];



    for (int i = 0; i < 3; ++i)
    {
        int insufficient = required[i] - retained[i] > 0 ? required[i] - retained[i] : 0;
        answer += insufficient;
    }
    
    cout << answer << endl;


    return 0;
}