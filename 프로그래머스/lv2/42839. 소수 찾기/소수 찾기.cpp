#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAX 10000001

int answer = 0;
bool used[MAX];
bool checked[MAX];
string allNumbers;
string result;

void Check(int len)
{
    if (result.size() == len)
    {
        int num = stoi(result);
        
        if (checked[num] == true)
            return;
        checked[num] = true;
        
        if (num <= 1)
            return;
        
        for (int k = 2; k * k <= num; ++k)
        {
            if (num % k == 0)
                return;
        }
        
        ++answer;
        return;
    }
    
    for (int i = 0; i < allNumbers.size(); ++i)
    {
        if (used[i] == false)
        {
            used[i] = true;
            result += allNumbers[i];
            
            Check(len);
            
            result.pop_back();
            used[i] = false;
        }
    }
}

int solution(string numbers)
{
    allNumbers = numbers;
  
    for (int len = 1; len <= allNumbers.size(); ++len)
        Check(len);
    
    return answer;
}