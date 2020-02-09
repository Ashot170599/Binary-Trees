#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

void printLeaves(Node *root)
{
	if(root)
	{
		if(!root->left && !root->right) cout<<root->data<<endl;
		printLeaves(root->left);
		printLeaves(root->right);
	}
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(2);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
printLeaves(root);
return 0;
}
