#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define CASE 3

string num;
vector<int> nums;

bool Descend(int a, int b)
{
	return a > b ? true : false;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
	cin >> num;

	for (int i = 0; i < num.size(); ++i)
		nums.push_back(num[i] - '0');
	
	sort(nums.begin(), nums.end(), Descend);

	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i];

	return 0;
}