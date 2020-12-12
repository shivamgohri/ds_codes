#include<bits/stdc++.h>
using namespace std;
void dfs(int vertex, vector<bool>& visited, vector<vector<long long int>>& g){
	visited[vertex]=true;
	for(auto i:g[vertex]){
		if(!visited[i])
			dfs(i,visited,g);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,roads;
	cin>>n>>roads;
	vector<vector<long long int>> g(n);
	for(int i=0;i<roads;i++){
		long long int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<long long int> ans;
	vector<bool> visited(n,false);
	dfs(0,visited,g);
	for(int i=1;i<n;i++){
		if(!visited[i]){
			ans.push_back(i);
			dfs(i, visited, g);
		}
	}
	if(ans.size()==0)
		cout<<0;
	else{
		cout<<ans.size()<<"\n";
		for(auto i:ans)
			cout<<"1 "<<i+1<<"\n";
	}
	return 0;
	
}