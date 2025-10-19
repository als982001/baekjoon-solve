#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)  {
    const vector<string> SYL = {"aya","ye","woo","ma"};
    
    int answer = 0;

    for (auto s : babbling) 
    {
        // 각 허용 음절이 있으면 같은 길이의 공백으로 치환(경계 유지)
        for (const auto& w : SYL) 
        {
            size_t pos = s.find(w);
            if (pos != string::npos) {
                s.replace(pos, w.size(), string(w.size(), ' '));
            }
        }
        // 전부 공백이면 (= 허용 음절들의 연속으로만 구성) 카운트
        bool ok = true;
        for (char c : s) if (c != ' ') { ok = false; break; }
        if (ok) ++answer;
    }
    return answer;
}