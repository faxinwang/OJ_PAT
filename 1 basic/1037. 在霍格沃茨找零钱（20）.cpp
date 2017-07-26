#include<iostream>
#include<cstdio>
using namespace std;


class Currency{
  public:
    int galleon,sickle,knut;
  public:
    Currency(int g, int s, int k):galleon(g),sickle(s),knut(k){}
    bool operator<(const Currency& c2){
    	if(galleon != c2.galleon) return galleon < c2.galleon;
    	else if(sickle != c2.sickle) return sickle < c2.sickle;
    	else return knut < c2.knut;
	}
    Currency operator-(Currency& c2){
	    bool flag = false;
	    if(*this < c2){
	    	Currency t = *this;
	    	*this = c2;
	    	c2 = t;
	    	flag = true;
		}
	    int i,k,s,g;
	    k = knut;
	    for(i=0; i*29+k < c2.knut;++i);
	    k = i * 29 + k - c2.knut;
	    s = sickle - i;
	    for(i=0; i*17 + s < c2.sickle; ++i);
	    s = i * 17 + s - c2.sickle;
	    g =  galleon- i - c2.galleon;
	    if(flag) g=-g;
	    return Currency(g,s,k);
    }
};

ostream& operator<<(ostream& out, const Currency& cur){
  return out<<cur.galleon<<"."<<cur.sickle<<"."<<cur.knut;
}

int main(){
  int gg,ss,kk;
  scanf("%d.%d.%d",&gg,&ss,&kk);
  Currency c1(gg,ss,kk);
//  cout<<c1<<endl;
  scanf("%d.%d.%d",&gg,&ss,&kk);
  Currency c2(gg,ss,kk);
//  cout<<c2<<endl;
  cout<<c2 - c1<<endl;
  
  return 0;
}
