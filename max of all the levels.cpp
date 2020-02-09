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
int maxOnLevel(Node *root,int level){
if(!root) return 0;
if(!level) return root->data;
return max(maxOnLevel(root->left,level-1),maxOnLevel(root->right,level-1));
}
void printMaxsOnLevels(Node *root)
{
	int h=height(root);
	for(int l=0;l<=h;l++)
    cout<< maxOnLevel(root,l)<<endl;
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(2);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
printMaxsOnLevels(root);
return 0;
}
