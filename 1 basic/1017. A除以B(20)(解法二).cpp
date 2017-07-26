#include<stdio.h>

//这一题没有用到多少语言的知识,大一学到数组的同学应该都可以做了,回去在PAT上把这题AC了吧 

int main(){
	char str[1001];
	int b,result[1001],count=0,i,reminder=0;
	scanf("%s %d",str,&b);
	
	//求商并保存在数字result中 
	for(i=0;str[i];++i){
		 reminder = reminder * 10 + str[i] - '0';	
		 result[count++] = reminder /b;	
		 reminder %= b;
	}
	
	i=0;
	if(result[0]==0) ++i;//如果第一个数字为0,则从第二个数字开始输出(第二个数字一定不是0)
	for(;i<count;++i){
		printf("%d",result[i]);
	} 
	printf(" %d",reminder);
	return 0;
}
