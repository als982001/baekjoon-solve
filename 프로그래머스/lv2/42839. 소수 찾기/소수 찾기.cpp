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

/*
#define MAX 10000001


int answer = 0;
int allCheck;
int numLen;
string givenNum;
bool numCheck[10000001];
int prime[10000001];

void PrimeNumberSieve() {

    for (int i = 2; i < MAX; ++i)
        prime[i] = i;

    for (int i = 2; i < MAX; ++i) {

        if (prime[i] == 0)
            continue;

        for (int j = i + i; j < MAX; j += i)
            prime[j] = 0;
    }

}

void DFS(string curNum, int check) {

    if (check == allCheck) {

        int curNumInt = stoi(curNum);

        if (!numCheck[curNumInt] && prime[curNumInt] != 0) {

            numCheck[curNumInt] = true;
            ++answer;
        }

        return;
   }

    for (int idx = 0; idx < numLen; ++idx) {

        int curIdxBit = (1 << idx);

        if (!(curIdxBit & check))
        {
            string newNum = curNum;
            newNum += givenNum[idx];
            int newBit = check | curIdxBit;


            DFS(curNum, newBit);
            DFS(newNum, newBit);
        }
    }
}

int solution(string numbers) {
    PrimeNumberSieve();

    numLen = numbers.size();
    givenNum = numbers;
    allCheck = (1 << numLen) - 1;

    for (int idx = 0; idx < numLen; ++idx) {

        string tmp;
        tmp += numbers[idx];

        int curCheck = (1 << idx);

        DFS(tmp, curCheck);
    }

    return answer;
}
*/