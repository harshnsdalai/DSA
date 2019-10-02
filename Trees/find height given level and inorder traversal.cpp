#include<bits/stdc++.h>

using namespace std;

unordered_map <int,int> mapp;

int minHeight(vector<int> &inorder, int ss, int se)
{
    if(ss>se) return 0;
    int ll = 0, rr = 0, mini=ss;

    for(int i=ss+1;i<=se;i++)
    {
        if(mapp[inorder[i]]<mapp[inorder[mini]])
            mini = i;
    }

    ll = minHeight(inorder, ss, mini-1);
    rr = minHeight(inorder, mini+1, se);
    return 1+max(ll,rr);
}

int main()
{
    int n=7;
    int arr1[n]={4,2,5,1,6,3,7}, arr2[n]={1,2,3,4,5,6,7};
    vector <int> inorder(n), level(n);
    for(int i=0;i<n;i++)
    {
        inorder.at(i) = arr1[i];
        mapp[arr2[i]]=i;
    }
    cout<<minHeight(inorder, 0, n-1)<<"\n";
    return 0;
}
