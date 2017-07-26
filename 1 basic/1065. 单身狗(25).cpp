#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cp[100000];
bool id[100000];

int main(){
	int n,a,b;
	scanf("%d",&n);
	//read couple
	for(int i=0;i<n;++i){
		scanf("%d%d",&a,&b);
		cp[a] = b;
		cp[b] = a;
	}
	//read id of person who is attending
	scanf("%d",&n);
	vector<int> query(n);
	for(int i=0;i<n;++i){
		scanf("%d",&query[i]);
		id[query[i]] = 1;
	}
	//compute
	sort(query.begin(),query.end());
	vector<int> rst;
	rst.reserve(query.size());
	for(int i=0;i<query.size();++i){
		if(id[query[i]] && id[cp[query[i]]]) continue;
		rst.push_back(query[i]);
	}
	//output result
	printf("%d\n",rst.size());
	if(rst.size()) printf("%05d",rst[0]);
	for(int i=1;i<rst.size(); ++i) printf(" %05d",rst[i]);
	
	return 0;
} 
