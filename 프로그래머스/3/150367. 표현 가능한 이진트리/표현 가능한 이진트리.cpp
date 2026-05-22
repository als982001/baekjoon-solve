#include <string>
#include <vector>
#include <algorithm>
#include<cmath>

#include <iostream>

using namespace std;

string NumToBin(long long num)
{
    string result = "";
    
    while(num > 0)
    {
        int r = num % 2;
        
        result += to_string(r);
        num /= 2;
    }
    
    // 이진 트리에 맞게 길이 조정
    int targetLen = 1;
    
    while(targetLen < result.size())
        targetLen = ((targetLen + 1) * 2) - 1;
    
    while(result.size() < targetLen)
        result += "0";
    
    reverse(result.begin(), result.end());
    
    return result;
}

// 1 0 1 1 1 1 1
// 0 1 2 3 4 5 6
bool CheckValidBinary(string bin, int idx, int height, bool onlyZero)
{ 
    // 리프 노드인 경우, 0이어도 상관없음
    if (idx % 2 == 0)
    {
        if (onlyZero)
            return bin[idx] == '0';
        
        return true;
    }
    
    if (idx % 2 == 1)
    {
        if (onlyZero && bin[idx] == '1')
            return false;
        
        // 현재 노드가 0이면 자식 노드 전부 0이어야 함
        bool isOnlyZero = bin[idx] == '0';
        
        int idxDiff = pow(2, height - 1);
        
        int nxtLeftIdx = idx - idxDiff;
        int nxtRightIdx = idx + idxDiff;
        
        return CheckValidBinary(bin, nxtLeftIdx, height - 1, isOnlyZero) && CheckValidBinary(bin, nxtRightIdx, height - 1, isOnlyZero);
    }
}

/*

                    7
        3                      11 
   1         5           9            13
0    2    4     6     8     10    12      14




        3   
   1          5
0     2    4     6



   1
0     2
*/

int GetHeight(int binLen)
{
    int maxHeight = 1;
    int len = 1;
    
    while(len <= binLen)
    {
        ++maxHeight;
        len *= 2;
    }
    
    return maxHeight - 1;
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long num : numbers)
    {
        string bin = NumToBin(num);
        
        int rootNodeHeight = GetHeight(bin.size());
                
        bool isValid = CheckValidBinary(bin, bin.size() / 2, rootNodeHeight - 1, false);
        
        answer.push_back(isValid ? 1 : 0);
    }
    
    return answer;
}






/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string NumToDec(long long number)
{
    string result = "";
    
    while(number > 0)
    {
        int rest = number % 2;
        
        if (rest == 1)
            result += "1";
        else
            result += "0";
        
        number /= 2;
    }

    if (result.size() == 1)
        return result;
    
    reverse(result.begin(), result.end());
    
    int len = 1;
    
    while(len - 1 < result.size())
        len *= 2;
    --len;
    
    while(result.size() < len)
        result = "0" + result;
    
    return result;
}

bool CheckValidBin(string bin)
{
    if (bin.size() == 0)
        return true;
    
    int mid = bin.size() / 2;
    char midNum = bin[mid];
    
    string left = bin.substr(0, mid);
    string right = bin.substr(mid + 1, mid);
    
    if (left.size() > 0)
    {
        if (midNum == '0' && left[left.size() / 2] == '1')
            return false;
    }
    
    if (right.size() > 0)
    {
        if (midNum == '0' && right[right.size() / 2] == '1')
            return false;
    }
    
    
    return CheckValidBin(left) && CheckValidBin(right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long number : numbers)
    {
        string bin = NumToDec(number);
        
        bool isValid = CheckValidBin(bin);
        
        if (isValid)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}




*/