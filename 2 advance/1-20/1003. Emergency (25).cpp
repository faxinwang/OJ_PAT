/*
1003. Emergency (25)
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
As an emergency rescue team leader of a city, you are given a special map of your 
country. The map shows several scattered cities connected by some roads. Amount 
of rescue teams in each city and the length of each road between any pair of 
cities are marked on the map. When there is an emergency call to you from some 
other city, your job is to lead your men to the place as quickly as possible, 
and at the mean time, call up as many hands on the way as possible.

Input
Each input file contains one test case. For each test case, the first line 
contains 4 positive integers: N (<= 500) - the number of cities (and the 
cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the 
cities that you are currently in and that you must save, respectively. The 
next line contains N integers, where the i-th integer is the number of rescue 
teams in the i-th city. Then M lines follow, each describes a road with three 
integers c1, c2 and L, which are the pair of cities connected by a road and 
the length of that road, respectively. It is guaranteed that there exists at 
least one path from C1 to C2.

Output
For each test case, print in one line two numbers: the number of different 
shortest paths between C1 and C2, and the maximum amount of rescue teams 
you can possibly gather.All the numbers in a line must be separated by exactly 
one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4

题目大意：
在给定的无向图中,求从c1点到c2点的最短路径数量和这些最短路径中最大的总权值，
需要注意的是这里的权值在顶点上而不是边上。 
 
解题思路：
用DFS搜索出所有从c1到c2的路径，记录最短路径的条数和这些最短路径中最大的总权值
由于要搜索出所有可能的路径，所以DFS在退栈的时候要把相应的点设为没有访问过。
*/ 
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits>
#define N 505
using namespace std;

int map[N][N];
int t[N];//rescue teams in a city
//number of city,number of road,city from,city to
int n,m,c1,c2;
//the length of all path from c1 to c2
bool visited[N];
int cnt=0,maxTeams=0,minDist=numeric_limits<int>::max();

void dfs(int curCity, int dist, int teams){
	if(dist>minDist) return;//剪枝 
	if(curCity==c2){
		if(dist<minDist){
			cnt=1;
			minDist = dist;
			maxTeams = teams;
		}else if(dist==minDist){
			++cnt;
			if(teams>maxTeams) maxTeams = teams;
		}
	}else{
		for(int i=0;i<n;++i){
			if(!visited[i] && map[curCity][i]){
				visited[i] = true;
				dfs(i,dist+map[curCity][i],teams+t[i]);
				visited[i] = false;
			}
		}
	}
}

int main(){
	int a,b,dist;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;++i) scanf("%d",t+i);
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&a,&b,&dist);
		map[a][b] = map[b][a] = dist;
	}
	visited[c1] = true;
	dfs(c1,0,t[c1]);

	printf("%d %d\n",cnt,maxTeams);
	
	return 0;
}
