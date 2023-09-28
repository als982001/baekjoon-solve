#include <string>
#include <vector>

using namespace std;

int Min(int a, int b)
{
    return a < b ? a : b;
}

int solution(string s)
{
    /*
    int answer = 0;

    int strLen = s.size();
    answer = strLen;

    int strLenHalf = strLen / 2;
    
    for (int len = 1; len <= strLenHalf; ++len)
    {
        string result = "";
        
        string repeated = s.substr(0, len);
        int cnt = 1;
        int idx = 0;

        for (idx = len; idx <= strLen; idx += len)
        {
            string tmp = s.substr(idx, len);

            if (repeated == tmp)
                ++cnt;
            else
            {
                if (cnt == 1)
                    result += repeated;
                else
                {
                    result += to_string(cnt);
                    result += repeated;
                }

                repeated = tmp;
                cnt = 1;
            }
        }

        if (idx > strLen)
        {
            if (cnt == 1)
                result += repeated;
            else
            {
                result += to_string(cnt);
                result += repeated;
            }
        }
        
        answer = Min(answer, result.size());
    }

    return answer;
    */
    
    int answer = s.size();

	int halfLen = s.size() / 2;

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

		answer = Min(answer, result.size());
	}

	return answer;
}