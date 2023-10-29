#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> answerIdx;             // 멤버별 answer의 인덱스 번호
map<string, int> reportedNum;           // 멤버마다 신고 당한 횟수
map<string, vector<string>> reporters;  // 신고 당한 사람을 신고한 사람들 이름

bool Push_Name(string reported, string reporter)
{
    for (int i = 0; i < reporters[reported].size(); ++i)
    {
        if (reporters[reported][i] == reporter)
            return false;
    }

    reporters[reported].push_back(reporter);

    return true;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    answer.resize(id_list.size());
   
    for (int i = 0; i < id_list.size(); ++i)
    {
        string curPerson = id_list[i];
        answerIdx[curPerson] = i;
    }
    
    // 사람마다 신고를 당한 횟수 센다
    for (int i = 0; i < report.size(); ++i)
    {
        string curReport = report[i];

        for (int k = 0; k < curReport.size(); ++k)
        {
            if (curReport[k] == ' ')
            {
                string reporter = curReport.substr(0, k);   // 신고를 "한" 사람
                string reported = curReport.substr(k + 1);  // 신고를 "당한" 사람

                // 신고 당한 사람을 신고한 사람 이름 저장에 성공했다면
                if(Push_Name(reported, reporter))
                {
                    // 신고 당한 횟수 기록
                    // 신고 당한 횟수 기록
                    if (reportedNum[reported] == 0)
                        reportedNum[reported] = 1;
                    else
                        ++reportedNum[reported];
                }
            }
        }
    }

    // 신고 당한 사람 중 k번 이상 신고당한 사람 있으면
    // 그 사람을 신고한 사람에게 메일 발송(answer++)
    map<string, int>::iterator iter;
    for (iter = reportedNum.begin(); iter != reportedNum.end(); ++iter)
    {
        int curReportedNum = iter->second;

        if (curReportedNum >= k)
        {
            string curReported = iter->first;

            for (int i = 0; i < reporters[curReported].size(); ++i)
            {
                string curReporter = reporters[curReported][i];
                int curReporterIdx = answerIdx[curReporter];
                ++answer[curReporterIdx];
            }
        }
    }

    return answer;
}