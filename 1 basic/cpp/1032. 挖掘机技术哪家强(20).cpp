#include<cstdio>

const int N = 1e5+5;
int a[N];

int main(){
	int n;
	int id,score;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&id,&score);
		a[id] += score;
	}
	score = id = 0;
	for(int i=1;i<=n;++i){
		if(a[i] > score){
			id = i;
			score = a[i];
		}
	}
	printf("%d %d\n",id,score);
	
	
	return 0;
}
