#include <bits/stdc++.h>

using namespace std;

int N;
bitset < 30 > col, d1, d2;
int board[15][15];

void PrintBoard()
{
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			(board[i][j] == 0) ? cout<<'.'<<" " : cout<<'Q'<<" ";
		}
		cout<<endl;
	}
}

void solve(int r, int& Ans)
{
	if(r == N){
		Ans++;
		PrintBoard();
		return ;
	}
	
	for(int c=0 ; c<N ; c++){
		if(!col[c] and !d1[r+c] and !d2[r-c+N-1]){
			col[c] = d1[r+c] = d2[r-c+N-1] = board[r][c] = 1;
			solve(r+1, Ans);
			col[c] = d1[r+c] = d2[r-c+N-1] = board[r][c] = 0;
		}
	}		
}

int main()
{
	cin>>N;
	
	int Ans = 0;
	
	solve(0, Ans);
	
	cout << Ans <<endl;
	
	return 0;
}
