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

int P, S;

int main()
{
    cin >> S;

    P = (5 * S) - 400;

    cout << P << endl;

    if (P > 100)
        cout << -1 << endl;
    else if (P == 100)
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}