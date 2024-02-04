#include <iostream>
#include <vector>
#define MAX 12

using namespace std;

int T, n;
int dp[MAX];
vector<int> answer;

int Check(int num)
{
    if (dp[num] > -1)
        return dp[num];

    return dp[num] = Check(num - 1) + Check(num - 2) + Check(num - 3);
}

int main()
{
    ios_base::sync_with_stdio(0);
	std::cout.tie(NULL);    
	std::cin.tie(NULL);
    
    for (int i = 0; i < MAX; ++i)
        dp[i] = -1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin >> T;

    while(T--)
    {
        cin >> n;

        int result = Check(n);

        answer.push_back(result);
    }

    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;
  

    return 0;
}       