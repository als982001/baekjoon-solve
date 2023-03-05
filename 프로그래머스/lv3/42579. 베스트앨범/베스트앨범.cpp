#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define CASE 1

map<string, int> playByGenre;					// 장르별 재생된 횟수
map<string, vector<pair<int, int>>> maxPlays;
vector<string> genreList;						// 장르 당 가장 재생 많이 된 노래 두 개

bool Compare(string a, string b)
{
	if (playByGenre[a] > playByGenre[b])
		return true;
	else
		return false;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;	

	for (int idx = 0; idx < genres.size(); ++idx)
	{
		string genre = genres[idx];
		int play = plays[idx];

		// 만약 처음 보는 장르라면 장르 리스트에 추가.
		if (playByGenre[genre] == 0)
			genreList.push_back(genre);
		playByGenre[genre] += play;	// 장르별 재생 횟수 갱신

		if (maxPlays[genre].size() == 0)
			maxPlays[genre].push_back({ play, idx });
		else if (maxPlays[genre].size() == 1)
		{
			if (maxPlays[genre][0].first < play)
			{
				pair<int, int> temp = maxPlays[genre][0];
				maxPlays[genre][0] = { play, idx };
				maxPlays[genre].push_back(temp);
			}
			else
				maxPlays[genre].push_back({ play, idx });
		}
		else if (maxPlays[genre].size() == 2)
		{
			if (maxPlays[genre][0].first < play)
			{
				pair<int, int> temp = maxPlays[genre][0];
				maxPlays[genre][0] = { play, idx };
				maxPlays[genre][1] = temp;
			}
			else if (maxPlays[genre][1].first < play)
				maxPlays[genre][1] = { play, idx };
		}
	}

	sort(genreList.begin(), genreList.end(), Compare);

	for (int i = 0; i < genreList.size(); ++i)
	{
		string genre = genreList[i];

		for (int p = 0; p < maxPlays[genre].size(); ++p)
			answer.push_back(maxPlays[genre][p].second);
	}

	return answer;
}