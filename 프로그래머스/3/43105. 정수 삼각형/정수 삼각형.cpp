#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    // 삼각형의 높이
    int height = triangle.size();

    // 맨 아래층 바로 윗줄부터 시작해서, 꼭대기(0번째 줄)까지 올라감
    // height - 1은 맨 아랫줄이므로, height - 2부터 시작
    for (int h = height - 2; h >= 0; h--) 
    {
        for (int j = 0; j < triangle[h].size(); j++) 
        {
            // 내 위치(h, j)의 값 = 원래 값 + max(왼쪽 아래, 오른쪽 아래)
            triangle[h][j] += max(triangle[h + 1][j], triangle[h + 1][j+1]);
        }
    }

    // 꼭대기에 모든 계산 결과가 누적됨
    return triangle[0][0];
}