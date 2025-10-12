#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<char, int> GetNumberWord(string numbers, int idx)
{
    // first: 숫자
    // second: 다음 index
    pair<int, int> result;
    
    // zero
    if (numbers[idx] == 'z')
        return { '0', idx + 4 };
    
    // one
    if (numbers[idx] == 'o')
        return { '1', idx + 3 };
    
    // two, three
    if (numbers[idx] == 't')
    {
        // two
        if (numbers[idx + 1] == 'w')
            return { '2', idx + 3 };
        
        // three
        if (numbers[idx + 1] == 'h')
            return { '3', idx + 5 };
    }
    
    // four, five
    if (numbers[idx] == 'f')
    {
        // four
        if (numbers[idx + 1] == 'o')
            return { '4', idx + 4 };
        
        // five
        if (numbers[idx + 1] == 'i')
            return { '5', idx + 4 };
    }
    
    // six, seven
    if (numbers[idx] == 's')
    {
        if (numbers[idx + 1] == 'i')
            return { '6', idx + 3 };
        
        if (numbers[idx + 1] == 'e')
            return { '7', idx + 5 };
    }
    
    // eight
    if (numbers[idx] == 'e')
        return { '8', idx + 5 };
    
    // nine
    if (numbers[idx] == 'n')
        return { '9', idx + 4 };
    
    return { '0', numbers.size() + 1 };
}

long long solution(string numbers) {
    long long answer = 0;
    
    string answerStr = "";
    
    int idx = 0;
    
    while(idx < numbers.size())
    {
        pair<int, int> info = GetNumberWord(numbers, idx);
        
        answerStr += info.first;
        idx = info.second;
    }
    
    answer = stoll(answerStr);
    
    return answer;
}