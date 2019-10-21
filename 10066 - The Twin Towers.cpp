#include <bits/stdc++.h>

using namespace std;

const int mxn = 105;

int DP[mxn][mxn];
int visit[mxn][mxn];
int arr1[mxn], arr2[mxn];
int n1, n2, tot, cs = 1 ;

int Func(int i, int j)
{
	if(i == n1 or j == n2) return 0;
	
	int &ret = DP[i][j];
	
	if(visit[i][j] == tot) return ret;
	visit[i][j] = tot;
	
	if(arr1[i] == arr2[j]){
		return ret = 1 + Func(i+1, j+1);
	}
	else{
		int tmp1 = Func(i+1, j); 
		int tmp2 = Func(i, j+1);
		return ret = max(tmp1, tmp2);
	} 
}

int main()
{
	while(1){
		
		tot += 2;
		
		scanf("%d%d",&n1,&n2);
		if(!n1 and !n2) break;
		
		for(int i=0 ; i<n1 ; i++) scanf("%d",&arr1[i]);
		for(int i=0 ; i<n2 ; i++) scanf("%d",&arr2[i]);
		
		printf("Twin Towers #%d\n",cs++);
		int Ans = Func(0, 0);
		printf("Number of Tiles : %d\n",Ans);
		puts("");
	}
	
	return 0;
}
