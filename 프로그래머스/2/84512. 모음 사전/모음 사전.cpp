#include <string>
#include <vector>
#include <map>

using namespace std;

/*
// 첫 번째 자리가 바뀔 때의 간격
A = 1
AA = 1
AAA = 1
AAAA = 1
AAAAA ~ AUUUU = 625
AAAE ~ AUUU = 125 - 1
AAE ~ AUU = 25 - 1
AE AI AO AU = 5 - 1

E = 5 + 25 + 125 + 625 + 1 = 781
앞자리는 781씩 증가

// 두 번째 자리가 바뀔 때의 간격
_A = 1
_AA = 1
_AAA = 1
_AAAA ~ _AUUU = 125
_AAE ~ _AUU = 25 - 1
_AE _AI _AO _AU = 5 - 1
_E = 125 + 25 + 5 + 1 = 156

// x번째 자리 바뀔 때 간격
// 1 + 5^1 + ... + 5^(x + 1)
*/

vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };

int solution(string word) {
    int answer = 0;
    
    int weightByIndex[5] = { 781, 156, 31, 6, 1 };
    
    map<char, int> vowelOrders;
    
    for (int i = 0; i < vowels.size(); ++i)
        vowelOrders[vowels[i]] = i;
    
    for (int idx = 0; idx < word.size(); ++idx)
    {
        char vowelOrder = vowelOrders[word[idx]];
        
        answer += (1 + vowelOrder * weightByIndex[idx]);
    }
    
    return answer;
}

