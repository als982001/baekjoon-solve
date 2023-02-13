#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

int Bigger(int a, int b)
{
	return a > b ? a : b;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

	vector<int> deliveryDistances;
	vector<int> pickupDistances;

	int curCap = cap;
	int maxDistance = 0;

	for (int i = 0; i < deliveries.size(); ++i)
	{
		while(deliveries[i] > 0)
		{
			stk.push(i + 1);
			--deliveries[i];
		}
	}

	while(stk.empty() == false)
	{	
		int distance = stk.top();
		stk.pop();

		--curCap;

		if (maxDistance < distance)
			maxDistance = distance;

		if (curCap == 0 || stk.empty())
		{
			curCap = cap;
			deliveryDistances.push_back(maxDistance);
			maxDistance = 0;
		}
	}

	curCap = cap;
	maxDistance = 0;

	for (int i = 0; i < pickups.size(); ++i)
	{
		while(pickups[i] > 0)
		{
			stk.push(i + 1);
			--pickups[i];
		}
	}

	while(stk.empty() == false)
	{	
		int distance = stk.top();
		stk.pop();

		--curCap;

		if (maxDistance < distance)
			maxDistance = distance;

		if (curCap == 0 || stk.empty())
		{
			curCap = cap;
			pickupDistances.push_back(maxDistance);
			maxDistance = 0;
		}
	}

	if (deliveryDistances.size() < pickupDistances.size())
	{
		for (int i = 0; i < deliveryDistances.size(); ++i)
			answer += Bigger(deliveryDistances[i], pickupDistances[i]);
		
		for (int i = deliveryDistances.size(); i < pickupDistances.size(); ++i)	
			answer += pickupDistances[i];
	}
	else
	{
		for (int i = 0; i < pickupDistances.size(); ++i)
			answer += Bigger(deliveryDistances[i], pickupDistances[i]);
		
		for (int i = pickupDistances.size(); i < deliveryDistances.size(); ++i)	
			answer += deliveryDistances[i];
	}

    return answer * 2;
}