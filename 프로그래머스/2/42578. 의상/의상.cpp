#include <string>
#include <vector>
#include <map>
#define MAX 35
using namespace std;

int clothNum[MAX];
int clothID = 1;
map<string, int> kind;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for (int i = 0; i < clothes.size(); ++i) {

        string curCloth = clothes[i][1];
        
        if (kind[curCloth] == 0) {
            kind[curCloth] = clothID;
            clothNum[clothID] = 1;
            ++clothID;
        }
        else {

            int curID = kind[curCloth];
            ++clothNum[curID];
        }
    }

    for (int i = 1; i < clothID; ++i)
        answer *= (clothNum[i] + 1);
    answer -= 1;
    
    return answer;
}
