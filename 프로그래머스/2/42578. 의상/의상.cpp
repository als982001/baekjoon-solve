#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    vector<string> clothTypes; // 의상의 종류를 저장하는 변수
    map<string, int> clothCounts; // 의상의 종류별 개수
    
    for (vector<string> clothInfo : clothes)
    {
        string cloth = clothInfo[1];
        
        // 처음 확인하는 의상 종류는 저장
        if (clothCounts[cloth] == 0)
        {
            clothCounts[cloth] = 1;
            clothTypes.push_back(cloth);
        }
        else
            ++clothCounts[cloth]; // 저장한 적 있으면 수만 증가
    }
    
    for (string cloth : clothTypes)
    {        
        int clothCount = clothCounts[cloth];
                
        // 안 입는 경우도 포함해서 옷 개수 + 1을 곱함
        answer *= (clothCount + 1);
    }
    
    --answer; // 전부 안 입는 경우를 고려해서 1 감소
    
    return answer;
}