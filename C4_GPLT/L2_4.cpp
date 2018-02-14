/*
L2-004. ���Ƕ�����������
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
һ�ö����������ɱ��ݹ�ض���Ϊ�����������ʵĶ�������������һ��㣬

�������������н��ļ�ֵС�ڸý��ļ�ֵ��
�������������н��ļ�ֵ���ڵ��ڸý��ļ�ֵ��
�������������Ƕ�����������
��ν�����������ġ����񡱣��������н������������Ի�λ�ú����õ�������

����һ��������ֵ���У��������д�����ж����Ƿ��Ƕ�һ�ö������������侵�����ǰ������Ľ����

�����ʽ��
����ĵ�һ�и���������N��<=1000�������һ�и���N��������ֵ������Կո�ָ���

�����ʽ��
������������Ƕ�һ�ö������������侵�����ǰ������Ľ������������һ���������YES����Ȼ��
����һ�����������������Ľ�������ּ���1���ո�һ�е���β�����ж���ո������Ƿ��������NO����

��������1��
7
8 6 5 7 10 8 11

�������1��
YES
5 7 6 8 11 10 8

��������2��
7
8 10 11 8 6 7 5

�������2��
YES
11 8 10 7 5 6 8

��������3��
7
8 6 8 5 10 9 11

�������3��
NO
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class BSTree{
	private:
		struct Node{
			int data;
			Node *left,*right;
			Node(int d,Node* l=0,Node* r=0):data(d),left(l),right(r){}
		}*root;
	public:
		BSTree():root(0){}
		~BSTree(){clear(root);}
		void clear(Node*);
		void insert(int x){insert(root,x);}
		void insert(Node* &rt,int x);
		void LRD(vector<int>& lrd){ LRD(root,lrd); }
		void LRD(Node* rt,vector<int>&);
		
		void DLR(vector<int>& dlr){ DLR(root,dlr); }
		void DLR(Node* rt,vector<int>&);
		
		void DRL(vector<int>& drl){ DRL(root,drl); }
		void DRL(Node* rt,vector<int>&);
		
		void rotate(){rotate(root);}
		void rotate(Node*rt);
};
void BSTree::clear(Node* rt){
	if(rt){
		clear(rt->left);
		clear(rt->right);
		delete rt;
	}
}
void BSTree::insert(Node* &rt,int x){
	if(rt==0){
		rt = new Node(x);
		return;
	}
	if( x < rt->data){
		insert(rt->left,x);
	}else{
		insert(rt->right,x);
	}
}
void BSTree::LRD(Node* rt, vector<int>& lrd){
	if(rt){
		LRD(rt->left,lrd);
		LRD(rt->right,lrd);
		lrd.push_back(rt->data);
	}
}
void BSTree::DLR(Node* rt, vector<int>& dlr){
	if(rt){
		dlr.push_back(rt->data);
		DLR(rt->left,dlr);
		DLR(rt->right,dlr);
	}
}
void BSTree::DRL(Node* rt,vector<int>& drl){
	if(rt){
		drl.push_back(rt->data);
		DRL(rt->right,drl);
		DRL(rt->left,drl);
	}
}
void BSTree::rotate(Node* rt){
	if(rt==0) return ;
	rotate(rt->left);
	rotate(rt->right);
	Node* tmp = rt->left;
	rt->left = rt->right;
	rt->right = tmp; 
}

int main(){
	vector<int> data,dlr,drl,lrd;
	int n,tmp;
	
	BSTree tree;
	scanf("%d",&n);
	for(int i=0;i<n;++i) {
		scanf("%d",&tmp);
		data.push_back(tmp);
		tree.insert(tmp);
	}
	tree.DLR(dlr);
	tree.DRL(drl);
/*
	cout<<endl;
	copy(dlr.begin(),dlr.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	copy(drl.begin(),drl.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
*/		
	if(data==dlr){
		cout<<"YES"<<endl;
		tree.LRD(lrd);
		copy(lrd.begin(),--lrd.end(),ostream_iterator<int>(cout," "));
		cout<<*(--lrd.end())<<endl;
	}else if(data==drl){
		cout<<"YES"<<endl;
		tree.rotate();
		tree.LRD(lrd);
		copy(lrd.begin(),--lrd.end(),ostream_iterator<int>(cout," "));
		cout<<*(--lrd.end())<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}
