#include<iostream>
#include<string>
#include<set>
using namespace std;

/*
S记录的是第一个中奖的人，在程序中不断修改S的值，使其保持下一个 
中奖人的序号，如果该序号已经中奖过，则顺序找后面的人，同时修改S的值
为当前序号i后面的N个人:i+N 
*/ 

int main(){
	int M,N,S;
	string str;
	cin>>M>>N>>S;
	set<string> st;
	for(int i=1;i<=M;++i){
		cin>>str;
		if(i==S){
			if(st.find(str) == st.end()){
				cout<<str<<endl;
				st.insert(str);
				S += N;
			}else{
				while(i<=M){
					++i;
					cin>>str;
					if(st.find(str) == st.end()){
						st.insert(str);
						cout<<str<<endl;
						S = i + N; 
						break;
					}
				}
			}
			
		}
	}
	if(st.size()==0){
		cout<<"Keep going..."<<endl;
	}
	
	return 0;
}
