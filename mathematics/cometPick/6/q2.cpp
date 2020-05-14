#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
    while(a){
        long long t = a;
        a = b%a;
        b = t;
    }
    return b;
}

inline int checkVec(vector<int> &V){
    if(V[0] == 0) return -1;
    if((V[0] + V[3])%2 == 0) return 1;
    if((V[1]*V[2])%2 == 1) return 1;
    return 0;
}

int main(){
    vector<int> V = {0, 1, 2, 3, 4, 5};
    long long tot = 0, n = 0;

    do{
        int C = checkVec(V);
        if(C == 1) n++;
        if(C != -1) tot++;
    }while(next_permutation(V.begin(), V.end()) && next_permutation(V.begin(), V.end())); //what needed is first 4 digit, so skip 2 permutation.

    long long k = gcd(tot, n);
    cout << n/k << "/"  << tot/k;

    return 0;
}