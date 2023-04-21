#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> person[3];
    person[0] = { 1, 2, 3, 4, 5 };
    person[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    person[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int score[3] = { 0, 0, 0 };
    int maxScore = -1;

    for (int personIdx = 0; personIdx < 3; ++personIdx) {

        int ansNum = person[personIdx].size();

        for (int idx = 0; idx < answers.size(); ++idx) {

            if (answers[idx] == person[personIdx][idx % ansNum])
                ++score[personIdx];
        }

        if (maxScore < score[personIdx])
            maxScore = score[personIdx];
    }
    
    for (int i = 0; i < 3; ++i) {

        if (maxScore == score[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}