#include <bits/stdc++.h>

using namespace std;

vector<int>G[105];
int visit[105];
stack<int>stk;
int cnt;

int DFS(int u)
{
	if(visit[u]) return 0;
	
	visit[u] = 1;
	cnt++;
	
	for(auto v : G[u]) DFS(v);
	
	return cnt;
}

int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		
		if(n == 0) break;
		
		for(int i=1 ; i<=n ; i++){
			G[i].clear();
			visit[i] = 0;
			int x;
			scanf("%d",&x);
			for(int j=1 ; j<=x ; j++){
				int p;
				scanf("%d",&p);
				G[i].push_back(p);
			}
		}
			
		int mx = -1, res;
		for(int i=1 ; i<=n ; i++){
			memset(visit, 0, sizeof visit);
			cnt = 0;
			int Ans = DFS(i);
			if(Ans > mx){
				mx = Ans;
				res = i;
			}
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}
