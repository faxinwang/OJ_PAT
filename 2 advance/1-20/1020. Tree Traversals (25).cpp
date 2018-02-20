/*
1020. Tree Traversals (25)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
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

��Ŀ���⣺
�����������ĺ���������к�����������У�����ö������Ĳ���������С� 

����˼·��
���ȸ��ݺ���������ؽ����ö�������Ȼ���ö��б�������������������С� 
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

/*�ú���������ؽ��������� 
* ���������һ��Ԫ�ؼ�Ϊ����㣬����������������е��м�ĳ��λ�ã���λ��
* ���Ϊ������������������У��ұ�Ϊ������������������С�����������
* ���������еĵ�k��λ�ã���0~k-1λ������������������У�k+1~n-1Ϊ��������
* ����������С��ں������������У�0~k-1Ϊ�������ĺ�߱������У�k~n-2Ϊ��
* �����ĺ���������У�n-1Ϊ���ڵ㡣����Щ��Ϣ���ɵݹ鹹����������������
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

