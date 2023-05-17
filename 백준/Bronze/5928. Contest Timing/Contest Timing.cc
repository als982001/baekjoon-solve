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

#define HOUR 60
#define DAY 1440
#define CRI 16511

using namespace std;

int day, hour, minute, sum = 0;


int main()
{
    cin >> day;
    cin >> hour;
    cin >> minute;

    sum += minute;
    sum += (hour * HOUR);
    sum += (day * DAY);

    cout << (sum - CRI >= 0 ? sum - CRI : -1) << endl;

    return 0;
}