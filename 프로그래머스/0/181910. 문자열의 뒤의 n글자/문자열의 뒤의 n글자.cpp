#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    int startIndex = my_string.size() - n;
    
    string slicedString = my_string.substr(startIndex, n);
    answer += slicedString;
    
    return answer;
}