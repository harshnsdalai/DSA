#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty())
    {
    	int s = q.front();
    	q.pop();
    	cout << s << " ";
    	for(auto x: adj[s])
    	{
    		if (!vis[x])
    		{
    			vis[x] = true;
    			q.push(x);
    		}
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
		bfs(0, adj, vis, V);
		cout << endl;

	}
	
}
