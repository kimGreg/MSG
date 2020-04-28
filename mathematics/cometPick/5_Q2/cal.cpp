#include <cstdio>
using namespace std;
using ll = long long;

const int A = 5, B = 10;

ll d[A+2][B+2]; // d[i][j] = number of cases when the number of multiples of 3 is i and the number of non-multiples of 3 is j

ll gcd(ll a, ll b){ // Euclidean algorithm
	while(a){
		ll temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}

ll fact(int k){  // factorial
	ll a=1;
	for(; k; a*=(k--));
	return a;
}

void fill_table(){
	d[0][0] = 1;
	for(int i=0; i<A; i++){
		for(int j=0; j<B; j++){
			d[i+1][j] += d[i][j]*(A-i);
			d[i][j+1] += d[i][j]*(B-j);
		}
	}
}

ll get_ans(){
	ll a = 0, b = 0;
	
	for(int i=0; i<B; i++){
		a += d[A][i] * fact(B-i); // multiply (10-i)! instade of (10-i)!/15!
	}
	for(int i=0; i<A; i++){
		b += d[i][B] * fact(A-i); // multiply (5-i)! instade of (5-i)!/15!
	}

	ll total = a+b;
	ll Gcd = gcd(a, total);

	return a/Gcd + total/Gcd; // a/Gcd : numerator, total/Gcd : denominator
}

int main(){
	fill_table();
	ll ans = get_ans();
	printf("%lld", ans);
	return 0;
}
