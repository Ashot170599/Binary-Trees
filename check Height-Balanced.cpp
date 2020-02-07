#include <iostream>
#include <cmath>
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
bool isheightBalanced(Node *root)
{
	if(!root) return true;
	if(!root->left && !root->right) return true;
	int lh=height(root->left);
	int rh=height(root->right);
	if(abs(lh-rh)<=1 && isheightBalanced(root->left) && isheightBalanced(root->right)) return true;
	return false;
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
cout<<((isheightBalanced(root))?"yes":"no")<<endl;
return 0;
}
