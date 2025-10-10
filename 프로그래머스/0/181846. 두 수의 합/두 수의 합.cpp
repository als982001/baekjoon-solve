#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer;
    
    // 뒤에서부터 자리수 합치기
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    

    while (i >= 0 || j >= 0 || carry) 
    {
        int da = (i >= 0) ? (a[i] - '0') : 0;
        int db = (j >= 0) ? (b[j] - '0') : 0;

        int sum = da + db + carry;
        answer.push_back(char('0' + (sum % 10)));
        carry = sum / 10;

        --i; 
        --j;
    }

    reverse(answer.begin(), answer.end());


    return answer;
}