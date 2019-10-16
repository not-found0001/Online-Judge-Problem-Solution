#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5;

int DP[mxn];
int cs = 1;

int solve(vector<int>& stor)
{
	DP[0] = 1;
	
	int Ans = 0;
	int n = stor.size();
	
	for(int i=1 ; i<n ; i++){
		int mx = 1;
		for(int j=0 ; j<i ; j++){
			if(stor[j] > stor[i]){
				int tmp = 1 + DP[j];
				mx = max(mx, tmp);
			}
		}
		DP[i] = mx;
		Ans = max(Ans, mx);
	}
	
	return Ans;
}

int main()
{
    vector<int>stor;
    
    int num;
    
    string sep = "";
    
    while(cin>>num, num != -1){
        stor.clear();
        stor.push_back(num);
        
        while(cin>>num, num != -1) stor.push_back(num);
        
        cout << sep << "Test #" << cs++ << ":\n  maximum possible interceptions: " << solve(stor) << '\n';
        sep = "\n";
    }
    
    return 0;
}
