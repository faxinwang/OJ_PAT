#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}; 
char M[]={'1','0','X','9','8','7','6','5','4','3','2'};

bool valid(string& id){
	int w_sum=0;
	for(int i=0;i<17;++i){
		if(id[i]<'0' || id[i]>'9') return false;
		w_sum += weight[i] * (id[i]-'0');
	}
	int z = w_sum % 11; 
	if(id[17] != M[z]) return false;
	return true;
}

int main(){
	int N;
	vector<string> v;
	string id;
	cin>>N;
	while(N--){
		cin>>id;
		if(!valid(id)) v.push_back(id);
	}
	if(v.size()){
		copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
	}else{
		cout<<"All passed"<<endl;
	}

	return 0;
}
