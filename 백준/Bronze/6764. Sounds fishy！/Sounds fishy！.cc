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

int depth[4];

bool Rising()
{
    return (depth[0] < depth[1]) && (depth[1] < depth[2]) && (depth[2] < depth[3]);
}

bool Diving()
{
    return (depth[0] > depth[1]) && (depth[1] > depth[2]) && (depth[2] > depth[3]);
}

bool Constant()
{
    return (depth[0] == depth[1]) && (depth[1] == depth[2]) && (depth[2] == depth[3]);
}

int main()
{
    for (int i = 0; i < 4; ++i)
        cin >> depth[i];

    if (Rising())
        cout << "Fish Rising" << endl;
    else if (Diving())
        cout << "Fish Diving" << endl;
    else if (Constant())
        cout << "Fish At Constant Depth" << endl;
    else
        cout << "No Fish" << endl;
 
    return 0;
}