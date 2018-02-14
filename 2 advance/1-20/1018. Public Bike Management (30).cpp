/*
1018. Public Bike Management (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
There is a public bike service in Hangzhou City which provides great convenience to 
the tourists from all over the world. One may rent a bike at any station and return 
it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of 
all the stations. A station is said to be in perfect condition if it is exactly 
half-full. If a station is full or empty, PBMC will collect or send bikes to adjust 
the condition of that station to perfect. And more, all the stations on the way will 
be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach 
that station. If there are more than one shortest path, the one that requires the least 
number of bikes sent from PBMC will be chosen.

Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads 
correspond to the edges. The number on an edge is the time taken to reach one end station 
from another. The number written inside a vertex S is the current number of bikes stored 
at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, 
we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 
  1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent 
  from PBMC and hence is the one that will be chosen.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: 
Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), 
the total number of stations; Sp, the index of the problem station (the stations are 
numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. 
The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current 
number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, 
and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers 
in a line are separated by a space.

Output Specification:
For each test case, print your results in one line. First output the number of bikes that 
PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally 
after another space, output the number of bikes that we must take back to PBMC after the 
condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes 
that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

Sample Output:
3 0->2->3 0

解题思路:
先用DFS找出所有的最短路径，然后在所有的最短路径中选择最优路径。
最优路径为：所需要送出去的bike最少，如果需要送出去的bike数相等，则需要带回来的bike数最少。
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


//找出所有的最短路径 
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
		//选择最优路径 
		cost(paths[0]);
		int idx = 0;
		for(int i=1;i<paths.size();++i) if( cost(paths[i]) ) idx = i;
		printPath(paths[idx]);
	}
	
	return 0;
}
