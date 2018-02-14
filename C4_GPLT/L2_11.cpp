/*
L2-011. 玩转二叉树
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。
所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（<=30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行
给出其前序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7

输出样例：
4 6 1 7 5 3 2

解题思路：
首先根据中序和前序序列恢复出二叉树，
然后对该二叉树进行镜像操作 
最后进行层序遍历输出其层序序列。
*/
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
