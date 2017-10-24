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
