
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

void util(Node* root, int hd, int vd, map<int,pair<int,int>> &m)
{
	if (!root)
	{
		return;
	}
	if (m.find(hd)!=m.end())
	{
		if (m[hd].first>vd)
		{
			m[hd] = {vd,root->data};
		}
	}
	else
		m[hd] = {vd,root->data};
	
	
	util(root->left, hd-1,vd +1, m);
	util(root->right, hd+1, vd+ 1,m);
}
void topView(Node* root)
{
	map<int, pair<int,int>> m;
	util(root,0,0,m);
	
	for(auto x:m)
	{
		cout<<x.second.second<<' ';
	}
	
}

int main() 
{ 
	 Node *root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(5); 
    root->left->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(25); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14);

	topView(root); 

	return 0; 
} 



