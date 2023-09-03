#include <string>
#include <vector>
#include <map>
#define LEFT 'L'
#define RIGHT 'R'
using namespace std;

map<int, pair<int, int>> coordinate;

int Distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    char defaultHand = hand == "left" ? LEFT : RIGHT;
    
    coordinate[1] = { 0, 0 }, coordinate[2] = { 0, 1 }, coordinate[3] = { 0, 2 };
    coordinate[4] = { 1, 0 }, coordinate[5] = { 1, 1 }, coordinate[6] = { 1, 2 };
    coordinate[7] = { 2, 0 }, coordinate[8] = { 2, 1 }, coordinate[9] = { 2, 2 };
    coordinate[0] = { 3, 1 };
    
    pair<int, int> leftHand = { 3, 0 };
    pair<int, int> rightHand = { 3, 2 };
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        int number = numbers[i];
                
        if (number == 1 || number == 4 || number == 7)
        {
            leftHand = coordinate[number];
            answer += LEFT;
        }
        else if (number == 3 || number == 6 || number == 9)
        {
            rightHand = coordinate[number];
            answer += RIGHT;
        }
        else
        {
            int leftHandDistance = Distance(leftHand, coordinate[number]);
            int rightHandDistance = Distance(rightHand, coordinate[number]);
            
            if (leftHandDistance < rightHandDistance)
            {
                leftHand = coordinate[number];
                answer += LEFT;
            }
            else if (leftHandDistance > rightHandDistance)
            {
                rightHand = coordinate[number];
                answer += RIGHT;
            }
            else
            {
                if (defaultHand == LEFT)
                {
                    leftHand = coordinate[number];
                    answer += LEFT;
                }
                else
                {
                    rightHand = coordinate[number];
                    answer += RIGHT;
                }
            }
        }
    }
    
    
    return answer;
}
