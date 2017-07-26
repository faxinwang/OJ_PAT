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
	if(dist>minDist) return;//ºÙ÷¶ 
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
