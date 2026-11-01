#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> categories;
map<string, int> clothesNum;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for (vector<string> clothInfo : clothes)
    {
        string category = clothInfo[1];
        
        if (clothesNum[category] == 0)
        {
            clothesNum[category] = 1;
            categories.push_back(category);
        }
        else
            ++clothesNum[category];
    }
    
    for (string category : categories)
        answer *= (clothesNum[category] + 1);
    --answer; // 아예 안 입는 경우는 제외
    
    return answer;
}