#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

string nums[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
	vector<string> v;
	int n;
	bool flag=false;
	scanf("%d",&n);
	if(n<0){
		flag=true;
		n=-n;
	}
	if(n==0){
		cout<<"ling"<<endl;
		return 0; 
	}
	while(n){
		v.push_back(nums[n%10]);
		n/=10;
	}
	if(flag) cout<<"fu ";
	copy(v.rbegin(),--v.rend(),ostream_iterator<string>(cout," "));
	cout<<*(--v.rend())<<endl;
	return 0;
}

