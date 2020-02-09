#include <iostream>
#include <cassert>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int d,Node *l=NULL,Node* r=NULL):data(d),left(l),right(r){}
};

void sumArray(int *arr,int arr_size)
{
	int sum=0;
	for(int index=0;index<arr_size;index++)
	sum+=*(arr+index);
	cout<<sum<<endl;
}

void Paths(Node *root,int *paths,int len)
{
	if(!root) return;
	paths[len++]=root->data;
	if(!root->left && !root->right) sumArray(paths,len);
	else
	{
		Paths(root->left,paths,len);
		Paths(root->right,paths,len);
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
Paths(root,arr,0);
delete []arr;
return 0;
}
