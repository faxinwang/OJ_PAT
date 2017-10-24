#include<iostream>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;

class BinTree{
	public:
		struct Node{
			int data;
			Node *left,*right;
			Node(int d,Node* l=0,Node* r=0):data(d),left(l),right(r){}
		} *root;
		BinTree(int* ldr,int* lrd,int n){
			root = recover(ldr,lrd,n);
		}
		~BinTree(){clear(root);}
		void clear(Node*);
		Node* recover(int* ldr,int* lrd,int n);
		void levelOrder(vector<int>& v);
};
void BinTree::clear(Node* r){
	if(r){
		clear(r->left);
		clear(r->right);
		delete r;
	}
}
typename BinTree::Node* BinTree::recover(int* ldr,int* lrd,int n){
	if(n==0) return 0;
	Node* rt = new Node(lrd[n-1]);
	int *p,*q,i;
	for(i=0;ldr[i]!=lrd[n-1] && i<n ;++i);//i在ldr中定位到根结点
	//确定左子树 
	p = ldr;
	q = lrd;
	rt->left = recover(p,q,i);
	//确定右子树
	p = ldr+i+1;
	q = lrd+i;
	rt->right = recover(p,q,n-i-1);
	return rt;
}
void BinTree::levelOrder(vector<int>& v){
	queue<Node*> q;
	if(root)
		q.push(root);
	while(!q.empty()){
		Node* rt = q.front();
		q.pop();
		v.push_back(rt->data);
		if(rt->left) q.push(rt->left);
		if(rt->right) q.push(rt->right);
	}
}

int main(){
	int N,lrd[30],ldr[30];
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d",lrd+i);
	for(int i=0;i<N;++i)
		scanf("%d",ldr+i);
	
	BinTree tree(ldr,lrd,N);
	vector<int> v;
	tree.levelOrder(v);
	copy(v.begin(),--v.end(),ostream_iterator<int>(cout," "));
	cout<<*(--v.end())<<endl;
	
	return 0;
}
