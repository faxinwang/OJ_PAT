/*
1012. The Best Rank (25)
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
To evaluate the performance of our first year CS majored students, we consider 
their grades of three courses only: C - C Programming Language, M - Mathematics 
(Calculus or Linear Algebra), and E - English. At the mean time, we encourage 
students by emphasizing on their best ranks -- that is, among the four ranks
with respect to the three courses and the average grade, we print the best rank 
for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as 
the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done t
he best in C Programming Language, while the 2nd one in Mathematics, the 3rd one 
in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 
numbers N and M (<=2000), which are the total number of students, and the number 
of students who would check their ranks, respectively. Then N lines follow, 
each contains a student ID which is a string of 6 digits, followed by the three 
integer grades (in the range of [0, 100]) of that student in the order of C, M 
and E. Then there are M lines, each containing a student ID.

Output
For each of the M students, print in one line the best rank for him/her, and 
the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if 
there are two or more ways for a student to obtain the same best rank, output 
the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output
1 C
1 M
1 E
1 A
3 A
N/A

题目大意：
给出每个学生三门课程的成绩和平均成绩，求每个人最好的排名和对应的排序指标。
如果有多个指标导致相同的最好排名，输出优先级最高的。
例如 1 C 代码在C课程中成绩排名第1

解题思路：
分别根据四种指标排序，每次排序后保存每个人在该指标下的名次，
在输出的时候输出每个人最高的排名和对应的排序指标。 
*/

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<iterator>
using namespace std;


class Student{
	public:
		int score[4];//store the score of C,M,E and mean value of them
		int rank[4];//store the rank of A,C,M,E 
		int id;
		
	public:
		Student(int id,int c=0,int m=0,int e=0):id(id){
			score[1]=c;
			score[2]=m;
			score[3]=e;
			score[0]=score[1]+score[2]+score[3];
		}
		friend ostream& operator<<(ostream& out,const Student& s);
};


bool operator==(const Student& s1,const Student& s2){
	return s1.id==s1.id;
}

ostream& operator<<(ostream& out,const Student& s){
		out.setf(ios::fixed,ios::floatfield);
	out<<"[ id="<<s.id
	   <<setprecision(1)
	   <<" ,A="<<s.score[0]
	   <<setprecision(0)
	   <<" ,C="<<s.score[1]
	   <<" ,M="<<s.score[2]
	   <<" ,E="<<s.score[3]
	   <<' ';
	   for(int i=0;i<4;++i)
			out<<s.rank[i]<<' ';
	   out<<" ]";
	   
	return out;
}


//sort the students by their scores according to different sort criterion
bool sortByA(const Student& s1,const Student& s2){
	return s1.score[0]>s2.score[0];
}
bool sortByC(const Student& s1,const Student& s2){
	return s1.score[1]>s2.score[1];
}
bool sortByM(const Student& s1,const Student& s2){
	return s1.score[2]>s2.score[2];
}
bool sortByE(const Student& s1,const Student& s2){
	return s1.score[3]>s2.score[3];
}

//ranking according to score[idx]
void makeRank(vector<Student> &v,int idx){
	v[0].rank[idx] = 1;
	for(int i=1;i<v.size();++i)
		if( v[i].score[idx] == v[i-1].score[idx] )
			v[i].rank[idx]=v[i-1].rank[idx];
		else
			v[i].rank[idx]=i+1;//process the same score case.
			//分数相同，并列排名【思维】：和前一个排名相同，不同则i+1
}


int main(){
	int id;
	int c,m,e;
	int N,M;
	typedef vector<Student> StudColl;
	StudColl stu;
	cin>>N>>M;
	stu.reserve(N);

	while(N--){
		cin>>id>>c>>m>>e;
		stu.push_back(Student(id,c,m,e));
	}
//sort to make ranks
	sort(stu.begin(),stu.end(),sortByA);
	makeRank(stu,0);
	
	sort(stu.begin(),stu.end(),sortByC);
	makeRank(stu,1);
	
	sort(stu.begin(),stu.end(),sortByM);
	makeRank(stu,2);
	
	sort(stu.begin(),stu.end(),sortByE);
	makeRank(stu,3);
	
//	cout<<"ranks:"<<endl;
//	copy(stu.begin(),stu.end(),ostream_iterator<Student>(cout,"\n"));

	while(M--){
		bool find=false;
		char ch;
		int rank;
		cin>>id;
		//to find the highest rank for student having ID id and corresponding subject
		for(int i=0;i<stu.size();++i)
			if(id==stu[i].id){
				rank=stu[i].rank[0];
				ch='A';
				if(rank>stu[i].rank[1]){
					rank=stu[i].rank[1];
					ch='C';
				}
				if(rank>stu[i].rank[2]){
					rank=stu[i].rank[2];
					ch='M';
				}
				if(rank>stu[i].rank[3]){
					rank=stu[i].rank[3];
					ch='E';
				}
				find=true;
				break;
			}
			
		//output the result
		if(find){
			cout<<rank<<" "<<ch<<endl;
		}else{
			cout<<"N/A"<<endl;
		}
	}
	
	return 0;
}

