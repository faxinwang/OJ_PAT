#include<stdio.h>

//��һ��û���õ��������Ե�֪ʶ,��һѧ�������ͬѧӦ�ö���������,��ȥ��PAT�ϰ�����AC�˰� 

int main(){
	char str[1001];
	int b,result[1001],count=0,i,reminder=0;
	scanf("%s %d",str,&b);
	
	//���̲�����������result�� 
	for(i=0;str[i];++i){
		 reminder = reminder * 10 + str[i] - '0';	
		 result[count++] = reminder /b;	
		 reminder %= b;
	}
	
	i=0;
	if(result[0]==0) ++i;//�����һ������Ϊ0,��ӵڶ������ֿ�ʼ���(�ڶ�������һ������0)
	for(;i<count;++i){
		printf("%d",result[i]);
	} 
	printf(" %d",reminder);
	return 0;
}
