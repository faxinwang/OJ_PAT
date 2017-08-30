#include<iostream>
#include<string>
using namespace std;

typedef struct{
	string name;
	string num;
	int score;
}Stud;


int main(){
	Stud st;
	string maxName,maxNum;
	string minName,minNum;
	int max=0,min=100,N;
	scanf("%d",&N);
	while(N--){
		cin>>st.name>>st.num>>st.score;
		if(max<st.score){
			max=st.score;
			maxName=st.name;
			maxNum=st.num;
		}
		if(min>st.score){
			min=st.score;
			minName=st.name;
			minNum=st.num;
		}
	}
	cout<<maxName<<' '<<maxNum<<endl;
	cout<<minName<<' '<<minNum<<endl;
	
	return 0;
}
