#include <stdio.h>

const int DICE_CNT = 4;
const int DICE_MIN = 1;
const int DICE_MAX = 6;
const int MAX_MUL = 20;

long long gcd(long long a, long long b){
    while(a){
        long long t = a;
        a = b%a;
        b = t;
    }
    return b;
}

long long rolling_dice(int T, int m, int M){
    if(!T){
        return (long long)(m*M < MAX_MUL);
    }

    long long sum = 0;
    for(int i=DICE_MIN; i<=DICE_MAX; i++){
        sum += rolling_dice(T-1, m<i?m:i, M>i?M:i);
    }
    return sum;
}


int main(){
    long long n = rolling_dice(DICE_CNT, DICE_MAX, DICE_MIN);
    long long k = 6ll*6ll*6ll*6ll;
    long long g = gcd(n, k);
    printf("%lld / %lld", n/g, k/g);
    return 0;
}