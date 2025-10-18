#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const vector<int>& a, const vector<int>& b) { // ★ const ref
    if (a[0] != b[0]) return a[0] > b[0];  // x 내림차순
    return a[1] > b[1];                     // x 같으면 y 내림차순
}


int solution(vector<vector<int>> dots) {
    sort(dots.begin(), dots.end(), Compare);
    
    int height = dots[0][1] - dots[1][1];
    int width = dots[0][0] - dots[2][0];
    
    return width * height;
}