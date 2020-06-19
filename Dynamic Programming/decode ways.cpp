#include<iostream>
#include<string.h>
using namespace std;
/////////////s.substring takes starting index and numbers of characters
class Solution {
public:
    int numDecodings(string s) {
       if (s.length() == 0) {
            return 0;
        }
       	int n = s.length();

        int dp[n + 1];

       memset(dp, 0, sizeof(dp));
       dp[0] = 1;
       dp[1] = s[0] != '0' ? 1 : 0;

       for(int i = 2;i < n+1;++i){

            if(0< stoi(s.substr(i-1, 1))){
                dp[i]+=dp[i-1];

            }
             if(10<=stoi(s.substr(i-2, 2))
              and stoi(s.substr(i-2, 2))<=26){
                 dp[i]+=dp[i-2];

             }
       }
    return dp[n];
	}
};

int main(){
Solution a;
cout << a.numDecodings("12120") <<"Adsf"<< endl;
string u = "10";
cout << u.substr(1,2);
string s1 = "Geeks"; 
  
    // Copy three characters of s1 (starting  
    // from position 1) 
    cout << s1.substr(1, 3); 
}