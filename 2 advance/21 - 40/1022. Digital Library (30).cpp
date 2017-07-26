#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
/*
��Ŀ���⣺
����N�������Ϣ��ID,title,author,keywords,publisher,publish year,
����keywords�ɶ��������ɣ���year�⣬�����Ӷ��п����пո� 
����M����ѯ��ÿ����ѯ�������Ӷ��е�ĳһ����
��ÿ����ѯ���������������ܶ�Ӧ��ID��
 
����˼·:
����title,author,keyword, publisher,year�����ID����һ�Զ�Ĺ�ϵ,
���Խ�ͬһtitle������ID���ŵ�һ��set<string>��ȥ��
Ȼ�����е�title�����Ӧ��set<string>���ŵ�map<string,set<string> > ��ȥ 
����һ���ҵ�ĳ��title��Ӧ�������ID��
�����Ӷζ���ͬ���Ĵ��� 
*/

map<string,set<string> > titles; //����һ��title��Ӧ���������id
map<string,set<string> > authors;
map<string,set<string> > keys;
map<string,set<string> > publishers;
map<string,set<string> > years;

int main(){
#ifdef WFX
freopen("1022 in.txt","r",stdin);
#endif 
	int N;
	string id,title,auth,words,pub,year;
	string key;
	scanf("%d",&N); //scanf()�����ȡ����Ļ��з� 
	getchar(); //������Ҫ��getchar()����ȡ������Ļ��з� 
	while(N--){
		getline(cin,id); //getline()��һ����ȡ�����з�����������ӵ��ַ�����
		
		getline(cin, title);
		titles[title].insert(id);
		
		getline(cin,auth);
		authors[auth].insert(id);
		
		getline(cin,words);
		stringstream ss(words);
		while(ss>>key) keys[key].insert(id);
		
		getline(cin,pub);
		publishers[pub].insert(id);
		
		getline(cin,year);
		years[year].insert(id);
	}
	
	int M;
	string query;
	scanf("%d",&M);  
	getchar();
	while(M--){
		getline(cin,query);
		cout<<query<<endl;
		char ch  = query[0];
		query = query.substr(3);
		set<string>* s=0;
	
		switch(ch){
		case '1': s = titles.find(query) != titles.end()? 		&titles[query] : 0 ;		break;
		case '2': s = authors.find(query) != authors.end()? 	&authors[query] : 0;	 	break;
		case '3': s = keys.find(query) != keys.end()? 			&keys[query]: 0; 			break;
		case '4': s = publishers.find(query)!= publishers.end()? &publishers[query]:0;		break;
		case '5': s = years.find(query) != years.end()? 		&years[query]:0;			break;
		}
		if(s != 0)
			copy(s->begin(),s->end(),ostream_iterator<string>(cout,"\n"));
		else
			cout<<"Not Found"<<endl;
	}
	
	
	return 0;
}
