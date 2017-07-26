#include<iostream>
#include<cstdio>
using namespace std;

//the struct to store results
typedef struct{
	char ch;//W or T or L
	double odd;
}Game;

int main(){
	double wtl[3][3],profit;
	Game g[3];
	int i,j,max;
	
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			scanf("%lf",&wtl[i][j]);
	//to find the max odd in each game and store into the struct Game
	for(i=0;i<3;++i){
		for(j=1,max=0;j<3;++j)
			if(wtl[i][max]<wtl[i][j])
				max=j;
		g[i].odd=wtl[i][max];
		if(max==0) g[i].ch='W';
		else if(max==1) g[i].ch='T';
		else if(max==2) g[i].ch='L';
	}

	profit=( g[0].odd * g[1].odd * g[2].odd * 0.65 - 1 )*2;
	printf("%c %c %c %.2lf",g[0].ch,g[1].ch,g[2].ch,profit);
	return 0;
}
