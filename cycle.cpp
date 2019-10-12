#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
vector < int > g[maxn];
int par[maxn];
bool visit[maxn], mark[maxn];

bool see_cycle(int u , int pr)
{
    if(visit[u] == false){
        visit[u] = true;
        mark[u] = true;
        par[u] = pr;
        for(auto v : g[u]){
            if(!visit[v] and see_cycle(v , u)){
                return true;
            }
            else if(mark[v] == true){
                int p = v;
                while(par[u] != p){
                    cout << u << " -- > ";
                    u = par[u];
                }
                cout << u << " -- > ";
                cout << p << endl;
                return true;
            }
        }
    }
    mark[u] = false;
    return false;
}

int main()
{
    int node , edge;
    cin >> node >> edge;
    for(int i=1; i<=edge; i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }
	
	bool Ans;
    for(int i=1; i<=node; i++){
        if(visit[i] == false){
            Ans = see_cycle(i , -1);
        }
    }
    
    (Ans == 0) ? cout << "Cycle Not Found" <<endl : cout<< endl;
    
    return 0;
}

