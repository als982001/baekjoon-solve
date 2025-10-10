#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    string allNumbers = "";
    
    for (int num = i; num <= j; ++num)
    {
        allNumbers += to_string(num);
    }
    
    for (char number : allNumbers)
    {
        if ((number - '0') == k)
            ++answer;
    }
    
    return answer;
}