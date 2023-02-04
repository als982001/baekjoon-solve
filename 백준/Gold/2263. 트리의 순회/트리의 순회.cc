#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
int inorder[MAX];
int postorder[MAX];
int index[MAX];

void Preorder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {

	if (inorderStart > inorderEnd || postorderStart > postorderEnd)
		return;

	int rootNode = postorder[postorderEnd];
	int rootIdx = index[rootNode];

	cout << rootNode << " ";

	int leftSize = rootIdx - inorderStart;
	int rightSize = inorderEnd - rootIdx;

	Preorder(inorderStart, rootIdx - 1, postorderStart, postorderStart + leftSize - 1);
	Preorder(rootIdx + 1, inorderEnd, postorderStart + leftSize, postorderEnd - 1);

}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {

		cin >> inorder[i];
		index[inorder[i]] = i;
	}

	for (int i = 1; i <= N; ++i)
		cin >> postorder[i];

	Preorder(1, N, 1, N);

	return 0;
}