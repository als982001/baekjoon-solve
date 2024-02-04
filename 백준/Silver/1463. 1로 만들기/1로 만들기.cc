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
#include <unordered_set>
#include <set>
#pragma warning(disable:4996)
#define MAX 1000001

using namespace std;

int X;
int dp[MAX];

int Check(int num)
{
    if (num == 1)
        return 1;

    if (dp[num] > 0)
        return dp[num];

    int result = MAX + MAX;

    if (num % 3 == 0)
        result = min(result, Check(num / 3));

    if (num % 2 == 0)
        result = min(result, Check(num / 2));
    
    result = min(result, Check(num - 1));

    return dp[num] = result + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
	std::cout.tie(NULL);    
	std::cin.tie(NULL);

    for (int i = 0; i < MAX; ++i)
        dp[i] = -1;

    cin >> X;

    int answer = Check(X);    

    cout << answer - 1 << endl;

    return 0;
}