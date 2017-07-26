#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool valid(int a,vector<string> &exp){
	return a>=1 && a<=exp.size();
}

int main(){
	char ch;
	vector<string> hand,eye,mouse;
	string exp;
	//read hands
	while(scanf("%c",&ch) && ch!='\n'){
		if(ch == '[' || ch==' ') continue;
		if(ch == ']'){
			hand.push_back(exp);
			exp.clear();
			continue;
		}
		exp += ch;
	}
	//read eyes
	while(scanf("%c",&ch) && ch!='\n'){
		if(ch == '[' || ch==' ') continue;
		if(ch == ']'){
			eye.push_back(exp);
			exp.clear();
			continue;
		}
		exp += ch;
	}
	//read mouse
	while(scanf("%c",&ch) && ch!='\n'){
		if(ch == '[' || ch==' ') continue;
		if(ch == ']'){
			mouse.push_back(exp);
			exp.clear();
			continue;
		}
		exp += ch;
	}
	
	int T,a,b,c,d,e;
	cin>>T;
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(valid(a,hand) &&valid(b,eye) && valid(c,mouse)
		&& valid(d,eye) && valid(e,hand))
			cout<<hand[a-1]<<"("<<eye[b-1]<<mouse[c-1]
				<<eye[d-1]<<")"<<hand[e-1]<<endl;
		else
			cout<<"Are you kidding me? @\\/@"<<endl;
	}
	
	return 0;
}
