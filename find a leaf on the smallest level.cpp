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

int height(Node *root){
if(!root) return -1;
return max(height(root->left),height(root->right))+1;
}

void nearestLeaf(Node *root)
{
  if(root)	
  {
  	if(!root->left && !root->right)
  	cout<<"The nearest leaf is : "<<root->data<<endl;
  	if(height(root->left)<=height(root->right))
  	     nearestLeaf(root->left);
  	else
  	     nearestLeaf(root->right);
  }
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
//Node *d=new Node(10);
Node *e=new Node(7,NULL,NULL);
Node *root=new Node(1,c,e);
nearestLeaf(root);
return 0;
}
