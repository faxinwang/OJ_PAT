#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;

struct Person{
	int id,fa,ma,kid;
	set<int> child;
	int house,area;
};
Person p[10000];

struct Family{
	int min_id,member;
	int house,area;
	Family(int id=10000,int mem=0,double house=0,double area=0)
		  :min_id(id),member(mem),house(house),area(area){}
	void update_id(int id){
		if(id<min_id)
			min_id = id;
	}
	void add_area(int a){
		area += a;
	}
	void add_house(int h){
		house += h;
	}
//	void add_member(int m){
//		member += m;
//	}
	double ave_house()const{
		return 1.0*house/member;
	}
	double ave_area()const{
		return 1.0*area/member;
	}
	bool operator>(const Family& f)const{
		if(ave_house() != f.ave_house())
			return ave_house() > f.ave_house();
		else
			return min_id < f.min_id;
			
	}
};
ostream& operator<<(ostream& out,const Family& f){
	printf("%04d %d %.3lf %.3lf",
		f.min_id,f.member,f.ave_house(),f.ave_area());
	return out;
}

void calculate(Person& ps,Family& f){
	++f.member;
	if(ps.id==0) return;
	f.update_id(ps.id);
	f.add_house(ps.house);
	f.add_area(ps.area);
	if(ps.child.size()){
		typename set<int>::iterator pos;
		for(pos=ps.child.begin();pos!=ps.child.end();++pos)
			calculate(p[*pos],f);
	}
}


int main(){
	int N,id;
	scanf("%d",&N);
	set<Family,greater<Family> > coll;

	while(N--){
		scanf("%d",&id);
		p[id].id = id;
		scanf("%d%d%d",&p[id].fa,&p[id].ma,&p[id].kid);
		if(p[id].fa != -1){
			p[ p[id].fa ].id = p[id].fa;
			p[ p[id].fa ].child.insert(id);
		//	if(p[ p[id].fa ].fa ==0) p[ p[id].fa ].fa = -1;
		//	if(p[ p[id].fa ].ma ==0) p[ p[id].fa ].ma = -1;
		}
		if(p[id].ma != -1){
			p[ p[id].ma ].id = p[id].ma;
			p[ p[id].ma ].child.insert(id);
		//	if(p[ p[id].ma ].fa ==0) p[ p[id].ma ].fa = -1;
		//	if(p[ p[id].ma ].ma ==0) p[ p[id].ma ].ma = -1;
		}
		if(p[id].kid){
			int child_id;
			for(int i=0;i<p[id].kid;++i){
				scanf("%d",&child_id);
				p[id].child.insert(child_id);
			}
		}
		scanf("%d%d",&p[id].house,&p[id].area);
	}
	for(int i=0;i<10000;++i){
		if(p[i].fa==-1 && p[i].ma==-1){
			Family f;
			calculate(p[i],f);
			coll.insert(f);
		}
	}
	printf("%d\n",coll.size());
	copy(coll.begin(),coll.end(),ostream_iterator<Family>(cout,"\n"));

	
	return 0;
}


