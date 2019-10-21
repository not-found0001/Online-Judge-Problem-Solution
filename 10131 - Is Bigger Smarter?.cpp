#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e3+5;

map<pair<int,int>,int>MP;
int DP[mxn], Path[mxn];

struct Node{
	int w, iq;
};

vector<Node>v;

bool cmp(Node a, Node b)
{
	if(a.w < b.w) return true;
	else if(a.w == b.w) return (a.iq > b.iq);
	else return false;
}

void solve()
{
	int sz = v.size();
	DP[0] = 1;
	int mx;
	
	for(int i=1 ; i<sz ; i++){
		mx = 1;
		for(int j=0  ; j<i ; j++){
			if(v[j].w < v[i].w and v[j].iq > v[i].iq){
			    int tmp = DP[j] + 1;
			    if(tmp > mx){
					Path[i] = j;
					mx = tmp;
				}	
			}
		}
		DP[i] = mx;
	}
}

int main()
{
	memset(Path, -1, sizeof Path);
	
	Node tmp;
	int x, y;
	int cnt = 1;
	
	while(scanf("%d%d",&x, &y) != EOF){
		MP[{x, y}] = cnt++;
		tmp.w = x; 
		tmp.iq = y;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	solve();
	
	int sz = v.size();
	int Ans = 0, pos = -1;
	
	for(int i=0 ; i<sz ; i++){
		if(DP[i] > Ans){
			Ans = DP[i];
			pos = i;
		}
	}
	
	cout<<Ans<<endl;
	
	vector<pair<int,int>>Pi;
	
	while(Path[pos] != -1){
		Pi.push_back({v[pos].w, v[pos].iq});
		pos = Path[pos];
	}
	
	Pi.push_back({v[pos].w, v[pos].iq});
	reverse(Pi.begin(), Pi.end());
	
	for(auto X : Pi) cout<< MP[{X.first, X.second}] <<endl;
	
	return 0;
}
