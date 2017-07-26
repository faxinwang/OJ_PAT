#include<iostream>
#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
	unsigned int A,B,D;
	scanf("%d%d%d",&A,&B,&D);
	int sum = A + B;
	vector<int> v;
	while(sum){
		v.push_back(sum%D);
		sum/=D;
	}
	copy(v.rbegin(),v.rend(),ostream_iterator<int>(cout,""));
	if(A+B==0) printf("0");
	
	return 0;
}
