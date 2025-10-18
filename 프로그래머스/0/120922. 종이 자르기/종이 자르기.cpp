#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    // 가로 세로가 모두 1이면 자를 필요가 없다.
    if (M == 1 && N == 1)
        return 0;
    
    // 가로가 1이면 세로만 세로 - 1번 자르면 된다.
    if (M == 1)
        return N - 1;
    
    // 세로가 1이면 가로만 가로 - 1번 자르면 된다.
    if (N == 1)
        return M - 1;
    
    return max(max(M - 1, 1) + M * (N - 1), max(N - 1, 1) + N * (M - 1));
}