#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct Person{
	string name;
	int height;
	bool operator>(const Person& p)const{
		if(height != p.height) return height > p.height;
		return name < p.name;
	} 
};
string s[10000];
Person p[11000];

void print(int n){
	cout<<s[1];
	for(int i=2; i<=n; ++i) cout<<" "<<s[i];
	cout<<endl;
}

int main(){
	int n,k,i,j;
	bool flag = true;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i) cin>>p[i].name>>p[i].height;
	sort(p,p+n,greater<Person>());
	int col = n / k;
	int len=n-col*(k-1);
	int tmp = 0, mid=len/2+1;
	//最后一排 
	s[mid] = p[0].name;
	for(i=1,j=1; i<len; ++i){
		if(len%2){
			if(++tmp%2) s[mid-j] = p[i].name;
			else{
				s[mid+j] = p[i].name;
				++j;
			} 
		}else{
			if(++tmp%2) s[mid-j] = p[i].name;
			else{
				s[mid+j] = p[i].name;
				++j; 
			}
			 
		}
	}
	print(len);
	//前k排 
	for(mid=col/2+1; i<n; i+=col){
		tmp = 0;
		j=1;
		s[mid] = p[i].name;
		for(int k=1;k<col;++k){
			if(col%2){
				if(++tmp%2) s[mid-j] = p[i+k].name;
				else{
					s[mid+j] = p[i+k].name;
					++j;
				} 
			}else{
				if(++tmp%2) s[mid-j] = p[i+k].name;
				else{
					s[mid+j] = p[i+k].name;
					++j;
				} 
			}
		}
		print(col);
	}
	
	return 0;
}
