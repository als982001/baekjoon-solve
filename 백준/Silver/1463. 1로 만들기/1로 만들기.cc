#include <iostream>
#define MAX 1000001

using namespace std;

int X;
int dp[MAX];

int Check(int num)
{
    if (num == 1)
        return 0;

    if (dp[num] > 0)
        return dp[num];

    int result = MAX + MAX;

    if (num % 3 == 0)
        result = min(result, Check(num / 3) + 1);

    if (num % 2 == 0)
        result = min(result, Check(num / 2) + 1);
    
    result = min(result, Check(num - 1) + 1);

    return dp[num] = result;
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

    cout << answer << endl;

    return 0;
}