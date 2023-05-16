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

#define TroyMartian "TroyMartian"
#define VladSaturnian "VladSaturnian"
#define GraemeMercurian "GraemeMercurian"

using namespace std;

int antenna;
int eyes;
vector<string> answer;

bool CheckTroyMartian()
{
    return antenna >= 3 && eyes <= 4;
}

bool CheckVladSaturnian()
{
    return antenna <= 6 && eyes >= 2;
}

bool CheckGraemeMercurian() 
{
    return antenna <= 2 && eyes <= 3;
}

int main()
{
    cin >> antenna;
    cin >> eyes;

    if (CheckTroyMartian())
        cout << TroyMartian << endl;
    
    if (CheckVladSaturnian())
        cout << VladSaturnian << endl;

    if (CheckGraemeMercurian())
        cout << GraemeMercurian << endl;

    return 0;
}