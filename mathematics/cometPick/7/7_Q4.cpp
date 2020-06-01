#include <iostream>
using namespace std;

int num_arr[12] = {1,1,1,2,2,2,3,3,3,4,4,5};
int visit[12];
int ans[2];

void func(int dep = 0){
	if(dep == 3){
		int chk[6] = {0,};
		int flag = 1;
		for(int i=0; i<12; i++){
			chk[num_arr[i]] += visit[i];
		}
		for(int i=1; i<=5; i++){
			if(chk[i] >= 2){
				flag = 0;
				break;	
			}
		}
		if(flag){
			ans[0]++;
			if(visit[0] + visit[3] + visit[6] + visit[9] + visit[11] == 3)
				ans[1]++;
		}
		return;
	}
	for(int i=0; i<12; i++){
		if(visit[i]) continue;
		visit[i] = 1;
		func(dep+1);
		visit[i] = 0;
	}
}

int gcd(int A, int B){
	while(A){
		int temp = A;
		A = B%A;
		B = temp;
	}
	return B;
}

int main(){
	func();
	int g = gcd(ans[1], ans[0]);
	printf("%d/%d", ans[1]/g, ans[0]/g); 
	return 0;
}
