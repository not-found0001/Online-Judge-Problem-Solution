#include <bits/stdc++.h>

using namespace std;

long long arr[505];
long long DP[505][505];
int n;

long long solve(int pos, int tot)
{
	if(pos == n) return (tot == 0);
	
	long long &ret = DP[pos][tot];
	
	if(ret != -1) return ret;
	
	if(tot-arr[pos] >= 0) 
		return ret = solve(pos+1, tot-arr[pos]) + solve(pos+1, tot);
	else return ret = solve(pos+1, tot);
}

int main()
{
	memset(DP, -1, sizeof DP);
	
	scanf("%d",&n);
	
	for(int i=0 ; i<n ; i++) arr[i] = i+1 ;
	
	long long Ans = solve(0, n) - 1 ;
	
	printf("%lld\n",Ans);
	
	return 0;
}
