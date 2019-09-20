#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

int main()
{
    struct node *root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);

}
