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
void mostleft_longest_path(Node *root)
{
	if(root)
	{
		cout<<root->data<<' ';
		if(height(root->left)>=height(root->right)) mostleft_longest_path(root->left);
		else mostleft_longest_path(root->right);
	}
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
mostleft_longest_path(root);
return 0;
}
