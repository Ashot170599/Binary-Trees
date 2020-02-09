#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};
int height(Node *root){
if(!root) return -1;
return max(height(root->left),height(root->right))+1;
}

bool checkLevel(Node *root,int level){
if(!root) return false;
if(!level) return true;
 return checkLevel(root->left,level-1)&& checkLevel(root->right,level-1);
}
bool checkLevelsAreFilled(Node *root)
{
	int h=height(root);
	for(int l=0;l<=h;l++)
    if(!checkLevel(root,l)) return false;
    return true;
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(2);
//Node *dd=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
 cout<<((checkLevelsAreFilled(root))?"yes":"no")<<endl;
return 0;
}
