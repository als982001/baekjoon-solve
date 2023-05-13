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

string line;

int main()
{
    getline(cin, line);

    istringstream info(line);

    string strNum1, optr, strNum2, equal, strSum;
    
    info >> strNum1 >> optr >> strNum2 >> equal >> strSum;

    int num1 = stoi(strNum1);
    int num2 = stoi(strNum2);
    int sum = stoi(strSum);

    if (num1 + num2 == sum)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}