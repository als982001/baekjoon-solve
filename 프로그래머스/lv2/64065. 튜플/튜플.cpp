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

    vector<vector<int>> sets = Parse(s);
    
    sort(sets.begin(), sets.end(), Compare);
    
    for (int i = 0; i < sets.size(); ++i)
    {
        vector<int> curTuple = sets[i];
        
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