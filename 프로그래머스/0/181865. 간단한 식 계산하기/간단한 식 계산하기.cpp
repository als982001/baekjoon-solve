#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    int firstBlankIdx = binomial.find_first_of(' ');
    int lastBlankIdx = binomial.find_last_of(' ');
    
    string a = binomial.substr(0, firstBlankIdx);
    string b = binomial.substr(lastBlankIdx);
    char op = binomial[firstBlankIdx + 1];
    
    int numA = stoi(a);
    int numB = stoi(b);
        
    switch(op)
    {
        case '+':
            answer = numA + numB;
            break;
        case '-':
            answer = numA - numB;
            break;
        case '*':
            answer = numA * numB;
            break;
    }
    
    
    
    return answer;
}