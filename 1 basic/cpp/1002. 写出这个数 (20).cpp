#include<iostream>
#include<string>
using namespace std;

string sum(string num){
	int n=0,i;
	string tmp,result="";
	for(i=0;i<num.size();++i){
		n+=num[i]-'0';
	}
	
	while(n){
		switch(n%10){
		case 0: tmp="ling ";	break;
		case 1: tmp="yi ";	break;
		case 2: tmp="er ";	break;
		case 3: tmp="san ";	break;
		case 4: tmp="si ";	break;
		case 5: tmp="wu ";	break;
		case 6: tmp="liu ";	break;
		case 7: tmp="qi ";	break;
		case 8: tmp="ba ";	break;
		case 9: tmp="jiu ";	break;
		}
		result = tmp + result;
		n/=10;
	}
	
	
	return result.substr(0,result.size()-1);
}

int main(){
	string num;
	cin>>num;
	cout<<sum(num)<<endl;
	
	return 0;
}
