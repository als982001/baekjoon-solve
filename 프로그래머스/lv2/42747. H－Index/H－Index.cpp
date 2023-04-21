#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b) {

    if (a > b)
        return true;
    else
        return false;

}

int solution(vector<int> numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), Compare);
    // 6 5 3 1 0
    for (int curH = numbers[0]; curH >= 0; --curH) {

        int count = 0;
        int idx = 0;

        for (idx = 0; idx < numbers.size(); ++idx) {

            if (numbers[idx] >= curH)
                ++count;
            else
                break;
        }
        
        //if (idx >= numbers.size())
        //    return numbers[0];

        if (count >= curH && numbers[idx] <= curH) {

            answer = curH;
            break;
        }
    }



    return answer;
}