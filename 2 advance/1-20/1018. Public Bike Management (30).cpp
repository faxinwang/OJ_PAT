/*
解题思路:
先用DFS找出所有的最短路径，软后在所有的最短路径中选择最优路径。 
不用dijkstra算法，因为不适用于有负权值的问题。题目要求的条件在求解过程中，
路径长度递增，send递增，而back值可能变小。题目意思一不小心就理解错了，从
原点到sp的过程中修正所有点，但是不会把多余的自行车再送回之前的点，比如一
条路上bike数为 3 10，是send 2，back 5，而不是back 3。

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
		//找到了更短的路径 
		if(len < shortest){
			shortest = len;
			paths.clear();
			paths.push_back(path);
		}else{ //找到了与当前路径等长的路径 
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

//p里面保存的节点不包括PBMC，即节点0 
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
