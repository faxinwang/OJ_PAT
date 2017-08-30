#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

struct Problem{
	int score;
	vector<char> ans;
};
struct Record{
	int id,count;
	Record(int id,int c):id(id),count(c){}
	bool operator>(const Record& r)const {
		if(count!=r.count) return count>r.count;
		return id<r.id;
	}
};

Problem p[105];
int r[105];

int main(){
	int N,M;
	char ch;
	scanf("%d%d",&N,&M);
	//read problems
	for(int i=0;i<M;++i){
		int total;
		scanf("%d %d %c",&p[i].score,&total,&ch);
		p[i].ans.push_back(ch);
		while((ch=getchar()) && ch!='\n')
			if(ch!=' ') p[i].ans.push_back(ch);
//		copy(p[i].ans.begin(),p[i].ans.end(),ostream_iterator<char>(cout,"_"));
//		cout<<endl;
	}
	
	//read answers
	for(int i=0;i<N;++i){
		int socre = 0,pro=0;
		vector<char> ans;
		while((ch=getchar()) && ch!='\n'){
			if(ch=='(' || ch==' ') continue;
			if(ch==')'){
//				copy(ans.begin(),ans.end(),ostream_iterator<char>(cout," "));
//				cout<<endl;
				if(ans == p[pro].ans) socre += p[pro].score;
				else ++r[pro];
				ans.clear();
				++pro;
			}else{
				ans.push_back(ch);
			}
		}
		cout<<socre<<endl;
	}
	
	vector<Record> v;
	for(int i=0; i<M; ++i)
		if(r[i]) v.push_back(Record(i+1,r[i]));
	sort(v.begin(),v.end(),greater<Record>());
	if(v.size()){
		int max = v[0].count;
		cout<<v[0].count<<" "<<v[0].id;
		for(int i=1;i<v.size();++i){
			if(v[i].count < max) break; 
			cout<<" "<<v[i].id;
		}
		cout<<endl;
	}else{
		cout<<"Too simple"<<endl;
	}

	
	return 0;
} 
