/*
1006. Sign In and Sign Out (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
At the beginning of every day, the first person who signs in the computer room 
will unlock the door, and the last one who signs out will lock the door. Given 
the records of signing in's and out's, you are supposed to find the ones who 
have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, 
followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no 
more than 15 characters.

Output Specification:
For each test case, output in one line the ID numbers of the persons who have 
unlocked and locked the door on that day. The two ID numbers must be separated 
by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in 
time must be earlier than the sign out time for each person, and there are 
no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:
SC3021234 CS301133

题目大意：
给出同一天中所有人进出的时间和ID，找出最早进入和最后离开的人的ID号 
解题思路：
简单时间的比较，先比时，在比分，最后比秒。 
*/
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
