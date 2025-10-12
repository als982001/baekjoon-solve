#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

string solution(string bin1, string bin2) {
    string answer;

    int i = (int)bin1.size() - 1;
    int j = (int)bin2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0) 
    {
        int a = (i >= 0) ? (bin1[i] - '0') : 0;
        int b = (j >= 0) ? (bin2[j] - '0') : 0;

        int sum = a + b + carry;
        answer.push_back(char('0' + (sum % 2))); // 이번 자리수
        carry = sum / 2;                         // 다음 자리로 넘길 올림

        --i;
        --j;
    }

    if (carry) 
        answer.push_back('1'); // 마지막 올림 처리
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}