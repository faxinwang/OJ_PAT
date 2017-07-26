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
	
	cout<<"ranks:"<<endl;
	copy(stu.begin(),stu.end(),ostream_iterator<Student>(cout,"\n"));

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

/*
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


5 5
1001 5 5 5
1002 4 5 6
1003 6 5 4
1004 2 3 4
1005 4 5 7
ranks:
[ id=1005 ,A=16 ,C=4 ,M=5 ,E=7 1 3 1 1  ]
[ id=1002 ,A=15 ,C=4 ,M=5 ,E=6 2 3 1 2  ]
[ id=1001 ,A=15 ,C=5 ,M=5 ,E=5 2 2 1 3  ]
[ id=1003 ,A=15 ,C=6 ,M=5 ,E=4 2 1 1 4  ]
[ id=1004 ,A=9  ,C=2 ,M=3 ,E=4 5 5 5 4  ]

*/

//http://www.cnblogs.com/Evence/p/4300469.html
