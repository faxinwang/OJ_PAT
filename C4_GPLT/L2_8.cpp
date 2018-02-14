/*
L2-008. ��Գ��Ӵ�
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
�Ը������ַ���������Ҫ���������Գ��Ӵ��ĳ��ȡ����磬����"Is PAT&TAP symmetric?"��
��Գ��Ӵ�Ϊ"s PAT&TAP s"��������Ӧ�����11��

�����ʽ��
������һ���и������Ȳ�����1000�ķǿ��ַ�����

�����ʽ��
��һ���������Գ��Ӵ��ĳ��ȡ�

����������
Is PAT&TAP symmetric?

���������
11

����˼·��
1.���ַ����У���1��n-2��λ����ö���Ը�λ��Ϊ�Գ��������õ��ĶԳ��Ӵ��ĳ���.
2.��ÿ��λ���Ϸֱ��ǶԳ��Ӵ�����Ϊż�Ϻ������������
3.����Щö��ֵ�з������ġ� 
*/ 
#include<iostream>
#include<string>
using namespace std;

int symmetric_len(string& str){
	int max_len=1;
	//�Ȱѳ��ȵ����������� 
	for(int i=1;i<str.size()-1;++i){
		int cur_len = 1 ; 
		for(int j=1;i-j>=0 && i+j<str.size();++j,cur_len+=2)
			if(str[i-j] != str[i+j]) break;
		if(max_len < cur_len) max_len = cur_len;
	}
	//�ٰѳ��ȵ���ż������ 
	for(int i=1;i<str.size()-1;++i)
		if(str[i]==str[i+1]){
			int cur_len = 2;
			for(int j=1;i-j>=0 && i+j+1<str.size();++j,cur_len+=2)
				if(str[i-j]!=str[i+j+1]) break;
			if(max_len < cur_len) max_len = cur_len; 
		}

	return max_len;
}

int main(){
	string  str;
	getline(cin,str);
	cout<<symmetric_len(str)<<endl;
	
	return 0;
}
