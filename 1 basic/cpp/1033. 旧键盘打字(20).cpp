#include<cstdio>
#include<iostream> 
using namespace std;


int main(){
	char a[200]={0};
	bool flag=true,check=false;
	char ch;
	while(scanf("%c",&ch) && ch!='\n'){
		if(ch=='+'){
			flag=false;//show that "Shift" is not work
		} else if(isupper(ch)){
			a[ch] = 1;
			a[ch+32] = 1; //the corresponding lower letter
		}else{
			a[ch] = 1;
		}
		
	}
	
	while(scanf("%c",&ch) && ch!='\n'){
		//if the key has no problem
		if(!a[ch]){
			if(isupper(ch)){
				if(flag){
					putchar(ch);
					check = true;
				}
			}else{
				putchar(ch);
				check = true;
			}
		}
	}
	if(check==false) putchar('\n');
	
	
	
	return 0;
}
