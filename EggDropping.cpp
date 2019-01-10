#include <iostream>

#define MAX 101

using namespace std;

int DP[MAX][MAX]; // DP of size n*k -- k = #floors , n = #eggs
	// DP[i][j] contains minimum no of trials needed to determine the critical 
	// floor if i eggs were given and j floor were given

int max(int a,int b){
	return a>b?a:b;
}

int EggDropping(int k,int n){
	for(int i=0;i<=k;i++)
		DP[1][i] = i;
	for(int i=0;i<=n;i++)
		DP[i][1] = 1;
	
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			DP[i][j] = MAX;
			for(int x = 1;x<=j;x++){
				int maxTrials = 1 + max(DP[i-1][x-1],DP[i][j-x]);
				// here we use DP[i-1]"[x-1]" because we are calculating minimum 
				// "no of trials" not the "Critical floor" so we don't consider 
				 // x'th floor again.
				// max function is used becuase we are looking for worst case
				// not the best case
				if(maxTrials < DP[i][j])
					DP[i][j] = maxTrials;
			}
		}
	}

	return DP[n][k];
}

int main(int argc, char const *argv[])
{
	/* code */
	int testCases;
	int n,k;
	cin>>testCases;
	while(testCases--){
		cin >> n;
		cin >> k;
		cout << EggDropping(k,n) << endl;
 	}
	return 0;
}