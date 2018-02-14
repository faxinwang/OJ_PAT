/*
1013. Battle Over Cities (25)
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
It is vitally important to have all the cities connected by highways in a war. 
If a city is occupied by the enemy, all the highways from/toward that city are 
closed. We must know immediately if we need to repair any other highways to 
keep the rest of the cities connected. Given the map of cities which have all 
the remaining highways marked, you are supposed to tell the number of highways 
need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and 
city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway 
repaired, that is the highway city2-city3.

Input
Each input file contains one test case. Each case starts with a line containing 3 
numbers N (<1000), M and K, which are the total number of cities, the number of 
remaining highways, and the number of cities to be checked, respectively. Then 
M lines follow, each describes a highway by 2 integers, which are the numbers 
of the cities the highway connects. The cities are numbered from 1 to N. Finally 
there is a line containing K numbers, which represent the cities we concern.

Output
For each of the K cities, output in a line the number of highways need to be 
repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3

Sample Output
1
0
0

题目大意：
给定一个图的结构，问如果去掉某个顶点，图中会有几个连通分量。
 
解题思路：
1.去掉某个顶点，在链接矩阵中的操作就是将所有与该顶点相连的边拿掉。
2.位了不破坏图结构，每次操作都在原图的副本上进行。 
3.通过DFS_driver()和DFS()统计去掉点后连通分量的个数。
*/ 
#include<iostream> 
#include<cstdio>
#include<cstring>
#define Max 1000
using namespace std;

bool mp[Max][Max];
bool mp2[Max][Max];
bool s[Max];
int N,K,M;
int cnt;

void DFS(int u){
	for(int v=1; v<=N;++v){
		if(mp2[u][v] && !s[v]){
			s[v] = 1;
			DFS(v);
		}
	}
}

void DFS_Driver(){
	for(int c=1;c<=N;++c){
		if(!s[c]){
			//每次遇到一个未访问过的城市，说明存在一个新的连通分量
			++cnt; 
			s[c] = 1;//标记city c为已访问过 
			DFS(c);
		}
	}
}

void removeCity(int c){
	for(int i=1;i<=N;++i) mp2[c][i] = mp2[i][c] = 0;
	s[c] = 1;//失去的city标记为已访问过
}

int main(){
	cin>>N>>M>>K;
	int a,b;
	for(int i=0;i<M;++i){
		 scanf("%d%d",&a,&b);
		 mp[a][b] = mp[b][a] = 1;
	}
	for(int i=0;i<K;++i){
		scanf("%d",&a); //the lost city
		memcpy(mp2,mp,sizeof(mp));
		removeCity(a);
		cnt=0;
		DFS_Driver();
		cout<<cnt-1<<endl;
		//cities are numbered from 1 to N
		memset(s,0,N+1);
	}
	
	return 0;
}
