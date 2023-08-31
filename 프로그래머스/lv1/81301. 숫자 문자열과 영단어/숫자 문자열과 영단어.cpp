#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    string result = s;

    string numsStr[10] = { "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine" };

    string nums[10] = { "0", "1", "2", "3", "4", 
    "5", "6", "7", "8", "9" };

    for (int findNum = 0; findNum < 10; ++findNum)
    {
        string curNum = numsStr[findNum];
        int curNumLen = curNum.size();

        while (result.find(curNum) != -1)
        {
            int curNumIdx = result.find(curNum);

            result = result.substr(0, curNumIdx) + nums[findNum] + result.substr(curNumIdx + curNumLen);
        }
    }

    answer = stoi(result);
    return answer;
}