#include<iostream>
#include<string>
#include<set>
using namespace std;

/*
S��¼���ǵ�һ���н����ˣ��ڳ����в����޸�S��ֵ��ʹ�䱣����һ�� 
�н��˵���ţ����������Ѿ��н�������˳���Һ�����ˣ�ͬʱ�޸�S��ֵ
Ϊ��ǰ���i�����N����:i+N 
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
