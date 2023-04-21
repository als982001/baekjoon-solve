#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	
	int maxR = 0, maxC = 0;

	for (int i = 0; i < sizes.size(); ++i)
	{
		if (sizes[i][0] < sizes[i][1])
		{
			int tmp = sizes[i][0];
			sizes[i][0] = sizes[i][1];
			sizes[i][1] = tmp;
		}

		if (maxR < sizes[i][0])
			maxR = sizes[i][0];

		if (maxC < sizes[i][1])
			maxC = sizes[i][1];
	}

	return maxR * maxC;

}