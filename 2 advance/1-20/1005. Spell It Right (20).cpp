#include<iostream>
#include<string>
using namespace std;

//calculate the sum of every digit of the num
int sum(string& str){
	int s=0;
	for(int i=0;i<str.size();++i){
		s+=str[i]-'0';
	}
	return s;
}

//transform the sum into string
string transform(int n){
	string num="";
	while(n){
		switch(n%10){
		case 0:num =" zero" + num;		break;
		case 1:num =" one" + num;		break;
		case 2:num =" two" + num;		break;
		case 3:num =" three" + num;		break;
		case 4:num =" four" + num;		break;
		case 5:num =" five" + num;		break;
		case 6:num =" six" + num;		break;
		case 7:num =" seven" + num;		break;
		case 8:num =" eight" + num;		break;
		case 9:num =" nine" + num;		break;
		}
		n/=10;
	}
	//if the sum == 0,then "zero" should be returned
	if(num.size()){
		return num.substr(1,num.size());
	}else{
		return "zero";
	}
	
}



int main(){
	string num;
	cin>>num;
	cout<<transform(sum(num))<<endl;
	
	return 0;
}
