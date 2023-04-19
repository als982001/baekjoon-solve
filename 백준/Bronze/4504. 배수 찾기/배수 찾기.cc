#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;

int N, K;
vector<int> nums;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> N;

	cin >> K;

	while(K != 0)
	{
		nums.push_back(K);
		
		cin >> K;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] % N == 0)
			cout << nums[i] << " is a multiple of "<< N << "." << endl;
		else
			cout << nums[i] << " is NOT a multiple of " << N << "." << endl;
	}

    return 0;
}
