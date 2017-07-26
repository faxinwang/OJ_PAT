#include<bits/stdc++.h>
using namespace std;

int toll[24];

//几个PhoneCall记录 
struct Call{
	int dd,hh,mm,time;
	string flag;
	//time保存从月初到当前时刻的分钟数 
	Call(int d,int h,int m,string f):dd(d),hh(h),mm(m),flag(f){
		time = d*24*60 + h*60 + m;
	}
	bool operator<(const Call& call)const{
		return time<call.time;
	}
};

//返回从月初开始算起的花费总额 
double chargeByTime(Call& c){
	double fee = 0;
	double feePerDay = 0;
	for(int h=0;h<24; ++h) feePerDay += toll[h]*60;
	fee += feePerDay * c.dd;
	for(int h=0;h<c.hh; ++h) fee += toll[h]*60;
	fee += toll[c.hh]*c.mm;
	return fee;
}

//计算从s到e的话费额度 
double Fee(Call& s, Call& e){
	return (chargeByTime(e) - chargeByTime(s)) / 100;
}


int main(){
#ifdef WFX
freopen("1016 in.txt","r",stdin);
#endif 
	string name,flag;
	map<string,vector<Call> > mp;
	int N,mon,d,h,m;
	for(int i=0;i<24;++i) scanf("%d",toll+i);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		cin>>name;
		scanf("%d:%d:%d:%d",&mon,&d,&h,&m);
		cin>>flag;
		mp[name].push_back(Call(d,h,m,flag));
	}
	map<string,vector<Call> >::iterator pos;
	for(pos=mp.begin(); pos!=mp.end(); ++pos){
		vector<Call> &v = pos->second;
		sort(v.begin(),v.end());
		vector<Call> v2;
		//先找出所有合法的记录 
		for(int i=0,len=v.size()-1; i<len;++i){
			if(v[i].flag=="on-line" && v[i+1].flag=="off-line"){
				v2.push_back(v[i]);
				v2.push_back(v[i+1]);
				++i; 
			}
		}
		//如果合法记录不为空 
		if(v2.size()){
			//输出姓名和月份 
			printf("%s %02d\n",pos->first.c_str(), mon);
			double sum=0,fee;
			for(int i=0,len=v2.size()-1; i<len;i+=2){
				int diff = v2[i+1].time - v2[i].time;//通话分钟数 
				fee = Fee(v2[i],v2[i+1]); //该笔通话费用 
				sum += fee;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
					v2[i].dd, v2[i].hh, v2[i].mm, 
					v2[i+1].dd, v2[i+1].hh, v2[i+1].mm,diff,fee);
			}
			printf("Total amount: $%.2lf\n",sum);
		}
	}
	
	return 0;
}
