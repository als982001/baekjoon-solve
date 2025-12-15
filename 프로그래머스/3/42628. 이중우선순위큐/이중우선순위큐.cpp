#include <string>
#include <vector>
#include <deque>
#include <sstream>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    // 만약 input들을 오름차순으로 정렬할 경우
    // -642, -45, 45, 97, 333, 653
    // -642, -45   |   45, 97, 333, 653  처럼 나눌 수 있다.
    
    deque<int> smallNumbers;
    deque<int> bigNumbers;
    
    for (string operation : operations)
    {
        bool caseInput = operation[0] == 'I';
        
        if (caseInput)
        {
            int num = stoi(operation.substr(2));
            
            // 두 deque이 모두 빈 경우: 작은 숫자 덱에 push
            if (smallNumbers.empty() && bigNumbers.empty())
                smallNumbers.push_back(num);
            // 작은 숫자 deque만 비어있는 경우
            else if (smallNumbers.empty() && !bigNumbers.empty())
            {
                int smallestOfBigNumbers = bigNumbers.front();
                int biggestNumber = bigNumbers.back();
                
                // 큰 숫자들 중 가장 작은 수보다 작을 경우: 작은 숫자 덱에 push
                if (num < smallestOfBigNumbers)
                    smallNumbers.push_back(num);
                // 제일 큰 수보다 더 큰 경우: 큰 숫자 덱에 push
                else if (biggestNumber < num)
                    bigNumbers.push_back(num);
                else
                {
                    while(!bigNumbers.empty())
                    {
                        int bigNumber = bigNumbers.front();
                       
                        if (bigNumber < num)
                        {
                            bigNumbers.pop_back();
                            smallNumbers.push_back(bigNumber);
                        }
                        else
                        {
                            bigNumbers.push_front(num);
                            break;
                        }
                    }
                }
            }
            // 큰 숫자 deque만 비어있는 경우
            else if (!smallNumbers.empty() && bigNumbers.empty())
            {
                int smallestNumber = smallNumbers.front();
                int biggestOfSmallNumbers = smallNumbers.back();
                
                if (num < smallestNumber)
                    smallNumbers.push_front(num);
                else if (biggestOfSmallNumbers < num)
                    bigNumbers.push_front(num);
                else
                {
                    while(!smallNumbers.empty())
                    {
                        int smallNumber = smallNumbers.back();
                        
                        if (num < smallNumber)
                        {
                            smallNumbers.pop_back();
                            bigNumbers.push_front(smallNumber);
                        }
                        else
                        {
                            smallNumbers.push_back(num);
                            break;
                        }
                    }
                }
            }
            else
            {
                int smallestNumber = smallNumbers.front();
                int biggestOfSmallNumbers = smallNumbers.back();
                
                int smallestOfBigNumbers = bigNumbers.front();
                int biggestNumber = bigNumbers.back();
                
                if (num <= smallestNumber)
                    smallNumbers.push_front(num);
                else if (smallestNumber < num && num < biggestOfSmallNumbers)
                {
                    while(!smallNumbers.empty())
                    {
                        int smallNumber = smallNumbers.back();
                        
                        if (num < smallNumber)
                        {
                            smallNumbers.pop_back();
                            bigNumbers.push_front(smallNumber);
                        }
                        else
                        {
                            smallNumbers.push_back(num);
                            break;
                        }
                    }
                }
                else if (biggestOfSmallNumbers <= num && num <= smallestOfBigNumbers)
                    smallNumbers.push_back(num);
                else if (smallestOfBigNumbers < num && num < biggestNumber)
                {
                    while(!bigNumbers.empty())
                    {
                        int bigNumber = bigNumbers.front();
                        
                        if (bigNumber < num)
                        {
                            bigNumbers.pop_front();
                            smallNumbers.push_back(bigNumber);
                        }
                        else
                        {
                            bigNumbers.push_front(num);
                            break;
                        }
                    }
                }
                else if (biggestNumber <= num)
                    bigNumbers.push_back(num);
            }
        }
        else
        {
            // 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시
            if (smallNumbers.empty() && bigNumbers.empty())
                continue;
            
            bool removeBiggestNumber = operation[2] == '1';
            
            if (removeBiggestNumber)
            {
                if (!bigNumbers.empty())
                    bigNumbers.pop_back();
                else
                    smallNumbers.pop_back();
            }
            else
            {
                if (!smallNumbers.empty())
                    smallNumbers.pop_front();
                else
                    bigNumbers.pop_front();
            }
        }
    }
    
    
   if (smallNumbers.empty() && bigNumbers.empty())
       return { 0, 0 };
    
    if (!smallNumbers.empty() && bigNumbers.empty())
    {
        answer.push_back(smallNumbers.back());
        answer.push_back(smallNumbers.front());
    }
    else if (smallNumbers.empty() && !bigNumbers.empty())
    {
        answer.push_back(bigNumbers.back());
        answer.push_back(bigNumbers.front());
    }
    else
    {
        answer.push_back(bigNumbers.back());
        answer.push_back(smallNumbers.front());
    }

    
    return answer;
}
