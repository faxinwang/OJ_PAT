#include<iostream> 
#include<string>
using namespace std;

int main(){
	string num;
	cin>>num;
	int count=0;
	int i=0;
	if(num[0]=='-') ++i;
	for(;i<num.size();++i){
		if(num[i]=='2') ++count;
	}
	double degree2 = 1.0 * count / (num[0]=='-'?num.size()-1:num.size());
	if(num[0]=='-') degree2*=1.5;
	if((num[num.size()-1]-'0')%2==0) degree2*=2;
	printf("%.2lf%%",degree2*100);
	
	return 0;
}
