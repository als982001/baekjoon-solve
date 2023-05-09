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

int age[2];
int answer;

int main()
{
    cin >> age[0];
    cin >> age[1];

    answer = age[1] + (age[1] - age[0]);

    cout << answer << endl;

    return 0;
}
