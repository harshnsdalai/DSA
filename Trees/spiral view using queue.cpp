
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


void spiralView(Node* root)
{
	queue<Node*> q;
	q.push(root);
	vector<vector<int>> v1;
	int x = 1;
	while(!q.empty())
	{
		int no_of_nodes_in_level = q.size();
		vector<int> v2;
		
		while(no_of_nodes_in_level!=0)

		{	
			

			Node* head = q.front();
			v2.push_back(head->data);
			no_of_nodes_in_level--;
			if(head->left)
				q.push(head->left);
			if(head->right)
				q.push(head->right);
			q.pop();

		}
		if (x)
		{
			//cout<<"its happening";
			reverse(v2.begin(), v2.end());
		}
		
		v1.push_back(v2);
		x^=1;

	}
	for(auto x: v1)
	{
		for(auto y: x)
		{
			cout<<y<<" ";
		}
	}
	
}

int main() 
{ 
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4);

	spiralView(root); 

	return 0; 
} 



