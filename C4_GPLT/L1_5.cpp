#include<iostream>
#include<cstdio>
#include<deque>
#include<string>
using namespace std;

struct Stud{
	string ID;
	int jishi,kaoshi;
	Stud(string id,int js,int ks):ID(id),jishi(js),kaoshi(ks){}
};

int main(){
	int N,jishi,kaoshi;
	char id[15];
	deque<Stud> s;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%s%d%d",id,&jishi,&kaoshi);
		s.push_back(Stud(id,jishi,kaoshi));
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;++i){
		scanf("%d",&jishi);
		for(int j=0;j<N;++j)
			if(s[j].jishi == jishi)
				cout<<s[j].ID<<' '<<s[j].kaoshi<<endl;
	}
	

	return 0;
}
