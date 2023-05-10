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

int total = 0;
int val;

int main()
{
    cin >> val;

    while(val != -1)
    {
        total += val;
        cin >> val;
    }

    cout << total << endl;

    return 0;
}
