#include<iostream>
#include<set>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
	vector<int> vi,count;
	vector<set<int> > vs;
	int N,n,tmp;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d:",&n);
		for(int j=0;j<n;++j){
			scanf("%d",&tmp);
			vi.push_back(tmp);
		}
		bool found=false;
		for(int k=0;k<vs.size() && !found; ++k){
			for(int j=0;j<n;++j)
				if(vs[k].find(vi[j])!=vs[k].end()){
					vs[k].insert(vi.begin(),vi.end());
					++count[k];
					found = true; break; 
				}
		}
		if(!found){
			vs.push_back(set<int>(vi.begin(),vi.end()));
			count.push_back(1);
		}
		vi.clear();
	}
	for(int i=0;i<vs.size();++i){
		for(int j=i+1;j<vs.size();++j){
			typename set<int>::iterator pos;
			for(pos=vs[j].begin();pos!=vs[j].end();++pos){
				if(vs[i].find(*pos) != vs[i].end()){
					vs[i].insert(vs[j].begin(),vs[j].end());
					vs[j].clear();
					count[i]+=count[j];
					count[j]=0;
					break;
				}
			}
		}
			
	}
	set<int,greater<int> > rank;
	for(int i=0;i<count.size();++i)
		if(count[i]) rank.insert(count[i]);
	cout<<rank.size()<<endl;
	copy(rank.begin(),--rank.end(),ostream_iterator<int>(cout," "));
	cout<<*rank.rbegin()<<endl;

	return 0;
}
