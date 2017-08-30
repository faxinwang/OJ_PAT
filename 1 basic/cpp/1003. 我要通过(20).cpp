#include<stdio.h> 
#include<string.h>

int main(){
	char str[100];
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		int len = strlen(str);
		int count_P=0,count_A=0,count_T=0;
		int pos_P=0,pos_T=0;
		for(int i=0;i<len;++i){
			if(str[i]=='P'){
				++count_P;
				pos_P=i;
			}
			else if(str[i]=='A'){
				++count_A;
			}
			else if(str[i]=='T'){
				++count_T;
				pos_T=i;
			}

		}
		
		if( count_P+count_A+count_T!=len || //包含其他字符 
			pos_T-pos_P<=1||				//PT中间没有A 
			count_P>1||
			count_T>1||						//P,A的个数大于1 
			pos_P*(pos_T-pos_P-1) != len-pos_T-1 //a*b!=c 
		)
		{
			printf("NO\n"); 
		}else{
			printf("YES\n");
		}
	}
	
	return 0; 
} 
