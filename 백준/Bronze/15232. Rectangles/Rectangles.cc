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

int R, C;

int main()
{   
    cin >> R;
    cin >> C;

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
            cout << "*";
        cout << endl;
    }

    return 0;
}