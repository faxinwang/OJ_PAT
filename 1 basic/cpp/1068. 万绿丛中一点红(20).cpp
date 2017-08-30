#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
using namespace std;

//�������ص��λ�ú���ɫ 
struct Pix{
	int row,col,color;
	Pix(int r,int c,int color):row(r),col(c),color(color){}
};
int M,N,Tol;

int g[1005][1005];
int cnt[(1<<24)+5]; //cnt[i]��������ֵΪi�ĵ���ֵĴ��� 

bool valid(int i,int j){
	if(1<=i && i<=N && 1<=j && j<=M) return true;
	return false;
}

//�������Χ8�����ص�Ĳ�ֵ�Ƿ����Tol 
bool fun(int row,int col){
	for(int i=row-1;i<=row+1;++i){
		for(int j=col-1;j<=col+1;++j){
			if( (i!=row || j!= col) && valid(i,j) &&
				abs(g[row][col]-g[i][j])<=Tol) return false;
		}
	}
	return true;
}

int main(){
	vector<Pix> v;
	cin>>M>>N>>Tol;
	//N * M 
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			scanf("%d",&g[i][j]);
			++cnt[g[i][j]]; //ͳ�Ƹ�����ֵ���ֵĴ��� 
		}
	}
	//N * M 
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			if( cnt[g[i][j]] ==1 && fun(i,j) ) 
				v.push_back(Pix(i,j,g[i][j]));
		}
	}
	if(v.size()==0){
		cout<<"Not Exist"<<endl;
	}else if(v.size()==1){
		printf("(%d, %d): %d\n",v[0].col,v[0].row,v[0].color);
	}else{
		cout<<"Not Unique"<<endl;
//		for(int i=0;i<v.size();++i){
//			printf("(%d, %d): %d\n",v[i].col,v[i].row,v[i].color);
//		}
	}
	
	return 0; 
}
