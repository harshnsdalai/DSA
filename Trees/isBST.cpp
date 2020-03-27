
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

void util(Node* root, vector<int> &v)
{
	if (!root)
	{
		return;
	}
	util(root->left,v);
	v.push_back(root->data);
	util(root->right,v);

}

bool isBST(Node* root) {
    vector<int> v;
    util(root,v);
    int min = INT_MIN;
    bool flag = true;
    for(auto x:v)
    {
    	if (x<=min)
    	{
    		flag = false;
    		break;
    	}
    	min = x;
    }
    return flag;

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

	cout<<isBST(root); 

	return 0; 
} 



