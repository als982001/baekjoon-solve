#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b) {
    
    string A = to_string(a);
    string B = to_string(b);

    string x = A + B;
    string y = B + A;

    if (x > y)
        return true;
    else
        return false;

}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), Compare);

    for (int i = 0; i < numbers.size(); ++i)
        answer += to_string(numbers[i]);
    
    bool allZero = true;
    for (int i = 0; i < answer.size(); ++i) {
        
        if (answer[i] != '0')
            allZero = false;
    }

    if (allZero == true)
        return "0";

    return answer;
}
