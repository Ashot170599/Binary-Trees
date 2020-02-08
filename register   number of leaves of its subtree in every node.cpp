#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

int writeLeafs(Node *root)
{
	if(!root) return 0;
	if(!root->left && !root->right)
	     root->data=1;
	else root->data=writeLeafs(root->left)+writeLeafs(root->right);
	return root->data;
}
void pre_order(Node *root)
{
	if(root)
	{
		cout<<root->data<<' ';
		pre_order(root->left);
	    pre_order(root->right);
	}
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
writeLeafs(root);
pre_order(root);
return 0;
}
