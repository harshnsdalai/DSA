#include <bits/stdc++.h>
using namespace std;
#define debug_1(a) cerr << #a << " " << a << endl;
#define debug_2(a, n) cerr << #a << " ";for(int i=0; i<n;++i){cerr<<a[i]<<" ";} cerr<<endl;
#define debug_3(a) cerr << #a << " ";for(auto x:a){cerr<<x<<" ";} cerr<<endl;

class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());
        debug_3(nums)
        int n = nums.size();
        
        set<vector<int>> s;
        for (int i = 0; i < n ; ++i)
        {

        	int li = i+1;
        	int ri = n-1;
        	int sum ;
        	while(li<ri)
        	{
        		sum = nums[li] + nums[ri] + nums[i];
        		if (sum == 0)
	        	{
	        		//cout << nums[i] << li << ri << sum;
	        		cout << nums[i] << nums[li] << nums[ri] << endl;
	        		s.insert({nums[i], nums[li], nums[ri]});
	        	}
        		if (sum<0)
        		{
        			li++;
        		}else if (sum>0)
        		{
        			ri--;
        		}else
        		{
        			if (li<n-2 and ri>0)
        			{
        				li--, ri--;
        			}
        			else break;
        		} 
        	}
        	

        }
        vector<vector<int>> v(s.begin(), s.end());
        return v;
    }
};


int main()
{
	vector<int> a =  {-2,0,1,1,2};

	Solution A;
	vector<vector<int>> v = A.threeSum(a);
	for(auto x: v)
	{
		for(auto y: x)
		{
			cout << y << " ";
		}
		cout << endl;
	}

}