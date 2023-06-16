#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

typedef struct NODE {
    NODE* prev;
    NODE* next;
    int data;
    
    NODE(int _data): data(_data) {
        prev = NULL;
        next = NULL;
    }
} Node;

typedef struct LINKEDLIST {
    Node* head;
    Node* tail;
    
    LINKEDLIST(): head(NULL), tail(NULL) {}
    
    void Insert(int n);
    Node* Remove(Node* node);
    void Restore(Node* node);
} LinkedList;

void LinkedList::Insert(int n) {
    Node* newNode = new Node(n);
    
    if (this->head == NULL) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
    }
}

Node* LinkedList::Remove(Node* node) {
    if (this->head == node) {
        node->next->prev = NULL;
        this->head = node->next;
        
        return node->next;
    } else if (this->tail == node) {
        node->prev->next = NULL;
        this->tail = node->prev;
        
        return node->prev;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        return node->next;
    }
}

void LinkedList::Restore(Node* node) {
    if (node->prev == NULL) {
        this->head->prev = node;
        this->head = node;
    } else if (node->next == NULL) {
        this->tail->next = node;
        this->tail = node;
    } else {
        node->next->prev = node;
        node->prev->next = node;
    }
}

LinkedList* list;
stack<Node*> stk;

void MakeLinkedList(int n)
{
    list = new LinkedList();
    
    for (int i = 0; i < n; ++i)
        list->Insert(i);
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    MakeLinkedList(n);
    
    Node* iter = list->head;
    
    for (int i = 0; i < k; ++i)
        iter = iter->next;
    
    for (int i = 0; i < cmd.size(); ++i)
    {
        string curCmd = cmd[i];
            
        char cmdType = curCmd[0];
        
        switch (curCmd[0])
        {
        case 'U':
        {
            int movingTurn = stoi(curCmd.substr(2));

            for (int m = 0; m < movingTurn; ++m)
                iter = iter->prev;

            break;
        }
        case 'D':
        {
            int movingTurn = stoi(curCmd.substr(2));

            for (int m = 0; m < movingTurn; ++m)
                iter = iter->next;

            break;
        }
        case 'C':
        {
            stk.push(iter);
            iter = list->Remove(iter);

            break;
        }
        case 'Z':
        {
            Node* restored = stk.top();
            stk.pop();

            list->Restore(restored);

            break;
        }
        }
    }
    
    for (int i = 0; i < n; ++i)
        answer += "O";
    
    while(!stk.empty())
    {
        Node* restored = stk.top();
        stk.pop();
        
        answer[restored->data] = 'X';
    }
    
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef struct NODE {
    NODE* prev;
    NODE* next;
    int data;

    NODE(int n)
    {
        data = n;
        prev = NULL;
        next = NULL;
    }
} node;

typedef struct LinkedList {
    NODE* head;
    NODE* tail;

    LinkedList() : head(NULL), tail(NULL) {}
    void Insert(int n);
    NODE* Delete(node* nd);
    void Restore(node* nd);
}linkedlist;

void LinkedList::Insert(int n)
{
    if (this->head == NULL)
    {
        node* newNode = new node(n);
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        node* newNode = new node(n);
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = this->tail->next;
    }
}

NODE* LinkedList::Delete(node* nd)
{
    if (nd == this->head)
    {
        nd->next->prev = NULL;
        this->head = nd->next;

        return nd->next;
    }
    else if (nd == this->tail)
    {
        nd->prev->next = NULL;
        this->tail = nd->prev;

        return this->tail;
    }
    else
    {
        nd->prev->next = nd->next;
        nd->next->prev = nd->prev;

        return nd->next;
    }
}

void LinkedList::Restore(node* nd)
{
    if (nd->prev == NULL)
    {
        this->head->prev = nd;
        this->head = nd;
    }
    else if (nd->next == NULL)
    {
        this->tail->next = nd;
        this->tail = nd;
    }
    else
    {
        nd->prev->next = nd;
        nd->next->prev = nd;
    }
}

LinkedList* list;
stack<node*> deleted;

void Make_LinkedList(int n)
{
    list = new LinkedList();

    for (int i = 0; i < n; ++i)
        list->Insert(i);
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    Make_LinkedList(n);
    node* iter = list->head;

    for (int i = 0; i < k; ++i)
        iter = iter->next;


    for (int i = 0; i < cmd.size(); ++i)
    {
        string curCmd = cmd[i];

        switch (curCmd[0])
        {
        case 'U':
        {
            int movingTurn = stoi(curCmd.substr(2));

            for (int m = 0; m < movingTurn; ++m)
                iter = iter->prev;

            break;
        }
        case 'D':
        {
            int movingTurn = stoi(curCmd.substr(2));

            for (int m = 0; m < movingTurn; ++m)
                iter = iter->next;

            break;
        }
        case 'C':
        {
            deleted.push(iter);
            iter = list->Delete(iter);

            break;
        }
        case 'Z':
        {
            node* restored = deleted.top();
            deleted.pop();

            list->Restore(restored);

            break;
        }
        }
    }

    for (int i = 0; i < n; ++i)
        answer += "O";

    while (!deleted.empty())
    {
        node* deletedNode = deleted.top();
        deleted.pop();

        int deletedIdx = deletedNode->data;

        answer[deletedIdx] = 'X';

    }

    return answer;
}
*/