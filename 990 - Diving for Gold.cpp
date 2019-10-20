#include <bits/stdc++.h>

using namespace std;

int DP[35][1005], path[35][1005];
int weight[1005], cost[1005], tmp[1005];
vector<int>res;
int cap, w, n;

int solve(int pos, int capa)
{
	if(pos == n) return 0;
	
	int &ret = DP[pos][capa];
	
	if(ret != -1) return ret;
	
	int profit1 = 0, profit2 = 0;
	
	profit1 = solve(pos+1, capa);
	if(capa+weight[pos] <= cap){
		profit2 = cost[pos] + solve(pos+1, capa+weight[pos]);
	}
	
	if(profit1 < profit2) path[pos][capa] = 1;
	else path[pos][capa] = 2;
	
	return ret = max(profit1, profit2);
}

void PrintDP(int pos, int capa)
{
	if(path[pos][capa] == -1) return ;
	
	if(path[pos][capa] == 1){
	    res.push_back(pos);
	    PrintDP(pos+1, capa+weight[pos]);
	}
	else{
		PrintDP(pos+1, capa);
	}
}

int main()
{
	bool bl = false;
	while(scanf("%d%d",&cap,&w)!=EOF){
		
		memset(DP, -1, sizeof DP);
		memset(path, -1, sizeof path);
		res.clear();
		
		scanf("%d",&n);
		for(int i=0 ; i<n ; i++){
			int x, y;
			scanf("%d%d",&x,&y);
			weight[i] = (w*x) + ((2*w)*x);
			tmp[i] = x;
			cost[i] = y;
		}
		
		if(bl) printf("\n");
		bl = true;
		
		int Ans = solve(0, 0);
		
		PrintDP(0, 0);
		
		int sz = res.size();
		printf("%d\n%d\n",Ans, sz);
		
		for(auto X : res) printf("%d %d\n",tmp[X], cost[X]);
	}
	
	return 0;
}

