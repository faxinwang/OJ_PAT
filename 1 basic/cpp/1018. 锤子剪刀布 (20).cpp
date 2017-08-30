#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int Jia=0,Yi=0;
//以ch字母获胜的次数 
struct Entry{
	int count;
	char ch;
};

int cmp(Entry e1,Entry e2){
	if(e1.count != e2.count) return e1.count>e2.count; 
	return e1.ch < e2.ch;
}

Entry s1[] = {{0,'C'},{0,'J'},{0,'B'}}; //Jia分别以C J B获胜的次数 
Entry s2[] = {{0,'C'},{0,'J'},{0,'B'}}; //Yi分别以C J B获胜的次数

//a为Jia的手势,b为Yi的手势 
void fight(char a,char b){
	if(a=='C'){
		if(b=='J'){
			++Jia; //Jia win 
			++s1[0].count;
		}
		else if(b=='B'){
			++Yi; 		//Yi win
		 	++s2[2].count; //s[2] 代表出B的时候赢 
		}
	}else if(a=='J'){
		if(b=='B'){
			++Jia;
			++s1[1].count; //s[1] 代表出J的时候赢 
		}
		else if(b=='C'){
			++Yi;
			++s2[0].count;
		}
	}else{
		if(b=='C'){
			++Jia;
			++s1[2].count;
		} 
		else if(b=='J'){
			++Yi;
			++s2[1].count;
		} 
	}
}


int main() {
	int N;
	char jia,yi; 
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		cin>>jia>>yi;
		fight(jia,yi);
	}
	
	printf("%d %d %d\n",Jia,N-Jia-Yi,Yi);
	printf("%d %d %d\n",Yi,N-Jia-Yi,Jia);
	
	sort(s1,s1+3,cmp);
	sort(s2,s2+3,cmp);
	
	printf("%c %c",s1[0].ch,s2[0].ch);
	
	return 0; 
} 
