#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;

int N, M;
int arr[MAX];
vector<int> answer;
vector<int> segmentTree;
vector<pair<int, int>> intervals;

int Init(int node, int start, int end) {

	if (start == end)
		return segmentTree[node] = arr[start];

	int mid = (start + end) / 2;

	int leftResult = Init(node * 2, start, mid);
	int rightResult = Init(node * 2 + 1, mid + 1, end);

	return segmentTree[node] = leftResult + rightResult;
}

void Make_Segment_Tree() {

	int treeHeight = (int)ceil(log2(N));
	int treeSize = 1 << (treeHeight + 1);

	segmentTree.resize(treeSize);

	Init(1, 1, N);
}

int Sum(int node, int start, int end, int intervalLeft, int intervalRight) {

	if (start > intervalRight || end < intervalLeft)
		return 0;

	if (intervalLeft <= start && end <= intervalRight)
		return segmentTree[node];

	int mid = (start + end) / 2;

	int leftSum = Sum(node * 2, start, mid, intervalLeft, intervalRight);
	int rightSum = Sum(node * 2 + 1, mid + 1, end, intervalLeft, intervalRight);

	return leftSum + rightSum;
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;
	for (int idx = 1; idx <= N; ++idx)
		cin >> arr[idx];

	for (int idx = 0; idx < M; ++idx) {

		int curStart, curEnd;
		cin >> curStart >> curEnd;

		intervals.push_back(make_pair(curStart, curEnd));
	}


	Make_Segment_Tree();

	for (int i = 0; i < M; ++i) {

		int curStart = intervals[i].first;
		int curEnd = intervals[i].second;

		int curAnswer = Sum(1, 1, N, curStart, curEnd);
		answer.push_back(curAnswer);
	}

	for (int i = 0; i < M; ++i)
		printf("%d\n", answer[i]);


	return 0;
}