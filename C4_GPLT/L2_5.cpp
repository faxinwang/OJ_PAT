#include<iostream> 
#include<set>
using namespace std;
set<int> s[50];

double familiar(set<int>&a,set<int>& b){
	int Nc=0;
	typename set<int>::iterator pa,pb;
	for(pa=a.begin(),pb=b.begin(); pa!=a.end() && pb!=b.end();){
		if(*pa < *pb){
			++pa;
		}else if(*pa > *pb){
			++pb;
		}else{
			++pa; ++pb; ++Nc;
		}
	}
	int Nt = a.size()+b.size()-Nc;
	return 1.0*Nc/Nt*100;
}

int main(){
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&M);
		int tmp;
		for(int j=0;j<M;++j){
			scanf("%d",&tmp);
			s[i].insert(tmp);
		}
	}
	scanf("%d",&M);
	for(int i=0;i<M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%.2lf%%\n",familiar(s[a-1],s[b-1]));
	}	
	
	return 0;
}
