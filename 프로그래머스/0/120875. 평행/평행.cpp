#include <string>
#include <vector>

using namespace std;

static bool parallel(const vector<int>& A, const vector<int>& B,
                     const vector<int>& C, const vector<int>& D) 
{
    long dx1 = B[0] - A[0];
    long dy1 = B[1] - A[1];
    long dx2 = D[0] - C[0];
    long dy2 = D[1] - C[1];
    return dy1 * dx2 == dy2 * dx1;  // 교차곱으로 기울기 비교
}

int solution(vector<vector<int>> dots) {
    return (parallel(dots[0], dots[1], dots[2], dots[3]) ||
            parallel(dots[0], dots[2], dots[1], dots[3]) ||
            parallel(dots[0], dots[3], dots[1], dots[2])) ? 1 : 0;
}