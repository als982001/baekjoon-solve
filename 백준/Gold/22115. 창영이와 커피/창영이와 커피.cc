#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321
#define MAX 100001

int N, K;
int caffeines[101];
int dp[MAX];

void Init() {
    fill(dp, dp + MAX, INF);
    dp[0] = 0; // 카페인 필요량이 0이면 커피를 마실 필요 없음
}

int main() {
    scanf("%d %d", &N, &K);

    for (int n = 1; n <= N; ++n) {
        scanf("%d", &caffeines[n]);
    }

    Init();

    for (int i = 1; i <= N; ++i) {
        for (int j = K; j >= caffeines[i]; --j) {
            dp[j] = min(dp[j], dp[j - caffeines[i]] + 1);
        }
    }

    int answer = dp[K] == INF ? -1 : dp[K];
    printf("%d\n", answer);

    return 0;
}
