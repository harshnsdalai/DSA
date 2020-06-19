//----------------------------------------------------------------------------------------------------------------------------------------//
//	 "Programming isn't about what you know; it's about what you can figure out.” 
//                                                                    - Chris Pine
//----------------------------------------------------------------------------------------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define tie() ios_base :: sync_with_stdio(0) ; cin.tie(0); cout.tie(0)
#define debug_1(a) cerr << #a << " " << a << endl;
#define debug_2(a, n) cerr << #a << " ";for(int i=0; i<n;++i){cerr<<a[i]<<" ";} cerr<<endl;
#define debug_3(a) cerr << #a << " ";for(auto x:a){cerr<<x<<" ";} cerr<<endl;

// only declare variable and not assign values to them
const int N = 1e5;
int n;

struct pt{
	double x, y;
};

//Comparison for points to sort after removel of bottom left
//and top right points
bool cmp(pt a, pt b){
	return a.x < b.x || (a.x == b.x and a.y < b.y);
}

//Orientation checking clockwise
bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

//Orientation checking counter-clockwise
bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    //Lower convex from p1 and upper convex from p2
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {

    	// if points lie in upper convex
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
        	//removing previous point which disturbs convex polygon with including new point
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }

        // Same for lower covex
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

void solve()
{
	cin >> n;
	vector<pt> a;
	pt inp;
	for (int i = 0; i < n; ++i)
	{
		cin >> inp.x >> inp.y ;
		a.push_back(inp);
	}
	convex_hull(a);
	sort(a.begin(), a.end(), cmp);
	for(auto i: a){
		cout << i.x << " " << i.y << ", " ;
	} cout << endl;
}
int32_t main()
{
    tie();
    int t = 1;
    cin>>t;
    while(t--)
    {
    	solve();
    	//cerr << "$$$$$$$$$$$$" << endl;
    }
}