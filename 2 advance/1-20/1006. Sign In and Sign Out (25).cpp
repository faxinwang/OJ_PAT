#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class DayTime{
	private:
		int hour,minute,second;
	public:
		DayTime(int h,int m,int s):hour(h),minute(m),second(s){}
		bool operator<(const DayTime& dt){
			if(hour<dt.hour) return true;
			else if(hour==dt.hour){
				if(minute<dt.minute) return true;
				else if(minute==dt.minute)
					return second<dt.second;
			}
			return false;
		}
		bool operator>(const DayTime& dt){
			return !(*this<dt);
		}
		void set(int h,int m,int s){
			hour=h;
			minute=m;
			second=s;
		}
}; 


int main(){
	DayTime min(23,59,59),max(0,0,0);
	string inid,outid,tmp;
	int M,h,m,s;
	cin>>M;
	while(M--){
		cin>>tmp;
		scanf("%d:%d:%d",&h,&m,&s);
		if(min>DayTime(h,m,s)){
			min.set(h,m,s);
			inid=tmp;
		}
		scanf("%d:%d:%d",&h,&m,&s);
		if(max<DayTime(h,m,s)){
			max.set(h,m,s);
			outid=tmp;
		}
	}
	cout<<inid<<' '<<outid<<endl;
	
	return 0;
}
