#include <bits/stdc++.h>
using namespace std;

void dfsutil(int s, vector<int> adj[], bool vis[])
{
	vis[s] = true;
	stack[s] = true; 
	cout << s << " ";
    for(auto x : adj[s])
    {
    	if (!vis[x] && stack[x] == 0)
    	{
    		
    		dfsutil(x, adj, vis);
    	}
    	else if(stack[x] == 1)
    	{
			return true;
		}
    }
    stack[s] = 0;
}

void dfs(int s, vector<int> adj[], bool vis[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		if (!vis[i])
		{
			dfsutil(i, adj, vis);
		}
	}   
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		int v1, v2, V, E;
		cin >> V >> E;
		vector<int> adj[V];
		for (int i = 0; i < E; ++i)
		{
			cin >> v1 >> v2;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
		bool vis[V] = {false};
		dfs(0, adj, vis, V);
		cout << endl;

	}
	
}
