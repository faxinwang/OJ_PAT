#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int fun(int x){
	int sum=0;
	for(; x ; x/=10) sum += x % 10;
	return sum;
}

int main(){
	int N,x;
	set<int> s;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&x);
		s.insert(fun(x));
	}
	
	cout<<s.size()<<endl;
	set<int>::iterator pos=s.begin();
	cout<<*pos;
	for(++pos; pos != s.end(); ++pos){
		cout<<" "<<*pos;
	}
	
	return 0;
} 
