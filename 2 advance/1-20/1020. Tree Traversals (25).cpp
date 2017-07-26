#include<iostream>
#include<string>
#include<queue>
#define maxn 35
using namespace std;

struct Node{
	int value;
	Node *left, *right;
	Node(char v, Node* left=0, Node* right=0)
	:value(v),left(left),right(right){}
};


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

