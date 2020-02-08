#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

int min(int a,int b)
{
 return (a>b)?b:a;
}
int fixMin(Node *root)
{
	if(!root) return INT_MAX;
	if(!root->left && !root->right ) return root->data;
	else 
	{
	root->data=min(min(fixMin(root->left),fixMin(root->right)),root->data);
	return root->data;
   }
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
fixMin(root);
pre_order(root);
return 0;
}
