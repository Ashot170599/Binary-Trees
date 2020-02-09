#include <iostream>
#include <cassert>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

void printArray(int *arr,int arr_size)
{
	for(int index=0;index<arr_size;index++)
	cout<<*(arr+index)<<' ';
	cout<<endl;
}

void printPaths(Node *root,int *paths,int len)
{
	if(!root) return;
	paths[len++]=root->data;
	if(!root->left && !root->right) printArray(paths,len);
	else
	{
		printPaths(root->left,paths,len);
		printPaths(root->right,paths,len);
	}
	
}
int main(){
Node *a=new Node(5);
Node *b=new Node(9);
Node *c=new Node(6,a,b);
Node *d=new Node(10);
Node *e=new Node(7,NULL,d);
Node *root=new Node(1,c,e);

int *arr=new int[1000];
assert(arr);
printPaths(root,arr,0);
delete []arr;
return 0;
}
