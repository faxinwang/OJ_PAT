#include<iostream>
#include<cstdio>
#include<vector>
#define N 100002
using namespace std;

int a[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	vector<int> v;
	v.reserve(n);
	
	int max=a[0];
	v.push_back(max);
	for(int i=1;i<n;++i){
		if(a[i] >= max){
			v.push_back(a[i]);
			max = a[i];
		}else{
			while(v.size() && a[i]<v.back()) v.pop_back();
		}
	}
	cout<<v.size()<<endl;
	if(v.size()) cout<<v[0];
	for(int i=1,len=v.size(); i<len;++i) cout<<" "<<v[i];
	cout<<endl;
	
	return 0;
}

