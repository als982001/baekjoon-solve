#include <string>
#include <vector>
#include <algorithm>

#define MAX 1000001

using namespace std;

string Convert(int num, int k)
{
    string result = "";
    
    while(num > 0)
    {
        long long rest = num % k;
        result += to_string(rest);
        num /= k;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

vector<long long> Split(string num)
{
    vector<long long> result;
    
    string splitNum = "";
    
    for (int i = 0; i < num.size(); ++i)
    {
        if (num[i] == '0')
        {
            if (splitNum.size() > 0)
            {
                long long targetNum = stoll(splitNum);
    
                result.push_back(stoll(splitNum));
                splitNum = "";
            }
        }
        else
            splitNum += num[i];
    }
    
    if (splitNum.size() > 0)                
        result.push_back(stoll(splitNum));
    
    return result;
}

bool CheckPrimeNumber(long long num)
{
    if (num < 2)
        return false;
    
    bool isPrimeNumber = true;

    for (long long k = 2; k * k <= num; ++k)
    {
        if (num % k == 0)
        {
            isPrimeNumber = false;
            break;
        }
            
    }
    
    return isPrimeNumber;
}

int solution(int n, int k) {
    int answer = 0;
    
    string convertedNum = Convert(n, k);
    
    vector<long long> nums = Split(convertedNum);
    
    for (long long num : nums)
    {
        bool isPrimeNumber = CheckPrimeNumber(num);
        
        if (isPrimeNumber)
            ++answer;
    }
    
    return answer;
}


/*

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1000111

using namespace std;

// k진수로 변환
string Convert(long long num, long long k)
{
    string result = "";
    
    while(num > 0)
    {
        long long rest = num % k;
        result += to_string(rest);
        
        num /= k;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

// 0을 기준으로 split
vector<long long> Split(string num)
{
    vector<long long> result;
    
    string part = "";
    
    for (int i = 0; i < num.size(); ++i)
    {
        if (num[i] == '0')
        {
            if (part.size() > 0)
            {
                result.push_back(stoi(part));
                part = "";
            }
        }
        else
            part += num[i];
    }
    
    if (part.size() > 0)
        result.push_back(stoll(part));
    
    return result;
}

bool CheckPrimeNumber(long long num)
{
    if (num < 2)
        return false;
    
    bool isPrimeNumber = true;
    
    long long mid = sqrt(num);
    
    for (long long x = 2; x <= mid; ++x)
    {
        if (num % x == 0)
        {
            isPrimeNumber = false;
            break;
        }
    }
    
    return isPrimeNumber;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num = Convert(n, k);
    
    vector<long long> parts = Split(num);
    
    for (long long part : parts)
    {
        if (CheckPrimeNumber(part))
            ++answer;
    }
    
    return answer;
}


*/