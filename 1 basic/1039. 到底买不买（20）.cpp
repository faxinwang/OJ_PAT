#include<iostream>
#include<cstdio>
using namespace std;

int p[200],q[200];


int main(){
	char ch;
	int left=0,need=0;
	while(scanf("%c",&ch) && ch != '\n') ++p[ch];
	while(scanf("%c",&ch) && ch != '\n') ++q[ch];
	
	bool flag=true;
	for(int i=1;i<=200;++i){
		if(p[i] < q[i]){
			flag = false;
			need += q[i] - p[i];
		}else if(p[i] > q[i]){
			left += p[i] - q[i]; 
		}
	}
	
	if(flag){
		printf("Yes %d",left);
	}else{
		printf("No %d",need);
	}
	
	
	return 0;
}
