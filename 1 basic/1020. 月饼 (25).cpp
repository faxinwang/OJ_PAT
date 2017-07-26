#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;

struct MoonCake{
	double amount,money;
	double price;
};
bool cmp(MoonCake m1,MoonCake m2){
	return m1.price > m2.price;
}

int main(){
	int N,D;
	scanf("%d %d",&N,&D);
	MoonCake mc[N];
	for(int i=0;i<N;++i){
		scanf("%lf",&mc[i].amount);
	}
	for(int i=0;i<N;++i){
		scanf("%lf",&mc[i].money);
		mc[i].price = mc[i].money/mc[i].amount;
	}
	sort(mc,mc+N,cmp);
	
//	for(int i=0;i<N;++i)
//		printf("%.2lf\n",mc[i].price);
		
	double profit=0;
	for(int idx = 0; D && idx<N; ++idx){
		if(D >= mc[idx].amount){
			profit += mc[idx].money;
			D -= mc[idx].amount;
		}
		else{
			profit += D * mc[idx].price;
			D = 0;
		}
	}

	printf("%.2lf",profit);

	return 0; 
} 

/*
75 72 45 money
18 15 10 amount
4.16 4.8 4.5
*/
