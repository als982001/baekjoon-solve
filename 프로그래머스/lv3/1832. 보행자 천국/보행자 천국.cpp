#include <vector>
#define MAX 501
#define REC 1
#define DOWN 0
#define RIGHT 1
using namespace std;

int MOD = 20170805;
int record[MAX][MAX][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int R = m;
    int C = n;
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
        {
            record[r][c][DOWN] = 0;
            record[r][c][RIGHT] = 0;
        }
    }
    
    record[0 + REC][0 + REC][DOWN] = 1;
    record[0 + REC][0 + REC][RIGHT] = 1;
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (r == 0 && c == 0)
                continue;
            
            // city_map[r][c] == 1일 경우, 문제의 조건에 의해 가지 못한다.
            
            if (city_map[r][c] == 0)
            {
                record[r + REC][c + REC][DOWN] = (record[r + REC - 1][c + REC][DOWN] + record[r + REC][c + REC - 1][RIGHT]) % MOD;
                record[r + REC][c + REC][RIGHT] = (record[r + REC - 1][c + REC][DOWN] + record[r + REC][c + REC - 1][RIGHT]) % MOD;
            }
            else if (city_map[r][c] == 2)
            {
                record[r + REC][c + REC][DOWN] = record[r + REC - 1][c + REC][DOWN];
                record[r + REC][c + REC][RIGHT] = record[r + REC][c + REC - 1][RIGHT];
            }
        }
    }
    
    return record[R][C][DOWN];
}