#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};
int sum_evens(Node *root){
if(!root) return 0;
if(root->data%2==0) 
   return root->data+sum_evens(root->left)+sum_evens(root->right);
else
    return sum_evens(root->left)+sum_evens(root->right);
}
int sum_odds(Node *root){
if(!root) return 0;
if(root->data%2!=0) 
   return root->data+sum_odds(root->left)+sum_odds(root->right);
else
    return sum_odds(root->left)+sum_odds(root->right);
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);
cout<<sum_evens(root)<<endl;
cout<<sum_odds(root)<<endl;
return 0;
}
