#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

bool isBST(Node *root)
{
	static Node* prev=NULL;
	if(root)
	{
		if(!isBST(root->left)) return false;
		if(prev!=NULL && prev->data>=root->data) return false;
		prev=root;
		return isBST(root->right);
	}
	return true;
}

int main(){
Node *a=new Node(5);
Node *b=new Node(7);
Node *c=new Node(6,a,b);
Node *d=new Node(12);
Node *e=new Node(11,NULL,d);
Node *root=new Node(9,c,e);
cout<<((isBST(root))?"yes":"no")<<endl;
return 0;
}
