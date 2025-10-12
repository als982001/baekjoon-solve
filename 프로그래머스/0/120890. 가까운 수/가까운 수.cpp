#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    
    for (int num : array)
    {
        int diff = abs(num - n);
        int befDiff = abs(answer - n);
        
        if (befDiff > diff)
            answer = num;
        else if (befDiff == diff && answer > num)
            answer = num;
    }
    
    return answer;
}