/*
����˼·:
����DFS�ҳ����е����·������������е����·����ѡ������·���� 
����dijkstra�㷨����Ϊ���������и�Ȩֵ�����⡣��ĿҪ����������������У�
·�����ȵ�����send��������backֵ���ܱ�С����Ŀ��˼һ��С�ľ������ˣ���
ԭ�㵽sp�Ĺ������������е㣬���ǲ���Ѷ�������г����ͻ�֮ǰ�ĵ㣬����һ
��·��bike��Ϊ 3 10����send 2��back 5��������back 3��

*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define maxn 505
#define INF 1<<30
using namespace std;

int Cm,N,Sp,M;
int s[maxn]; //station
int g[maxn][maxn];
int shortest = INF;
int minSend = INF, minBack=INF;
vector<vector<int> > paths;
vector<int> path;
bool vis[maxn];

void dfs(int c,int len){
	if(c == Sp){
		//�ҵ��˸��̵�·�� 
		if(len < shortest){
			shortest = len;
			paths.clear();
			paths.push_back(path);
		}else{ //�ҵ����뵱ǰ·���ȳ���·�� 
			paths.push_back(path);
		}
	}else{
		for(int i=1;i<=N;++i){
			if(!vis[i] && g[c][i] && len+g[c][i] <= shortest){ //use <= 
				path.push_back(i);
				vis[i] = 1;
				dfs(i,len+g[c][i]);
				vis[i] = 0;
				path.pop_back();
			}
		}
	}
}

//p���汣��Ľڵ㲻����PBMC�����ڵ�0 
int cost(vector<int>& p){
	int send =0 ,back = 0;
	int half = Cm/2;
	for(int i=0;i<p.size();++i){
		if(back + s[p[i]] < half) send += half - back - s[p[i]], back =0;
		else back = back + s[p[i]] - half;
	}
	if(send < minSend || (send==minSend && back < minBack)){
		minSend = send, minBack = back;
		return 1;
	}
	return 0;
}
void printPath(vector<int>& p){
	printf("%d 0",minSend);
	for(int i=0;i<p.size();++i) printf("->%d",p[i]);
	printf(" %d",minBack);
} 

int main(){
#ifdef WFX
freopen("1018 in.txt","r",stdin);
#endif
	int Si,Sj,Tij;
	scanf("%d%d%d%d",&Cm,&N,&Sp,&M);
	for(int i=1;i<=N;++i) scanf("%d",s+i); //current number of bikes at Si 
	for(int i=0;i<M;++i){
		scanf("%d%d%d",&Si,&Sj,&Tij);
		g[Si][Sj] = Tij;
		g[Sj][Si] = Tij;
	}
	
	vis[0] = 1;
	dfs(0,0);
	if(paths.size() == 1){ //noly one shortest path 
		cost(paths[0]);
		printPath(paths[0]);
	}else{
		cost(paths[0]);
		int idx = 0;
		for(int i=1;i<paths.size();++i) if( cost(paths[i]) ) idx = i;
		printPath(paths[idx]);
	}
	
	return 0;
}
