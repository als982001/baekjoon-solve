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

int leftNum, rightNum;

int main()
{
    cin >> leftNum >> rightNum;

    if (leftNum == 0 && rightNum == 0)
        cout << "Not a moose" << endl;
    else if( leftNum == rightNum)
        cout << "Even " << 2 * leftNum << endl;
    else
        cout << "Odd " << 2 * max(leftNum, rightNum) << endl;

    return 0;
}