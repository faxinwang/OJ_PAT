#include<iostream>
#include<cstdio>
using namespace std;

int totalTime(int *a,int n){
	int time=0,curFloor=0;
	for(int i=0;i<n;++i){
		if(curFloor<a[i]){
			time+=6*(a[i]-curFloor);
		}else{
			time+=4*(curFloor-a[i]);
		}
		time+=5;
		curFloor=a[i];
	}
	return time;
}


int main(){
	int N;
	cin>>N;
	int *a = new int[N];
	for(int i=0;i<N;++i)
		scanf("%d",a+i);
	cout<<totalTime(a,N)<<endl;
	
	delete []a; 
	return 0;
}
