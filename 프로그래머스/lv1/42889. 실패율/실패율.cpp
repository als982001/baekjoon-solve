#include <string>
#include <vector>
#include <algorithm>
#define MAX 501
using namespace std;

int clearNum[MAX];

bool Compare(pair<double, int> a, pair<double, int> b)
{
    if (a.first > b.first)
        return true;
    else if (a.first < b.first)
        return false;
    else
    {
        if (a.second < b.second)
            return true;
        else
            return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<double, int>> failureRate;

    int peopleNum = stages.size();

    for (int i = 0; i < stages.size(); ++i)
    {
        int curLastStage = stages[i];

        for (int i = 0; i < curLastStage; ++i)
            ++clearNum[i];
    }

    for (int i = 0; i < N; ++i)
    {
        int clearPeople = clearNum[i];
        int outPeople = clearPeople - clearNum[i + 1];
        double rate = (double)outPeople / (double)clearPeople;

        failureRate.push_back(make_pair(rate, i + 1));
    }

    sort(failureRate.begin(), failureRate.end(), Compare);

    for (int i = 0; i < failureRate.size(); ++i)
        answer.push_back(failureRate[i].second);

    return answer;
}