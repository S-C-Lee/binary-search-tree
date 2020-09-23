#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define size 10000
typedef struct {
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* push(Node* root, int data)
{
	if (!root)
	{
		root = malloc(sizeof(Node));
		root->data = data;
		root->right = NULL;
		root->left = NULL;
	}
	else {
		if (root->data > data) root->left = push(root->left, data);
		else root->right = push(root->right, data);
	}
	return root;
}
Node* search(Node* root, int data)
{
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	else if (root->data > data) search(root->left, data);
	else search(root->right, data);
}
preorder(Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
Node* findmin(Node* root) {
	Node* cur = root;
	while (cur -> left != NULL)
	{
		cur = cur->left;
	}
	return cur;
}
Node* pop(Node* root, int data)
{
	Node* node = NULL;
	if (root == NULL) return NULL;
	if (root->data > data) root->left = pop(root->left, data);
	else if (root->data < data) root->right = pop(root->right, data);
	else {
		if (root->left != NULL && root->right != NULL)
		{
			node = findmin(root->right);
			root->data = node->data;
			root->right = pop(root->right, node->data);
		}
		else {
			node = (root->left != NULL) ? root->left : root->right;
			free(root);
			return node;
		}
	}
	return root;
}
int main()
{
	Node* root = NULL;
	root = push(root, 30);
	root = push(root, 17);
	root = push(root, 48);
	root = push(root, 5);
	root = push(root, 23);
	root = push(root, 37);
	root = push(root, 50);
	root =pop(root, 30);
	preorder(root);

}