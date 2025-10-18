#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

vector<int> solution(vector<vector<int>> score) {
    int n = (int)score.size();
    vector<pair<int,int>> sortedInfo;
    sortedInfo.reserve(n);

    for (int i = 0; i < n; ++i) {
        int sum = score[i][0] + score[i][1];
        sortedInfo.push_back({sum, i});
    }

    sort(sortedInfo.begin(), sortedInfo.end(), Compare);

    vector<int> answer(n);
    int rank = 1;
    answer[sortedInfo[0].second] = rank;

    for (int i = 1; i < n; ++i) {
        if (sortedInfo[i].first == sortedInfo[i-1].first) {
            answer[sortedInfo[i].second] = rank;   // 동점 → 같은 등수
        } else {
            rank = i + 1;                          // 경쟁 랭킹: i+1로 점프
            answer[sortedInfo[i].second] = rank;
        }
    }
    return answer;
}