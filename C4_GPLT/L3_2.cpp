#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void count_sort(vector<int>& a,int *b,int N){
	int max = *max_element(a.begin(),a.end());
	int c[max+1];
	fill(c,c+max+1,0);
	for(int i=0;i<N;++i) ++c[a[i]];
	for(int i=1;i<=max;++i) c[i] += c[i-1];
	for(int i=N;i>0;--i){
		b[ c[a[i-1]] -1 ] = a[i-1];
		--c[a[i-1]];
	}
}

class Stack{
	public:
		vector<int> v;
		Stack(){}
		void Push(int x){
			v.push_back(x);
		}
		int Pop(){
			int tmp = v.back();
			v.pop_back();
			return tmp;
		}
		int PeekMedian(){
			if(v.size()==1){
				return v[0];
			}
			int mid;
			if(v.size()%2)
				mid = (v.size()+1)/2;
			else
				mid = v.size()/2;
			int b[v.size()];
			count_sort(v,b,v.size());
			return b[mid-1];	
		}
		int size(){
			return v.size();
		}
};

int main(){
	int N,x;
	Stack s;
	string dir;
	scanf("%d",&N);
	while(N--){
		cin>>dir;
		if(dir=="Push"){
			scanf("%d",&x);
			s.Push(x);
		}else if(dir=="Pop"){
			if(s.size())
				cout<<s.Pop()<<endl;
			else
				cout<<"Invalid"<<endl;
		}else{
			if(s.size())
				cout<<s.PeekMedian()<<endl;
			else
				cout<<"Invalid"<<endl;
		}
	//	cout<<endl;
	}
	
	return 0;
}
