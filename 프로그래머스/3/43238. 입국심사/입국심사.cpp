#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long maxImgtTime = -1;
    
    for (int imgtTime : times)
    {
        if (maxImgtTime < imgtTime)
            maxImgtTime = imgtTime;
    }
    
    long long minTime = 1;
    long long maxTime = n * maxImgtTime;
    
    answer = maxTime;

    while(minTime <= maxTime)
    {
        long long curTime = (minTime + maxTime) / 2;
        
        long long sum = 0;
        
        for (int imgtTime : times)
            sum += (curTime / imgtTime);
        
        if (n > sum)
            minTime = curTime + 1;
        else
        {
            answer = curTime;
            maxTime = curTime - 1;
        }
    }
    
    return answer;
}

















/*


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long maxCheckTime;
long long peopleNum;
vector<long long> checkTimes;

long long solution(int n, vector<int> times)
{
	// 1. 편의를 위해 모든 값들을 long long형으로 바꾼다.
	// 동시에 심사 받는 시간 중, 가장 긴 심사 시간을 찾는다.
	long long answer = 0;
	
	peopleNum = n;

	for (int i = 0; i < times.size(); ++i)	
	{
		checkTimes.push_back(times[i]);
		maxCheckTime = max(maxCheckTime, checkTimes.back());
	}

	// 2. 이진 탐색을 위한 변수를 설정한다.
	// left의 값은 1(심사하는 데 있어서 최소 1분은 걸리기 때문)
	// right의 값은 심사 최대 시간 x 사람의 수이다. (최악의 경우))
	long long leftTimeVal = 1;
	long long rightTimeVal = maxCheckTime * peopleNum;

	// 3. 이진 탐색을 시작한다.
	while(leftTimeVal <= rightTimeVal)
	{
		long long midTimeVal = (leftTimeVal + rightTimeVal) / 2;

		long long passPeopleNum = 0;

		// 3-1. 중간값이 이번 경우의 총 심사 시간이며
		// 각 심사대마다 현재 주어진 시간동안 몇 명을 심사할 수 있는지를 계산, 총합을 구한다.
		for (int i = 0; i < checkTimes.size(); ++i)
			passPeopleNum += (midTimeVal / checkTimes[i]);

		// 3-2. 만약 모든 심사된 인원이 문제에서 주어진 사람의 수보다 작다면
		// 시간이 부족하다는 뜻이므로 left의 값을 증가시킨다.
		if (passPeopleNum < peopleNum)
			leftTimeVal = midTimeVal + 1;
		else
		{
			// 3-3. 만약 총 심사된 인원의 수가 주어지 사람의 수와 같거나 크다면
			// 시간이 충분하다는 뜻이므로 답에 시간을 저장한 후, right의 값을 줄인다.
			answer = midTimeVal;
			rightTimeVal = midTimeVal - 1;
		}
	}

	return answer;
}

*/