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

int digits[4];

bool IsTelemarketer()
{
    if ((digits[0] == 8 || digits[0] == 9) == false)
        return false;

    if (digits[1] != digits[2])
        return false;

    if ((digits[3] == 8 || digits[3] == 9) == false)
        return false;

    return true;
}

int main()
{   
    for (int i = 0; i < 4; ++i)
        cin >> digits[i];

    bool isTelemarketer = IsTelemarketer();

    cout << (isTelemarketer ? "ignore" : "answer") << endl;
    
    return 0;
}