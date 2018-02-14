/*
L2-011. ��ת������
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
����һ�ö����������������ǰ������������Ƚ����������淴ת���������ת��Ĳ�����������С�
��ν���淴ת����ָ�����з�Ҷ�������Һ��ӶԻ�����������ֵ���ǻ�����ȵ���������

�����ʽ��
�����һ�и���һ��������N��<=30�����Ƕ������н��ĸ������ڶ��и���������������С�������
������ǰ��������С����ּ��Կո�ָ���

�����ʽ��
��һ�������������ת��Ĳ�����������С����ּ���1���ո�ָ�������β�����ж���ո�

����������
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7

���������
4 6 1 7 5 3 2

����˼·��
���ȸ��������ǰ�����лָ�����������
Ȼ��Ըö��������о������ 
�����в�����������������С�
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
	for(i=0;ldr[i]!=lrd[n-1] && i<n ;++i);//i��ldr�ж�λ�������
	//ȷ�������� 
	p = ldr;
	q = lrd;
	rt->left = recover(p,q,i);
	//ȷ��������
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
	for(i=0;ldr[i]!=dlr[0] && i<n ;++i);//i��ldr�ж�λ�������
	//�ݹ�ָ������� 
	rt->left = recover(ldr,dlr+1,i);
	//�ݹ�ָ�������
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
//������ת������ 
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
	for(int i=0;i<N;++i)//��������������� 
		scanf("%d",ldr+i);
	for(int i=0;i<N;++i)//����ǰ��������� 
		scanf("%d",dlr+i);
	
	BinTree tree(ldr,dlr,N);
	tree.rotate();
	vector<int> v;
	tree.levelOrder(v);
	copy(v.begin(),--v.end(),ostream_iterator<int>(cout," "));
	cout<<*(--v.end())<<endl;
	
	return 0;
}
