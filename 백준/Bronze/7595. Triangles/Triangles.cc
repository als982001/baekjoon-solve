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

int n;

int main()
{
    cin >> n;

    while(n != 0)
    {
        for (int star = 1; star <= n; ++star)
        {
            for (int i = 0; i < star; ++i)
                cout << "*";
            cout << endl;
        }

        cin >> n;
    }
   

    return 0;
}