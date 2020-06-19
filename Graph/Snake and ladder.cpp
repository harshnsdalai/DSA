#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define tie() ios_base :: sync_with_stdio(0) ; cin.tie(0); cout.tie(0)

// LEETCODE SOLUTION
// int snakesAndLadders(vector<vector<int>>& board) {
//         unordered_map<int, int> dist = {{1,0}};   
//         queue<int> bfs;
//         bfs.push(1);
//         int n = board.size();
//         int x, a, b, next, i;
        
//         while(!bfs.empty())
//         {
//             x = bfs.front();
//             bfs.pop();
//             for(int j = x + 1; j < x + 7; ++j)
//             {
//                 i = j;
//                 a = (i - 1) / n, b = (i - 1) % n;
//                 if(a&1) next = board[n-a-1][n-b-1];
//                 else next = board[n-a-1][b];

//                 if(next != -1) i = next;
                
//                 if(i>=n*n) return dist[x]+1;
                
//                 if(!dist.count(i))
//                 {
//                     dist[i] = dist[x] + 1;
//                     bfs.push(i);
//                 }
//             }
//         }
//         return -1;
//     }

//////////////////GFG SOLUTION
int snakesAndLadders(vector<int>& board) {
        unordered_map<int, int> dist = {{0,0}};   
        queue<int> bfs;
        bfs.push(0);
        int n = board.size();
        int x, a, b, next, i;
        
        while(!bfs.empty())
        {
            x = bfs.front();
            bfs.pop();
            for(int j = x + 1; j < x + 7; ++j)
            {
                i = j;
                next = board[i];

                if(next != -1) i = next;
                
                if(i>=n) return dist[x]+1;
                
                if(!dist.count(i))
                {
                    dist[i] = dist[x] + 1;
                    bfs.push(i);
                }
            }
        }
        return -1;
    }
int32_t main()
{
    tie();
//     vector<vector<int>> a = {
// {-1,-1,-1,-1,-1,-1},
// {-1,-1,-1,-1,-1,-1},
// {-1,-1,-1,-1,-1,-1},
// {-1,35,-1,-1,13,-1},
// {-1,-1,-1,-1,-1,-1},
// {-1,15,-1,-1,-1,-1}};
//    cout << snakesAndLadders(a);
    int t = 1;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	vector<int> board(30, -1);
    	int a, b;
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> a >> b;
    		board[a-1] = b;

    	}

    	cout << snakesAndLadders(board) << endl;
    }
    

}
