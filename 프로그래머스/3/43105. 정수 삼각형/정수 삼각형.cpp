#include <string>
#include <vector>

using namespace std;

int len;
int record[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    len = triangle.size();
    
    if (triangle.size() == 1)
        return triangle[0][0];
    
    if (triangle.size() == 2)
        return max(triangle[1][0], triangle[1][1]) + triangle[0][0];

    for (int row = 0; row < triangle.size(); ++row)
    {
        for (int col = 0; col < triangle[row].size(); ++col)
        {
            record[row][col] = -1;
        }
    }
    
    record[0][0] = triangle[0][0];
    
    if (triangle.size() > 1)
    {
        record[1][0] = triangle[1][0] + triangle[0][0];
        record[1][1] = triangle[1][1] + triangle[0][0];
    }
    
    for (int row = 1; row < len; ++row)
    {
        for (int col = 0; col < triangle[row].size(); ++col)
        {
            if (col == 0)
                record[row][col] = record[row - 1][col] + triangle[row][col];
            else if (col == triangle[row].size() - 1)
                record[row][col] = record[row - 1][col - 1] + triangle[row][col];
            else
                record[row][col] = max(record[row - 1][col - 1], record[row - 1][col]) + triangle[row][col];
        }
    }
    
    for (int col = 0; col < len; ++col)
    {
        answer = max(record[len - 1][col], answer);
    }
    
    return answer;
}















/*


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


*/