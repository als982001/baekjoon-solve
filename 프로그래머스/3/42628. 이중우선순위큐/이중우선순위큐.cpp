#include <string>
#include <vector>
#include <set> // multiset 헤더
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    // 오름차순 자동 정렬되는 중복 허용 집합
    multiset<int> ms; 

    for (string op : operations) {
        char cmd = op[0];
        int num = stoi(op.substr(2));

        if (cmd == 'I') {
            ms.insert(num); // O(log N)으로 자동 정렬 삽입
        }
        else {
            if (ms.empty()) continue; // 빈 경우 무시

            if (num == 1) {
                // 최댓값 삭제: 맨 뒤 요소 삭제
                // end()는 마지막 다음을 가리키므로 prev()로 이전 거를 지움
                ms.erase(prev(ms.end())); 
            }
            else {
                // 최솟값 삭제: 맨 앞 요소 삭제
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty()) return {0, 0};
    
    // {최댓값, 최솟값}
    return { *ms.rbegin(), *ms.begin() };
}