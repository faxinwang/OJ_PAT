#include<iostream>
#include<string>
using namespace std;


int main(){
	string A;
	int B,Q,R;
	cin>>A>>B;
	
	if(A.size()==1 && A[0]-'0' < B){
		cout<<"0 "<<A[0]-'0'<<endl;
	}else{
		int reminder = 0;
		for(int i=0;i<A.size();++i){
			reminder = reminder * 10 + A[i]-'0';
			if(reminder < B){
				if(i==0)
					continue;
				else{
					cout<<"0";
					continue;
				}
			}
			cout<<reminder/B;
			reminder %= B;
		}
		cout<<" "<<reminder<<endl;
	}
	
	return 0;
}
