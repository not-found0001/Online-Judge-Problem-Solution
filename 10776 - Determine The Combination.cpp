#include <bits/stdc++.h>

using namespace std;

int n, len;
string str;
vector<char>Ans;

void BackTrack(int pos)
{
	if(Ans.size() == n){
		for(auto X : Ans) cout<<X;
		cout<<endl;
		return ;
	}
	
	for(int i = pos ; i < len ; i++){
		Ans.push_back(str[i]);
		BackTrack(i+1);
		Ans.pop_back();
		
		while(str[i] == str[i+1]) i++;
	}
}

int main()
{
	while(cin>>str>>n){
		len = str.size();
		sort(str.begin(), str.end());
		BackTrack(0);
	}
	
	return 0;
}
