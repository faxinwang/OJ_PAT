#include<iostream>
#include<cstdio>
using namespace std;

/*
权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}
Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
*/
int W[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[]={'1','0','X','9','8','7','6','5','4','3','2'};

bool valid(char s[]){
	int sum=0;
	for(int i=0;i<17;++i){
		if(!isdigit(s[i])) return false;
		sum += (s[i]-'0') * W[i];
	}
	if(s[17] != M[sum%11]) return false;
	return true;
}


int main(){
	char id[19];
	int N,flag=0;
	scanf("%d",&N);
	while(N--){
		scanf("%s",id);
		if(!valid(id)){
			printf("%s---\n",id);
			flag=1;
		}
	}
	if(flag==0) printf("All passed");
	
	return 0;
}
