#include<iostream>
#include<string>
using namespace std;

class Date{
	public:
		int year,month,day;
	public:
		Date():year(0),month(0),day(0){}
		Date(int y,int m,int d):year(y),month(m),day(d){}
		bool operator<(const Date& d){
			if(year != d.year) return year < d.year;
			else if(month != d.month) return month < d.month;
			else return day < d.day; 
		}
		
		bool operator>(const Date& d){
			if(year != d.year) return year > d.year;
			else if(month != d.month) return month > d.month;
			else return day > d.day; 
		}
};



int main(){
	string young,old;
	Date low(1814,9,6),high(2014,9,6);
	Date yd,od;
	char tmp[10];
	int count=0,N;
	int y,m,d;
	
	cin>>N;
	for(int i=0;i<N;++i){
		scanf("%s%d/%d/%d",tmp,&y,&m,&d);
		Date dt(y,m,d);
		if(dt<low || dt>high) continue;
		++count;
		if(count==1){
			old = young = string(tmp);
			od = yd = dt;
		}
		else{
			if(dt < yd){
				yd = dt;
				old = string(tmp);
			}else if(dt > od){
				od = dt;
				young = string(tmp);
			}
		}
	}
	if(count!=0){
		cout<<count<<' '<<old<<' '<<young<<endl;
	}else{
		cout<<"0"<<endl;
	}
	
	
	return 0;
} 
