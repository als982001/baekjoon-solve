#include <iostream>
#include <string>
using namespace std;

bool pls;
int s_len;
int sum;
string s;

int main()
{
	cin >> s;
	s_len = s.size();
	pls = true;

	for (int i = 0; i < s_len; ++i)
	{
		string temp;

		while ('9' >= s[i] && s[i] >= '0')
			temp.push_back(s[i++]);
		
		if (pls)
			sum += stoi(temp);
		else
			sum -= stoi(temp);

		if (s[i] == '-')
			pls = false;
	}

	cout << sum << endl;

	return 0;
}