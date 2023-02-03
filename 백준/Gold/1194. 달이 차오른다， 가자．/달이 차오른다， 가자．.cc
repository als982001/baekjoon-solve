#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 51
using namespace std;

int N, M;
int startR, startC;
char map[MAX][MAX];
bool visited[MAX][MAX][64];
vector<pair<int, int>> endPoint;

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool Is_End(int r, int c) {

	for (int i = 0; i < endPoint.size(); ++i) {

		if (endPoint[i].first == r && endPoint[i].second == c)
			return true;
	}

	return false;
}

bool Is_In(int r, int c) {

	return N >= r && r >= 1 && M >= c && c >= 1;
}

int Key_Num(char key) {

	switch (key) {

	case 'a': 
	case 'A': {
		return 0;
		break;
	}
	case 'b':
	case 'B': {
		return 1;
		break;
	}
	case 'c': 
	case 'C': {
		return 2;
		break;
	}
	case 'd':
	case 'D': {
		return 3;
		break;
	}
	case 'e': 
	case 'E': {
		return 4;
		break;
	}
	case 'f': 
	case 'F': {
		return 5;
		break;
	}
	}
}

int BFS() {

	queue<pair<pair<int, int>, pair<int, int>>> q;		// 순서대로 좌표 r, 좌표 c, 소지 열쇠, 시간
	q.push(make_pair(make_pair(startR, startC), make_pair(0, 1)));
	visited[startR][startC][0] = true;

	
	while (!q.empty()) {

		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curKey = q.front().second.first;
		int curTime = q.front().second.second;
		q.pop();

		if (Is_End(curR, curC))
			return curTime - 1;

		for (int i = 0; i < 4; ++i) {

			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (!Is_In(nxtR, nxtC))
				continue;

			if (visited[nxtR][nxtC][curKey])
				continue;

			char nxtMap = map[nxtR][nxtC];

			if (nxtMap == '.' || nxtMap == '1' || nxtMap == '0') {

				visited[nxtR][nxtC][curKey] = true;
				q.push(make_pair(make_pair(nxtR, nxtC), make_pair(curKey, curTime + 1)));
			}
			else if ('a' <= nxtMap && nxtMap <= 'f') {

				int nxtKeyNum = (1 << Key_Num(nxtMap));
				int nxtKey = curKey | nxtKeyNum;

				visited[nxtR][nxtC][nxtKey] = true;
				q.push(make_pair(make_pair(nxtR, nxtC), make_pair(nxtKey, curTime + 1)));
			}
			else if ('A' <= nxtMap && nxtMap <= 'F') {

				int requiredKey = (1 << Key_Num(nxtMap));
				
				if (requiredKey & curKey) {

					visited[nxtR][nxtC][curKey] = true;
					q.push(make_pair(make_pair(nxtR, nxtC), make_pair(curKey, curTime + 1)));
				}
			}
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;

	for (int r = 1; r <= N; ++r) {

		for (int c = 1; c <= M; ++c) {

			cin >> map[r][c];

			if (map[r][c] == '0') {

				startR = r;
				startC = c;
			}
			else if (map[r][c] == '1')
				endPoint.push_back(make_pair(r, c));
		}
	}

	int answer = BFS();

	cout << answer << endl;

	return 0;
}