#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 노드 타입형
typedef struct NODE
{
	int x;
	int y;
	int index;
	NODE* left;
	NODE* right;
} Node;

Node* rootNode;
vector<Node> nodes;
vector<int> preorder;
vector<int> postorder;

bool Compare(Node a, Node b)
{
	if (a.y > b.y) 
		return true;
	else if(a.y < b.y) 
		return false;
	else
	{
		if (a.x < b.x)
			return true;
		else
			return false;
	}
}

void MakeTree(Node* parentNode, Node* childNode)
{
	if (childNode->x < parentNode->x)
	{
		if (parentNode->left == NULL)
		{
			parentNode->left = childNode;
			return;
		}

		MakeTree(parentNode->left, childNode);
	}
	else if (parentNode->x < childNode->x)
	{
		if (parentNode->right == NULL)
		{
			parentNode->right = childNode;
			return;
		}

		MakeTree(parentNode->right, childNode);
	}
}

// 전위 순회를 하는 함수
void Preorder(Node* node)
{
	if (node == NULL)
		return;

	preorder.push_back(node->index);
	Preorder(node->left);
	Preorder(node->right);
}

// 후위 순회를 하는 함수
void Postorder(Node* node)
{
	if (node == NULL)
		return;

	Postorder(node->left);
	Postorder(node->right);
	postorder.push_back(node->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{	
	// 1. nodeinfo의 정보들을 더 자세히 하여 저장한다.
	for (int i = 0; i < nodeinfo.size(); ++i)
	{
		int x = nodeinfo[i][0];
		int y = nodeinfo[i][1];

		Node node;
		node.x = x;
		node.y = y;
		node.index = i + 1;
		node.left = NULL;
		node.right = NULL;

		nodes.push_back(node);
	}

	// 2. node들을 y, x 위치에 따라 정렬한다. (기준 1: y좌표가 클수록 앞으로. 기준 2: x좌표가 작을수록 앞으로)
	sort(nodes.begin(), nodes.end(), Compare);

	// 이 때, 가장 앞에 오는 노드가 root node이다. (가장 꼭대기에 있는 노드)
	rootNode = &nodes[0];

	// 3. 트리를 생성한다.
	for (int i = 1; i < nodes.size(); ++i)
		MakeTree(rootNode, &nodes[i]);
	
	// 각각의 순회 결과를 저장한다.
	Preorder(rootNode);
	Postorder(rootNode);

	return { preorder, postorder };
}