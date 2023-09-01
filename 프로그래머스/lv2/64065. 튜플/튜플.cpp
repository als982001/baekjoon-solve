#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checked[100001];

bool Compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<vector<int>> Parse(string s)
{
	vector<vector<int>> result;

	for (int i = 1; i < s.size() - 1; ++i)
	{
		if (s[i] == '{')
		{
			++i;

			vector<int> set;
			string num = "";

			while(true)
			{
				if (s[i] == '}')
				{
					int realNum = stoi(num);
					set.push_back(realNum);
					
					num = "";

					break;
				}
				else if (s[i] == ',')
				{
					int realNum = stoi(num);
					set.push_back(realNum);
					
					num = "";
				}
				else 
					num += s[i];

				++i;
			}

			result.push_back(set);
		}
	}

	return result;
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> tuple = Parse(s);
    
    sort(tuple.begin(), tuple.end(), Compare);
    
    for (int i = 0; i < tuple.size(); ++i)
    {
        vector<int> curTuple = tuple[i];
        
        for (int k = 0; k < curTuple.size(); ++k)
        {
            int num = curTuple[k];
            
            if (checked[num] == false)
            {
                checked[num] = true;
                
                answer.push_back(num);
                
                break;
            }
        }
    }
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
*/