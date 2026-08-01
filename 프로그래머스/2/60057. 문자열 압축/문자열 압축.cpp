#include <string>
#include <vector>

using namespace std;

int solution(string s)
{ 
    int answer = s.size();

	for (int len = 1; len < s.size(); ++len)
	{
		string result = "";

		int count = 1;
		int idx = 0;

		string cur = s.substr(idx, len);

		for (idx = len; idx < s.size(); idx += len)
		{
			string nxt = s.substr(idx, len);
			
			if (cur == nxt)
				++count;
			else
			{
				if (count == 1)
					result += cur;
				else
				{
					result += to_string(count);
					result += cur;
				}

				cur = nxt;
				count = 1;
			}
		}

		if (idx >= s.size())
		{
			if (count == 1)
				result += cur;
			else
			{
				result += to_string(count);
				result += cur;
			}
		}

		answer = min(answer, int(result.size()));
	}

	return answer;
}