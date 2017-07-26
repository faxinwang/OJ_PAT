#include<iostream>
#include<cstdio>
using namespace std;

int s[105],a[105];

int main(){
	int N,M;
	cin>>N>>M;
	//read score
	for(int i=0;i<M;++i) scanf("%d",s+i);
	//read answer
	for(int i=0;i<M;++i) scanf("%d",a+i);
	//read student's answer
	for(int i=0;i<N;++i){
		int score=0;
		int ans;
		for(int j=0;j<M;++j){
			scanf("%d",&ans);
			if(ans == a[j]) score += s[j];
		}
		cout<<score<<endl;
	} 
	
	return 0;
}
