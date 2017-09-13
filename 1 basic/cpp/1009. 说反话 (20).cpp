#include<iostream>
#include<string>
using namespace std;

int main(){
	string word,ans;
	while(cin>>word) ans = word + " " + ans;
	cout<<ans.substr(0,ans.size()-1)<<endl;
	
	return 0;
}
