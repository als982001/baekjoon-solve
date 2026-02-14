#include <string>
#include <vector>
#include <set>

#define MAX 100001
#define MOD 10007

using namespace std;

int lastIdx = -1;
int 가로로_긴_마름모로_끝남[MAX]; // 가로로 긴 마름모로 끝나는 케이스
int 그_외_케이스[MAX * 2]; // 그 외 케이스 전부
set<int> hasTop;

bool HasTop(int idx)
{
    return hasTop.find(idx) != hasTop.end();
}

int solution(int n, vector<int> tops) {    
    for (int i = 0; i < tops.size(); ++i)
    {
        if (tops[i] == 1)
            hasTop.insert((i * 2) + 1);
    }
    
    lastIdx = 2 * n;
    
    for (int idx = 0; idx < MAX; ++idx)
    {
        가로로_긴_마름모로_끝남[idx] = 0;
        그_외_케이스[idx] = 0;
    }

    가로로_긴_마름모로_끝남[0] = 0; // 첫 번째 거는 가로로 긴 마름모 불가능
    그_외_케이스[0] = 1;

    가로로_긴_마름모로_끝남[1] = HasTop(1) ? 1 : 1;
    그_외_케이스[1] = HasTop(1) ? 2 : 1;

    가로로_긴_마름모로_끝남[2] = 1;
    그_외_케이스[2] = 가로로_긴_마름모로_끝남[1] + 그_외_케이스[1];

    가로로_긴_마름모로_끝남[3] = 가로로_긴_마름모로_끝남[1] + 그_외_케이스[1];
    그_외_케이스[3] = (가로로_긴_마름모로_끝남[2] + 그_외_케이스[2]) * (HasTop(3) ? 2 : 1);

    가로로_긴_마름모로_끝남[4] = 가로로_긴_마름모로_끝남[2] + 그_외_케이스[2];
    그_외_케이스[4] = 가로로_긴_마름모로_끝남[3] + 그_외_케이스[3];

    for (int idx = 5; idx <= lastIdx; ++idx)
    {
        if (idx % 2 == 1)
        {
            가로로_긴_마름모로_끝남[idx] = (가로로_긴_마름모로_끝남[idx - 2] + 그_외_케이스[idx - 2]) % MOD;
            그_외_케이스[idx] = ((가로로_긴_마름모로_끝남[idx - 1] + 그_외_케이스[idx - 1]) * (HasTop(idx) ? 2 : 1)) % MOD;
        }
        else
        {
            가로로_긴_마름모로_끝남[idx] = (가로로_긴_마름모로_끝남[idx - 2] + 그_외_케이스[idx - 2]) % MOD;
            그_외_케이스[idx] = (가로로_긴_마름모로_끝남[idx - 1] + 그_외_케이스[idx - 1]) % MOD;
        }
        
        가로로_긴_마름모로_끝남[idx] %= MOD;
        그_외_케이스[idx] %= MOD;
    }

    return (가로로_긴_마름모로_끝남[lastIdx] + 그_외_케이스[lastIdx]) % MOD;

}

