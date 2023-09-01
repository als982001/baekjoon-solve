#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
vector<int> solution(string s) {
    vector<int> answer;
    
   vector<string> tps(500);

    int tps_num = 0;
    int norder = 0;

    for (int i = 1; i < s.size(); ++i)
    {
        string stemp;
        int norder = 0;

        if (s[i] == '{')
        {
            while (s[i] != '}')
            {
                if (s[i] == ',')
                    ++norder;
                stemp.push_back(s[i]);
                ++i;
            }

            tps[norder] = stemp;
            ++tps_num;
        }
    }

    for (int i = 0; i < tps_num; ++i)
    {
        for (int j = 1; j < tps[i].size(); ++j)
        {
            string stemp;
            int ntemp;

            while ('9' >= tps[i][j] && tps[i][j] >= '0')
            {
                stemp.push_back(tps[i][j++]);
            }

            ntemp = stoi(stemp);

            bool isin = false;

            for (int ans_num = 0; ans_num < answer.size(); ++ans_num)
            {
                if (ntemp == answer[ans_num])
                    isin = true;
            }

            if (!isin)
                answer.push_back(ntemp);
        }
    }
    return answer;
}
*/

bool check[100001];

bool Compare(vector<int> a, vector<int> b)
{
	if (a.size() < b.size())
		return true;
	else
		return false;
}

vector<int> solution(string s)
{
	vector<int> answer;

	int idx = 1;

	vector<vector<int>> numsVec;

	while (idx < s.size() - 1)
	{
		if (s[idx] == '{')
		{
			vector<int> nums;

			while (s[idx] != '}')
			{
				++idx;
				string num = "";

				while ('0' <= s[idx] && s[idx] <= '9')
				{
					num += s[idx];
					++idx;
				}

				nums.push_back(stoi(num));
			}

			numsVec.push_back(nums);
		}
		else
			++idx;
	}

	sort(numsVec.begin(), numsVec.end(), Compare);

	for (int i = 0; i < numsVec.size(); ++i)
	{
		for (int k = 0; k < numsVec[i].size(); ++k)
		{
			int num = numsVec[i][k];

			if (!check[num])
			{
				check[num] = true;
				answer.push_back(num);

				break;
			}
		}
	}
	

	return answer;
}