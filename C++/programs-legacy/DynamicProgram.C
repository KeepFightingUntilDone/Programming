#include <iostream>

using namespace std;

const int VOLUME = 20;
const int COUNT = 5;
const int INF = 1000;

int opt[VOLUME][COUNT];
int C[COUNT] = {2,5,8,3,6};
int H[COUNT] = {5,4,2,3,1};
int P[COUNT] = {1,2,4,8,4};

int Cal(int V, int T){
	opt[0][T] = 0;
	for(int i=1; i<=V; i++){
		opt[i][T] = -INF;
	}

	for(int j=T-1; j>=0; j--){
		for(int i=0; i<=V; i++){
			opt[i][j] = -INF;
			for(int k=0; k<= C[j]; k++){
				if(i < k*P[j]){
					break;
				}
				int x = opt[i-k*P[j]][j+1];
				if(x != -INF){
					x += H[j] * k;
					if(x > opt[i][j]){
						opt[i][j] = x;
					}
				}
			}
		}
	}

	return opt[V][0];
}

int main(){
	cout<<Cal(VOLUME, COUNT)<<endl;
	return 0;
}
