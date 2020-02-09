#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};
void pre_order(Node *root)
{
	if(root)
	{
		cout<<root->data<<' ';
		pre_order(root->left);
	    pre_order(root->right);
	}
}
void in_order(Node *root)
{
	if(root)
	{
		in_order(root->left);
		cout<<root->data<<' ';
	    in_order(root->right);
	}
}
void post_order(Node *root)
{
	if(root)
	{
		post_order(root->left);
	    post_order(root->right);
	    cout<<root->data<<' ';
	}
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(2);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
pre_order(root);
cout<<endl;
in_order(root);
cout<<endl;
post_order(root);
return 0;
}
