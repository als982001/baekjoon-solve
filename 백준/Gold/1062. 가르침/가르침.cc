#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int N, K;

int answer;
bool check[26];
vector<string> words;
string antatica = "acint";

void Check(int cur_idx, int cnt)
{
	if (cnt == K)
	{
		int completed_words = 0;

		for (int w = 0; w < N; ++w)
		{
			bool complete = true;

			for (int idx = 0; idx < words[w].size(); ++idx)
			{
				if (!check[words[w][idx] - 'a'])
				{
					complete = false;
					break;
				}
			}

			if (complete)
				++completed_words;
		}

		if (answer < completed_words)
			answer = completed_words;

		return;
	}

	for (int idx = cur_idx; idx < 26; ++idx)
	{
		if (!check[idx])
		{
			check[idx] = true;
			Check(idx + 1, cnt + 1);
			check[idx] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; ++i)
	{
		char tempstr[20];
		scanf("%s", tempstr);
		words.push_back(tempstr);
	}

	if (K <= 4)
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < antatica.size(); ++i)
		check[antatica[i] - 'a'] = true;
	K -= 5;

	Check(0, 0);

	cout << answer << endl;

	return 0;
}