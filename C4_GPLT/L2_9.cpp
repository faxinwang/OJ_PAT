#include<iostream>
#include<algorithm>
using namespace std; 

struct Person{
	int id,income,redPocket;
};
Person p[10001];

bool cmp(const Person& p1,const Person& p2){
	if(p1.income != p2.income){
		return p1.income > p2.income;
	}else if(p1.redPocket != p2.redPocket){
		return p1.redPocket > p2.redPocket;
	}else{
		return p1.id <p2.id;
	}
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		p[i].id = i;
	for(int i=1;i<=N;++i){//第i个人发红包记录 
		int k,id,cent,sum=0;//sum为发送总金额 
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			scanf("%d%d",&id,&cent);
			p[id].income += cent;
			++p[id].redPocket;
			sum+=cent;
		}
		p[i].income -= sum;
	}
	
	sort(p+1,p+N+1,cmp);
	for(int i=1;i<=N;++i){
		printf("%d %.2lf\n",p[i].id,1.0*p[i].income/100);
	}
	
	return 0;
}
