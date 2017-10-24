#include<iostream>
#include<string>
using namespace std;
short R[101][101]={0};
int N,M,K;

void DFS(int u,bool* visited){
	visited[u] = true;
	for(int i=1;i<=N;++i)
		if(R[u][i]==1 && !visited[i])
			DFS(i,visited);
}

string relationship(int i,int j){
	if(R[i][j]==1){	//���ѹ�ϵ 
		return "No problem";
	}else if(R[i][j]==0){	//û�й�ϵ 
		return "OK";
	}else{	//�жԹ�ϵ,��Ҫ����û�й�ͬ������ 
		bool visited[N+1];
		fill(visited,visited+N+1,0);
		DFS(i,visited);
		if(visited[j])//i,j�й�ͬ���� 
			return "OK but...";
		return "No way";	//i,j�޹�ͬ���� 
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int a=1;a<=M;++a){
		int i,j,r;
		scanf("%d%d%d",&i,&j,&r);
		R[i][j]=r;
		R[j][i]=r;
	}
	for(int a=0;a<K;++a){
		int i,j;
		scanf("%d%d",&i,&j);
		cout<<relationship(i,j)<<endl;
	}
	
	return 0;
}
