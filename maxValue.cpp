#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

int max(int a,int b)
{
 return (a>b)?a:b;
}

int maxValue(Node *root)
{
	if(!root) return 0;
	return max(max(maxValue(root->left),maxValue(root->right)),root->data);
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
cout<<maxValue(root)<<endl;
return 0;
}
