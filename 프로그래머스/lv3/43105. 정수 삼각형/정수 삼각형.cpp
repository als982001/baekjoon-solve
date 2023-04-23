#include <string>
#include <vector>

using namespace std;

#define MAX 501

int dp[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for (int a = 0; a < MAX; ++a)
    {
        for (int b = 0; b < MAX; ++b)
            dp[a][b] = -1;
    }
    
    dp[0][0] = triangle[0][0];
    
    for (int row = 1; row < triangle.size(); ++row)
    {
        dp[row][0] = triangle[row][0] + dp[row - 1][0];
        dp[row][row] = triangle[row][row] + dp[row - 1][row - 1];
        
        for (int col = 1; col < row; ++col)
            dp[row][col] = triangle[row][col] + max(dp[row - 1][col - 1], dp[row - 1][col]);
    }
    
    for (int col = 0; col < triangle.size(); ++col)
        answer = max(answer, dp[triangle.size() - 1][col]);
    
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

#define MAX 501			// 높이의 최댓값이 500이므로 MAX를 501로 설정(0 ~ 500)

int maxR, maxC;			// maxR: 삼각형의 높이, maxC: 삼각형의 밑변의 길이
int check[MAX][MAX];	// dynamic programming의 기록을 위한 배열
vector<vector<int>> t;	// 주어진 triangle을 전역변수로 이용하기 위함

// dynamic programming을 위한 배열 초기화
void Reset_Check() {

    for (int r = 0; r <= maxR; ++r) {

        for (int c = 0; c < t[r].size(); ++c) {

            check[r][c] = -1;
        }
    }
}

int Bigger(int a, int b) {

    if (a > b)
        return a;
    else
        return b;
}

int Find_Max_Val(int r, int c) {

	// 예외 1. 만약 현재 높이가 삼각형의 범위를 벗어나는 경우
    if (r > maxR || r < 0)
        return 0;

	// 예외 2. 삼각형의 가로 위치가 삼각형의 범위를 벗어나는 경우
    if (c > r || c < 0)
        return 0;

	// 이미 검사한 지점인 경우, 검사한 값을 반환
    if (check[r][c] >= 0)
        return check[r][c];

    check[r][c] = t[r][c];

	
    if (c == 0)			// 만약 현재 삼각형의 가장 왼쪽이라면, 바로 윗 칸으로 갈 수 밖에 없다.
        check[r][c] = check[r][c] + Find_Max_Val(r - 1, c);
    else if (c == r)	// 만약 현재 삼각형의 가장 오른쪽이라면, 바로 윗 칸으로 갈 수 밖에 없다.
        check[r][c] = check[r][c] + Find_Max_Val(r - 1, r - 1);
    else				// 그 외의 경우에는 왼쪽 위, 오른족 위로 갈 수 있다.
        check[r][c] = check[r][c] + Bigger(Find_Max_Val(r - 1, c - 1), Find_Max_Val(r - 1, c));

    return check[r][c];
}

int solution(vector<vector<int>> triangle) {
    int answer = -1;

	// 본격적인 계산을 하기 전, 필요한 것들을 세팅한다.
    t = triangle;

    maxR = triangle.size() - 1;
    maxC = triangle[maxR].size() - 1;

    Reset_Check();

    check[0][0] = triangle[0][0];	
    for (int c = 0; c <= maxC; ++c) 
        answer = Bigger(answer, Find_Max_Val(maxR, c));

    return answer;
}
*/
