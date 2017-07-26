#include<iostream> 
using namespace std;

int parent[105];//parent[id] 保存的是id的父节点的id
char flag[105];//flag[i]=0 表示i是一个叶子节点 
int level[100];//level[i]记录第i层叶子节点的个数 

//求节点的深度 
int deepth(int id,int d){
	if( parent[id] ){
		return deepth(parent[id],d+1);
	}
	return d;
}

int main(){
	int n,m;//n Nodes, m non-leaf nodes
	int id,k,subId;
	cin>>n>>m;
	parent[1] = 0;
	//输入m条non-left nodes 
	for(int i=0;i<m;++i){
		cin>>id>>k;
		//标记出所有的non-left nodes
		flag[id] = 1;
		for(int j=0;j<k;++j){
			cin>>subId;
			parent[subId] = id;
		}
	}
	int MaxDeepth=0;
	for(int i=1;i<=n;++i){
		if(flag[i] == 0){
			int d = deepth(i,1);
			if(d>MaxDeepth) MaxDeepth = d; 
			++level[d];
		}
	}
//	cout<<"MaxDeepth:"<<MaxDeepth<<endl;
	cout<<level[1];
	for(int i=2;i<=MaxDeepth;++i){
		cout<<" "<<level[i];
	}
	cout<<endl;
	
	return 0;
}
