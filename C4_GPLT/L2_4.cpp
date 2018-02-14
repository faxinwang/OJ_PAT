/*
L2-004. 这是二叉搜索树吗？
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
一棵二叉搜索树可被递归地定义为具有下列性质的二叉树：对于任一结点，

其左子树中所有结点的键值小于该结点的键值；
其右子树中所有结点的键值大于等于该结点的键值；
其左右子树都是二叉搜索树。
所谓二叉搜索树的“镜像”，即将所有结点的左右子树对换位置后所得到的树。

给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。

输入格式：
输入的第一行给出正整数N（<=1000）。随后一行给出N个整数键值，其间以空格分隔。

输出格式：
如果输入序列是对一棵二叉搜索树或其镜像进行前序遍历的结果，则首先在一行中输出“YES”，然后
在下一行输出该树后序遍历的结果。数字间有1个空格，一行的首尾不得有多余空格。若答案是否，则输出“NO”。

输入样例1：
7
8 6 5 7 10 8 11

输出样例1：
YES
5 7 6 8 11 10 8

输入样例2：
7
8 10 11 8 6 7 5

输出样例2：
YES
11 8 10 7 5 6 8

输入样例3：
7
8 6 8 5 10 9 11

输出样例3：
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
