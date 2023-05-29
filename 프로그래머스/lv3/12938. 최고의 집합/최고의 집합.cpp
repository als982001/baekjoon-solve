#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s)
        return { -1 };
    
    int val = s / n;
    answer.resize(n, val);
    
    int rest = s % n;
    
    for (int r = answer.size() - 1; r >= answer.size() - rest; --r)
        ++answer[r];
    
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
   vector<int> answer;

	if (n > s)
		return { -1 };

	int num = s / n;
	int r = s % n;

	for (int i = 0; i < n; ++i)
		answer.push_back(num);

	for (int idx = answer.size() - 1, t = 0; t < r; ++t, --idx)
		++answer[idx];
	
    return answer;
}
*/