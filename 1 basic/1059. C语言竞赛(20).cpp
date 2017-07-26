#include<iostream>
#include<cstdio>
#define N 10005
using namespace std;

int r[N];
int p[N];
void init(){
	p[0]=p[1] = 1;//not prime
	for(int i=2;i*i<N;++i)
		if(p[i]==0)
			for(int j=i*i; j<N; j+=i)
				p[j] = 1;
}

int main(){
	int n,id;
	init();
	//read ranks
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&id);
		r[id] = i;
	}
	//read query
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%d",&id);
		//id²»´æÔÚ 
		if(r[id]==0){
			printf("%04d: Are you kidding?\n",id);
		}else{
			//¹Ú¾ü 
			if(r[id] == 1){
				printf("%04d: Mystery Award\n",id);
			}
			else if(r[id]==-1){
				printf("%04d: Checked\n",id);
			}
			else{
				if(p[r[id]] == 0){
					printf("%04d: Minion\n",id);
				}else{
					printf("%04d: Chocolate\n",id);
				}
			}
			r[id] = -1;
		}
	}
	
	return 0;
} 
