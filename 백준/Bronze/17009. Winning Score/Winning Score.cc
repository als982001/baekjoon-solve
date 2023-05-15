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

int shot;
int appleScore = 0;
int bananaScore = 0;

int main()
{
    for (int point = 3; point >= 1; --point)
    {
        cin >> shot;
        appleScore += shot * point;
    }

    for (int point = 3; point >= 1; --point)
    {
        cin >> shot;
        bananaScore += shot * point;
    }

    if (appleScore > bananaScore)
        cout << "A" << endl;
    else if (appleScore == bananaScore)
        cout << "T" << endl;
    else
        cout << "B" << endl;

    return 0;
}