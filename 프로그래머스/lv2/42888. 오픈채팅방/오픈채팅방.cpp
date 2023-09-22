#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    
	vector<pair<string, string>> result;
	map<string, string> nicknames;
	map<string, string> korean;
	korean["Enter"] = "님이 들어왔습니다.";
	korean["Leave"] = "님이 나갔습니다.";

	for (int i = 0; i < record.size(); ++i)
	{
		string curRecord = record[i];
	
		char behavior = curRecord[0];
		switch (behavior)
		{
		case 'E':
		{
			int idx = 6;
			string uid = "";
			string nickname = "";

			while (curRecord[idx] != ' ')
				uid += curRecord[idx++];
			++idx;

			nickname = curRecord.substr(idx);
			
			result.push_back({ "Enter", uid });

			if (nicknames[uid] == "" || nicknames[uid] != nickname)
				nicknames[uid] = nickname;

			break;
		}
		case 'L':
		{
			int idx = 6;
			string uid = curRecord.substr(idx);

			result.push_back({ "Leave", uid });

			break;
		}
		case 'C':
		{
			int idx = 7;
			string uid = "";
			string nickname = "";

			while (curRecord[idx] != ' ')
				uid += curRecord[idx++];
			++idx;

			nickname = curRecord.substr(idx);

			nicknames[uid] = nickname;

			break;
		}
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		string behavior = result[i].first;
		string uid = result[i].second;
    
        answer.push_back(nicknames[uid] + korean[behavior]);
	}
	

	return answer;

}