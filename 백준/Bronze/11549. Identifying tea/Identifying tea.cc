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
int T;
int n;

int main()
{
    cin >> T;

    for (int i = 0; i < 5; ++i)
    {
        cin >> n;

        if (n == T)
            ++answer;
    }

    cout << answer << endl;

    return 0;
}