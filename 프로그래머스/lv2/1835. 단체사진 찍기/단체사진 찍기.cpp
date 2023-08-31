#include <string>
#include <vector>
#include <map>
using namespace std;

int answer = 0;
char people[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
bool checked[8];
vector<char> line;
vector<string> allData;

void Check(int cnt)
{
    if (cnt >= 8)
    {   
        map<char, int> lineOrder;
        
        for (int i = 0; i < line.size(); ++i)
            lineOrder[line[i]] = i;
        
        for (int i = 0; i < allData.size(); ++i)
        {
            char person1 = allData[i][0];
            char person2 = allData[i][2];
            char requirement = allData[i][3];
            int requiredInterval = (allData[i][4] - '0') + 1;
            int interval = abs(lineOrder[person1] - lineOrder[person2]);
            
            if (requirement == '=')
            {
                if (requiredInterval != interval)
                    return;
            }
            else if (requirement == '>')
            {
                if ((requiredInterval < interval) == false)
                    return;
            }
            else if (requirement == '<')
            {
                if ((requiredInterval > interval) == false)
                    return;
            }
        }
        
        ++answer;
        return;
    }
    
    for (int i = 0; i < 8; ++i)
    {
        if (checked[i] == false)
        {
            checked[i] = true;
            line.push_back(people[i]);
            
            Check(cnt + 1);
            
            line.pop_back();
            checked[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    
    allData = data;
    
    line.clear();
    
    for (int i = 0; i < 8; ++i)
        checked[i] = false;
    
    Check(0);
    
    return answer;
}