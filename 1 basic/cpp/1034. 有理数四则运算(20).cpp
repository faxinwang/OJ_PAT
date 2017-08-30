#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long Long;

using namespace std;

class Fraction{
	public:
		/* m is numerator, n is denominator */
		/* m may be minus, n will always be positive, if n=0 ,the num is infinite */
		Long m,n;
	public:
		Fraction(Long m,Long n):m(m),n(n){
			if(m == 0 || n == 0) return;
			Reduction();
		}
		
		Long GCD(Long a,Long b){
			return b==0? a : GCD(b,a%b);
		}
		
		void Reduction(){
			Long tmp = GCD(abs(m),n);
			m /= tmp;
			n /= tmp;
		}

		Fraction operator+(const Fraction& num){
			return Fraction(m * num.n + n * num.m, n * num.n);
		}
		Fraction operator-(const Fraction& num){
			return Fraction(m * num.n - n * num.m, n * num.n);
		}
		Fraction operator*(const Fraction& num){
			return Fraction(m * num.m, n * num.n);
		}
		Fraction operator/(const Fraction& num){
			if(num.m == 0) return Fraction(1,0); // infinite
			//notice the sign of num.m; 
			return Fraction(m * num.n * (num.m / abs(num.m)), abs(n * num.m));
		}
};

ostream& operator<<(ostream& out, const Fraction& n){
	Fraction num = n;
	if(num.n == 0){	//if the denominator is zero, just output the "Inf"
		printf("Inf");
	}
	else if(num.m == 0){	
		printf("0");	//if the numerator is zero, just output "0"
	}
	else{
		bool flag=false;
		if(num.m<0){
			printf("(-");
			num.m = -num.m;
			flag = true;
		}
		
		if(num.n == 1){	//if the denominator is one, just output the numerator
			printf("%lld",num.m);
		}
		else if(num.m > num.n){
			if(num.m % num.n == 0){
				printf("%lld",num.m/num.n);
			}else{
				printf("%lld %lld/%lld", num.m/num.n, num.m%num.n, num.n);
			}
		}else{
			printf("%lld/%lld",num.m, num.n);
		}
	
		if(flag){
			printf(")");
		}
	}
	return out;
}

int main(){
	Long a,b,c,d;
	scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
	Fraction p(a,b);
	Fraction q(c,d);
	cout<<p<<" + "<<q<<" = "<<p+q<<endl;
	cout<<p<<" - "<<q<<" = "<<p-q<<endl;
	cout<<p<<" * "<<q<<" = "<<p*q<<endl;
	cout<<p<<" / "<<q<<" = "<<p/q<<endl;
	return 0;
}
