#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>>&a, long long sum, vector<long long>&ans, int i, int j){
    
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    vector<vector<int>>a(n,vector<int>(3,-1));
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a[i][0] = x;
    }

    for(int i=0;i<n;i++){
        int x , y;
        cin >> x >> y;        
        a[i][1] = x;
        a[i][2] = y;
    }
    vector<long long>ans;
    f(a,0,ans,0,0);
    
    long long finalans = 0 ;
    for(int i = 0 ; i < ans.size() ; i++ )
    finalans += ans[i];

    cout<<finalans;
    return 0;
}