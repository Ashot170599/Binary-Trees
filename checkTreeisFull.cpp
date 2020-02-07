#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};
bool isFull(Node *root)
{
	if(!root) return true;
	if(!root->left && !root->right) return true;
	if(root->left && root->right) return isFull(root->left) && isFull(root->right);
	return false;	
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *f=new Node(3);
Node *e=new Node(7,f,d);
Node *root=new Node(1,c,e);
cout<<((isFull(root))?"yes":"no")<<endl;
return 0;
}
