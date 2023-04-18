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

int T, N, C;
double G;
vector<pair<int, double>> gpa;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> N;

		int totalGrades = 0;
		double totalScore = 0;

		for (int n = 0; n < N; ++n)
		{
			cin >> C >> G;

			totalGrades += C;
			totalScore += (G * C);
		}

		double finalScore = (totalScore / totalGrades) * 10;
		finalScore = round(finalScore);
		finalScore /= 10;

		gpa.push_back({ totalGrades, finalScore });
	}

	for (int i = 0; i < gpa.size(); ++i)
		printf("%d %.1lf \n", gpa[i].first, gpa[i].second);

    return 0;
}
