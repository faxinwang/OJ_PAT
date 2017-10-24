#include<iostream>
#include<deque>
using namespace std;
int ID[100000]={0};

int main(){
	int N,M,id;
	scanf("%d",&N);
	for(int i=0;i<N;++i){ //输入N个朋友圈 
		int k;
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&id);//只有一个人在朋友圈，并不能确定他是否还有朋友 
			continue;
		}
		for(int j=0;j<k;++j){
			scanf("%d",&id);
			ID[id] = 1;//ID[id]=1 表示有朋友id有朋友，为0表示id没朋友 
		}
	}
	deque<int> d;
	scanf("%d",&M);
	for(int i=0;i<M;++i){
		scanf("%d",&id);
		if(ID[id]==0){
			ID[id]=1;//将次人设置为有朋友，并没重复查询时重复输出 
			d.push_back(id);
		}
	}
	if(d.size()){
		for(int i=0;i<d.size()-1;++i){
			printf("%05d ",d[i]);
		}
		printf("%05d",d[d.size()-1]);
	}else{
		printf("No one is handsome");
	}
	
	return 0;
}
