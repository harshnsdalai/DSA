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
void printCousins(Node* root, int k)
{
	queue<Node*> q;
	q.push(root);
	bool node_found = false;
	while(!q.empty())
	{
		
		int size = q.size();
		//int curr_sum = 0;

		while(size--)
		{
			Node* curr = q.front();
			q.pop();
			if (curr->left->data==k || curr->right->data==k)
			{	//cout<<curr->data<<"hi"<<endl;
				node_found = true;
				continue;
			}
			if (curr->left)
			{
				//curr_sum+=curr->left->data;
				q.push(curr->left);
			}
			if (curr->right)
			{
				//curr_sum+=curr->right->data;
				q.push(curr->right);
			}
			//cout<<curr_sum<<"fox"<<endl;
		}
		if (node_found)
		{
			if (q.empty())
			{
				cout<<"NOT FOUND"<<endl;
			}
			while(!q.empty())
			{
				cout<<q.front()->data<<" ";
				q.pop();
			}
			return;
		}
	}
	
}
int main()
{
	
   struct Node* root = newNode(1); 
    root->left = newNode(3); 
    root->right = newNode(7); 
    root->left->left = newNode(6); 
    root->left->right = newNode(5); 
    root->left->right->left = newNode(10); 
    root->right->left = newNode(4); 
    root->right->right = newNode(13); 
    root->right->left->left = newNode(17); 
    root->right->left->right = newNode(15); 
  
    printCousins(root, 7);
	return 0;
}