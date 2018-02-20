/*
1020. Tree Traversals (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Suppose that all the keys in a binary tree are distinct positive integers. Given 
the postorder and inorder traversal sequences, you are supposed to output the 
level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a 
positive integer N (<=30), the total number of nodes in the binary tree. The 
second line gives the postorder sequence and the third line gives the inorder 
sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the level order traversal sequence of the 
corresponding binary tree. All the numbers in a line must be separated by exactly 
one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2

题目大意：
给定二叉树的后序遍历序列和中序遍历序列，输出该二叉树的层序遍历序列。 

解题思路：
首先根据后序和中序重建出该二叉树，然后用队列遍历并输出其层序遍历序列。 
*/ 
#include<iostream>
#include<string>
#include<queue>
#define maxn 35
using namespace std;

struct Node{
	int value;
	Node *left, *right;
	Node(int v, Node* left=0, Node* right=0)
	:value(v),left(left),right(right){}
};

/*用后序和中序重建二叉树： 
* 后序中最后一个元素即为根结点，而根结点在中序序列的中间某个位置，该位置
* 左边为左子树的中序遍历序列，右边为右子树的中序遍历序列。假设根结点在
* 中序序列中的第k个位置，则0~k-1位左子树的中序遍历序列，k+1~n-1为右子树的
* 中序遍历序列。在后续遍历序列中，0~k-1为左子树的后边遍历序列，k~n-2为右
* 子树的后序遍历序列，n-1为根节点。用这些信息即可递归构建出整个二叉树。
*/ 
Node* makeTree(int* pos,int* in, int n){
	if(n==0)return 0;
	Node *root = new Node(pos[n-1]);
	int k = n-1;
	while(k>0 && in[k] != pos[n-1]) --k;
	root->left = makeTree(pos,in,k);
	root->right = makeTree(pos+k,in+k+1,n-k-1);
	return root;
}


void levelOrder(Node* rt){
	if(rt == 0) return ;
	queue<Node*> Q;
	Q.push(rt);
	bool isFirst = true;
	while(!Q.empty()){
		Node* r = Q.front(); 
		Q.pop();
		if(isFirst){
			cout<<r->value;
			isFirst = false;
		}else{
			cout<<" "<<r->value;
		}
		if(r->left)  Q.push(r->left);
		if(r->right) Q.push(r->right);
	}
}

int main(){
#ifdef WFX
freopen("1020 in.txt","r",stdin);
#endif
	int pos[maxn],in[maxn];
	int n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>pos[i];
	for(int i=0;i<n;++i) cin>>in[i];
	
	Node* root = makeTree(pos,in,n);
	levelOrder(root);
	
	return 0;
}

