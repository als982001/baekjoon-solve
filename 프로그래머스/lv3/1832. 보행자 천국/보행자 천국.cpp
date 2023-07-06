#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define MAX 555
#define MOD 20170805

int check[MAX][MAX][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int R = m;
	int C = n;

	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			check[r][c][0] = 0;
			check[r][c][1] = 0;
		}
	}
	
	check[1][1][0] = 1;
	check[1][1][1] = 1;

	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; ++c)
		{
			int checkR = r + 1;
			int checkC = c + 1;

			if (city_map[r][c] == 0)
			{
				check[checkR][checkC][0] += ((check[checkR - 1][checkC][0] + check[checkR][checkC - 1][1]) % MOD);
				check[checkR][checkC][1] += ((check[checkR - 1][checkC][0] + check[checkR][checkC - 1][1]) % MOD);
			}
			else if (city_map[r][c] == 1)
			{
				check[checkR][checkC][0] = 0;
				check[checkR][checkC][1] = 0;
			}
			else if (city_map[r][c] == 2)
			{
				check[checkR][checkC][0] = (check[checkR - 1][checkC][0] % MOD);
				check[checkR][checkC][1] = (check[checkR][checkC - 1][1] % MOD);
			}
		}
	}

	return check[R][C][0] % MOD;
}
