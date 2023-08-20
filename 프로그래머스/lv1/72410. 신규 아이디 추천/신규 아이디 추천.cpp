#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	string tmp = "";
    
	for (int i = 0; i < new_id.size(); ++i)
	{
		// 1단계: 대문자 -> 소문자
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
			new_id[i] += 32;

		// 2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
		if ((
			('a' <= new_id[i] && new_id[i] <= 'z') ||
			('0' <= new_id[i] && new_id[i] <= '9') ||
			new_id[i] == '-' ||
			new_id[i] == '_' ||
			new_id[i] == '.'))
			tmp.push_back(new_id[i]);
	}
	
	// 3단계: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
	while (tmp.find("..") != -1)
	{
		int from = tmp.find("..");
		int to = from;
		for (; tmp[to] == '.'; ++to)
			;
		tmp = tmp.substr(0, to - 1) + tmp.substr(to);
	}
	
	// 4단계: 마침표(.)가 처음이나 끝에 위치한다면 제거
	if (tmp.back() == '.')
		tmp.pop_back();
	if (tmp.size() >1 && tmp.front() == '.')
		tmp = tmp.substr(1);

	// 5단계: 빈 문자열이라면, new_id에 "a"를 대입
	if (tmp.size() == 0)
		tmp = "a";

	// 6단계: new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
	//		  만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
	
	if (tmp.size() >= 16)
	{
		tmp = tmp.substr(0, 15);

		if (tmp.back() == '.')
			tmp.pop_back();
	}


	// 7단계: 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입
	if (tmp.size() <= 2)
	{
		char plusChar = tmp.back();

		while (tmp.size() < 3)
			tmp.push_back(plusChar);
	}


	answer = tmp;

	return answer;
}