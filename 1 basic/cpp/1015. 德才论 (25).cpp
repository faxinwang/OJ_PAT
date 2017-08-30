#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

//һ���ɼ���¼ 
struct Record{
	int ID;
	int D,C;
	Record(int id,int d,int c):ID(id),D(d),C(c){}
};

ostream& operator<<(ostream& out,const Record& r){
	return out<<r.ID<<" "<<r.D<<" "<<r.C;
}

bool cmp(Record r1, Record r2){
	int t1 = r1.D + r1.C;
	int t2 = r2.D + r2.C;
	if( t1 != t2 ) return t1>t2; //���ֽܷ�������
	
	if( r1.D != r2.D) return r1.D > r2.D; //���·ֵĽ������� 
	
	return r1.ID < r2.ID; //��ID���������� 
}

int main(){
	int N, L, H;
	int id, de, cai;
	vector<Record> a, b, c, d;
	scanf("%d%d%d",&N,&L,&H);
	while(N--){
		scanf("%d%d%d",&id,&de,&cai);
		if(de >= L && cai >= L){
			if(de >= H && cai >= H) //��һ�� 
				a.push_back(Record(id,de,cai));
			else if(de >= H && cai < H) //�ڶ��� 
				b.push_back(Record(id,de,cai));
			else if(de < H && cai < H && de >= cai) //������
				c.push_back(Record(id,de,cai)); 
			else
				d.push_back(Record(id,de,cai)); //������ 
		}
	}
	
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	sort(c.begin(),c.end(),cmp);
	sort(d.begin(),d.end(),cmp);
	
	printf("%d\n",a.size()+b.size()+c.size()+d.size()); //�����¼ȡ���� 
	copy(a.begin(),a.end(),ostream_iterator<Record>(cout,"\n"));
	copy(b.begin(),b.end(),ostream_iterator<Record>(cout,"\n"));
	copy(c.begin(),c.end(),ostream_iterator<Record>(cout,"\n"));
	copy(d.begin(),d.end(),ostream_iterator<Record>(cout,"\n"));
	
	return 0;
}
