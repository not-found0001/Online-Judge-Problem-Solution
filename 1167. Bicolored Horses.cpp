#include <bits/stdc++.h>

using namespace std;

int DP[505][505];
int arr[505];

int solve(int n, int k)
{
	int &ret = DP[n][k];
	
	if(ret != -1) return ret;
	
	ret = 1e8;
	int black = 0, white = 0;
	
	if(k == 1){
		for(int i=1 ; i<=n ; i++){
			if(arr[i] == 0) white++;
			else black++;
		}
		return ret = white*black;
	}
	
	for(int i=n ; i>=k ; i--){
		if(arr[i] == 0) white++;
		else black++;
		ret = min(ret, solve(i-1, k-1) + black*white);
	}
	
	return ret;
}

int main()
{
	memset(DP, -1, sizeof DP);
	
	int n, k;
	
	scanf("%d%d",&n,&k);
	for(int i=1  ; i<=n ; i++) scanf("%d",&arr[i]);
	
	int Ans = solve(n, k);
	
	printf("%d\n",Ans);
	
	return 0;
}
