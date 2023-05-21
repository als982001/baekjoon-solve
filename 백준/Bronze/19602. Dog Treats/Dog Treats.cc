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

int Calculate(int S, int M, int L)
{
    return 1 * S + 2 * M + 3 * L;
}

int main()
{
    int S, M, L;
    
    cin >> S;
    cin >> M;
    cin >> L;

    int answer = Calculate(S, M, L);

    if (answer >= 10) 
        cout << "happy" << endl;
    else
        cout << "sad" << endl;
 
    return 0;
}