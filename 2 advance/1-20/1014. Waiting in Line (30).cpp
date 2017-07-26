#include<iostream>
#include<cstdio> 
#include<queue>
#define MAX 1001
using namespace std;

int processTime[MAX];
int leaveTime[MAX];
int timeBase[20+1]={0};
queue<int> que[20+1];
int endTime=60*9;//there is 9 hours from 8:00 to 17:00


int main(){
	int N,M,K,Q;// num of window,capacity of line,customers,num of querys
	cin>>N>>M>>K>>Q;
	for(int i=0;i<K;++i)
		scanf("%d",processTime+i);
	int cur=0;
	for(int i=0;cur < N*M && cur<K; ++cur){
		que[i].push(cur);
		leaveTime[cur]=timeBase[i]+processTime[cur];
		timeBase[i]=leaveTime[cur];
		i=(i+1)%N;
	}
	for(int min;cur<K;++cur){
		//find earliest leave customer
		int min_wait=0xfffffff;
		for(int i=0;i<N;++i){
			int cus=que[i].front();
			if(min_wait>leaveTime[cus]){
				min_wait=leaveTime[cus];
				min=i;
			}
		}
		que[min].pop();
		que[min].push(cur);
		leaveTime[cur]=timeBase[min]+processTime[cur];
		timeBase[min]=leaveTime[cur];
	}
	while(Q--){
		int query;
		scanf("%d",&query);
		--query;
		if(leaveTime[query]-processTime[query] >= endTime){
			cout<<"Sorry"<<endl;
		}
		else{
			int h=leaveTime[query]/60;
			int m=leaveTime[query]%60;
			printf("%02d:%02d\n",h+8,m);
		}
	}
	
	return 0;
}
