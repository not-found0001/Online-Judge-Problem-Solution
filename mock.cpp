#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair < int , int >, null_type, less<pair < int , int > >, rb_tree_tag,
                tree_order_statistics_node_update> Ordered_Set;

const int mxn = 1e5 + 10;
int parent[mxn];
int cs = 1;

Ordered_Set st[mxn];

int Find(int u)
{
    if(parent[u] == u) return u;
    else return parent[u] = Find(parent[u]);
}

void Merge(int u , int v)
{
    u = Find(u);
    v = Find(v);

    if(u == v)return;

    if(st[u].size() >= st[v].size()){
        parent[v] = u;
        for(auto X : st[v]) st[u].insert(X);
    }
    else{
        parent[u] = v;
        for(auto X : st[u]) st[v].insert(X);
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n, q;
        int ct = 1;
        scanf("%d%d",&n,&q);
        for(int i = 0; i <= n; i++) st[i].clear();
        for(int i = 1; i <= n; i++) parent[i] = i;
        printf("Case %d:\n",cs++);
        while(q--){
            int type;
            scanf("%d",&type);
            if(type == 0){
                int u, v;
                scanf("%d%d",&u,&v);
                Merge(u,v);
            }
            else if(type == 1){
                int u, t;
                scanf("%d%d",&u,&t);
                u = Find(u);
                st[u].insert({t,ct++});
            }
            else{
                int u, l, r;
                scanf("%d%d%d",&u,&l,&r);
                u = Find(u);
                int Ans = st[u].order_of_key({r+1,-1}) - st[u].order_of_key({l,-1});
                printf("%d\n",Ans);
            }
        }
    }

    return 0;
}
