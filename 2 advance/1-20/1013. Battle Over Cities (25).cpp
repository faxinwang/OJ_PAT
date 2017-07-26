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
			//ÿ������һ��δ���ʹ��ĳ��У�˵������һ���µ���ͨ����
			++cnt; 
			s[c] = 1;//���city cΪ�ѷ��ʹ� 
			DFS(c);
		}
	}
}

void removeCity(int c){
	for(int i=1;i<=N;++i) mp2[c][i] = mp2[i][c] = 0;
	s[c] = 1;//ʧȥ��city���Ϊ�ѷ��ʹ�
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
