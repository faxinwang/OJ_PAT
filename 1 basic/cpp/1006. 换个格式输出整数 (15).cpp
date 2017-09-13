#include<iostream> 
#include<string>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int b = n / 100;
	int s = n % 100 / 10;
	int g = n % 10;
	string ans;
	for(int i=0; i<b; ++i) ans += 'B';
	for(int i=0; i<s; ++i) ans += 'S';
	for(int i=1; i<=g; ++i) ans += char(i + '0');
	cout<<ans<<endl;
		
	return 0;
}
