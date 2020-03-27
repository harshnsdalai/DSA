
#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

struct Node* newNode(int data) 
{ 
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node)); 
	
	Node->data = data; 
	Node->left = Node->right = NULL; 

	return Node; 
} 
void util(Node* root, int hd, int vd, map<int, vector<int>> &m)
{
	if (!root)
	{
		return;
	}

	m[hd].push_back(root->data);

	
	util(root->left, hd-1,vd +1, m);
	util(root->right, hd+1, vd+ 1,m);
}
void verticaltraversal(Node* root)
{
	map<int, vector<int>> m;
	util(root,0,0,m);
	for(auto x:m)
	{
		for(auto y:x.second)
		{
			cout<<y<<' ';
		}
		cout<<endl;
	}
}

int main() 
{ 
	 Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 

	verticaltraversal(root); 

	return 0; 
} 


