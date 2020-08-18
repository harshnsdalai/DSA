#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        map<char, int> pat, str;
        for(auto x: t) pat[x]++;
        int counter = t.length(), start = 0, ans = INT_MAX, start_ind = -1;
        for(int i = 0; i< s.length(); i++)
        {
            str[s[i]]++;

            if(str[s[i]]<=pat[s[i]] and pat[s[i]]!=0)
            {
                counter -- ;
            }
            if (counter == 0)
            {   
                while(str[s[start]]>pat[s[start]] or pat[s[start]]==0)
	            {
	            	if(str[s[start]]>pat[s[start]])
    	            {
    	                str[s[start]]--;
    	            }
	            	start++;
	            }
	           	int window = i-start+1;
            	
            	if (ans>window)
	            {
	                ans = window;
	                start_ind = start;
	            }
            }   
        }
        if(start_ind == -1) return "";
        return s.substr(start_ind, ans);
        
    }
};
int main()
{
	Solution A;
	string s= "ADOBECODEBANC", t = "ABC";
	cout << A.minWindow(s, t) << endl;
}