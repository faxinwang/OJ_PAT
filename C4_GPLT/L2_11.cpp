#include<iostream>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;

class BinTree{
	private:
		struct Node{
			int data;
			Node *left,*right;
			Node(int d,Node* l=0,Node* r=0):data(d),left(l),right(r){}
		} *root;
	public:
		BinTree(int* ldr,int* dlr,int n){
			root = recover(ldr,dlr,n);
		}
		~BinTree(){clear(root);}
		void clear(Node*);
		Node* recover(int* ldr,int* lrd,int n);
		void levelOrder(vector<int>& v);
		void rotate(Node*);
		void rotate(){rotate(root);}
};
void BinTree::clear(Node* r){
	if(r){
		clear(r->left);
		clear(r->right);
		delete r;
	}
}
/*
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
*/
typename BinTree::Node* BinTree::recover(int* ldr,int* dlr,int n){
	if(n<=0) return 0;
	Node* rt = new Node(dlr[0]);
	int i;
	for(i=0;ldr[i]!=dlr[0] && i<n ;++i);//i在ldr中定位到根结点
	//递归恢复左子树 
	rt->left = recover(ldr,dlr+1,i);
	//递归恢复右子树
	rt->right = recover(ldr+i+1,dlr+i+1,n-i-1);
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
//镜像旋转二叉树 
void BinTree::rotate(Node* rt){
	if(rt==0) return;
	if(rt->left) rotate(rt->left);
	if(rt->right) rotate(rt->right);
	Node* tmp = rt->left;
	rt->left = rt->right;
	rt->right = tmp;
}

int main(){
	int N,dlr[30],ldr[30];
	scanf("%d",&N);
	for(int i=0;i<N;++i)//输入中序遍历序列 
		scanf("%d",ldr+i);
	for(int i=0;i<N;++i)//输入前序遍历序列 
		scanf("%d",dlr+i);
	
	BinTree tree(ldr,dlr,N);
	tree.rotate();
	vector<int> v;
	tree.levelOrder(v);
	copy(v.begin(),--v.end(),ostream_iterator<int>(cout," "));
	cout<<*(--v.end())<<endl;
	
	return 0;
}
