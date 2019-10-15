#include <bits/stdc++.h>

using namespace std;

vector<int>G[105];
int level[105], visit[105];
int cs = 1;
int NINF = -1e9;
stack<int>stk;

void DFS(int u)
{
	visit[u] = 1;
	
	for(auto v : G[u]) if(!visit[v]) DFS(v);
	
	stk.push(u);
}

int main()
{	
	while(1){
		int nod, src;
		scanf("%d",&nod);
		if(nod == 0) return 0;
		
		scanf("%d",&src);
		
		for(int i=1 ; i<=nod ; i++){
			 G[i].clear();
			 visit[i] = 0;
			 level[i] = NINF;
		 }
		
		while(1){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u == 0 and v == 0) break;
			G[u].push_back(v);
		}  
		
		level[src] = 0;
		 
		DFS(src);
		
		while(!stk.empty()){
			int u = stk.top();
			stk.pop();
			for(int v : G[u]){
				if(level[v] < level[u]+1){
					level[v] = level[u]+1;
				}
			}
		}
		
		int mx = -1, ep;
		
		for(int i=1 ; i<=nod ; i++) mx = max(level[i], mx);
		for(int i=1 ; i<=nod ; i++){
			if(mx == level[i]){
				ep = i;
				break;
			}
		}
		
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",cs++, src, mx, ep);
		cout<<endl;
	}
	
	return 0;
}
