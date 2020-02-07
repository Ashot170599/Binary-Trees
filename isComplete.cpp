#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

int countNodes(Node *root){
if(!root) return 0;
return 1+countNodes(root->left)+countNodes(root->right);
}

bool isComplete(Node *root,int index,int count)
{
 if(!root) return true;
 if(index>=count) return false;
 return (isComplete(root->left,index*2+1,count) && isComplete(root->right,index*2+2,count));
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *f=new Node(3);
Node *e=new Node(7,f,d);
Node *root=new Node(1,c,e);
int count=countNodes(root);
cout<<((isComplete(root,0,count))?"yes":"no")<<endl;
return 0;
}
