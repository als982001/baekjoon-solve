#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

int N, parent, removedNode, rootNode;
vector<int> tree[MAX];

int Solve(int curNode) {

	if (curNode == removedNode)
		return 0;

	int curChildNum = tree[curNode].size();

	if (curChildNum == 0 || (curChildNum == 1 && tree[curNode][0] == removedNode))
		return 1;

	int leafNode = 0;

	for (int idx = 0; idx < curChildNum; ++idx)
	{
		leafNode += Solve(tree[curNode][idx]);
	}

	return leafNode;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int idx = 0; idx < N; ++idx) {
		cin >> parent;

		if (parent == -1)
			rootNode = idx;
		else
			tree[parent].push_back(idx);
	}

	cin >> removedNode;

	cout << Solve(rootNode) << endl;

	return 0;
}