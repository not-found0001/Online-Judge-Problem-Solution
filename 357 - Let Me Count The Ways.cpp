#include <bits/stdc++.h>

using namespace std;

int coin[] = {1, 5, 10, 25, 50};

long long DP[5][30005];

long long rec(int pos, long long tk)
{
	if(pos == 5) return (tk == 0);
	
	long long &ret = DP[pos][tk];
	
	if(ret != -1) return ret;
	
	long long Ans1 = 0, Ans2 = 0;
	
	Ans1 = rec(pos+1, tk);
	
	if(tk >= coin[pos]) Ans2 = rec(pos, tk-coin[pos]);
	
	return ret = (Ans1 + Ans2);
}

int main()
{
	memset(DP, -1, sizeof DP);
	
	long long tk;
	while(scanf("%lld",&tk) != EOF){
		long long Ans = rec(0,tk);
		
		if(Ans > 1) printf("There are %lld ways to produce %lld cents change.\n",Ans,tk);
		else printf("There is only %lld way to produce %lld cents change.\n",Ans,tk);
	}
	
	return 0;
}
