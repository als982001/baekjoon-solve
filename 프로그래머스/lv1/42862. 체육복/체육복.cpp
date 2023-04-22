#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int hasCloth[31];
    for (int i = 1; i <= n; ++i)
        hasCloth[i] = 1;
    for (int i = 0; i < lost.size(); ++i)
        --hasCloth[lost[i]];
    for (int i = 0; i < reserve.size(); ++i)
        ++hasCloth[reserve[i]];

    for (int curPerson = 1; curPerson <= n; ++curPerson) 
    {
        if (hasCloth[curPerson] >= 2 && curPerson - 1 >= 1) 
        {
            if (hasCloth[curPerson - 1] == 0) 
            {
                ++hasCloth[curPerson - 1];
                --hasCloth[curPerson];
            }
        }
        
        if (hasCloth[curPerson] >= 2 &&  curPerson + 1 <= n) 
        {
            if (hasCloth[curPerson + 1] == 0) 
            {
                ++hasCloth[curPerson + 1];
                --hasCloth[curPerson];
            }
        }
    }

    for (int i = 1; i <= n; ++i) 
    {    
        if (hasCloth[i] >= 1) 
            ++answer;
    }
    
    return answer;
}