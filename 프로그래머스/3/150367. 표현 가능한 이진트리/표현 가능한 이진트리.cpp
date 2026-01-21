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


