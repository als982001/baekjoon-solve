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

int limit;
int speed;

int main()
{
    cin >> limit;
    cin >> speed;

    int diff = speed - limit;
    
    if (diff >= 31)
        cout << "You are speeding and your fine is $500." << endl;
    else if (diff >= 21)
        cout << "You are speeding and your fine is $270." << endl;
    else if (diff >= 1)
        cout << "You are speeding and your fine is $100." << endl;
    else
        cout << "Congratulations, you are within the speed limit!" << endl;

   
    return 0;
}