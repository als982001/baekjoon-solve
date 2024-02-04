#include <iostream>

using namespace std;

int N;
pair<long long, long long> dp[1000000];

pair<long long, long long> Check(int num)
{
    if (dp[num].first != -1)
        return dp[num];

    pair<long long, long long> befRec = Check(num - 1);

    return dp[num] = { befRec.first + befRec.second, befRec.first };
}

int main()
{
    ios_base::sync_with_stdio(0);
	std::cout.tie(NULL);    
	std::cin.tie(NULL);

    for (int i = 1; i <= 1000000; ++i)  
        dp[i] = { -1, -1 };

    dp[1] = { 1, 1 };
    dp[2] = { 2, 1 };

    cin >> N;

    pair<long long, long long> rectangle = Check(N);

    long long answer =  (rectangle.first + rectangle.second) * 2;

    cout << answer << endl;

    return 0;
}