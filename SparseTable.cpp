#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 100;

int ST[mxn][20];
int arr[mxn];

int main()
{
	int n;

	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
		ST[i][0] = arr[i];
	}

	for(int j=1 ; (1<<j)<=n ; j++){
		for(int i=0 ; (i+(1<<j))<=n ; i++){
			ST[i][j] = min(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
		}
	}
	
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		int lo = log(r-l+1);
		cout<< min( ST[l][lo], ST[r-(1<<lo)+1][lo]) <<endl;
	}

	return 0;
}
