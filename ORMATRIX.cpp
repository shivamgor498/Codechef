/* shivamgor498
	https://www.codechef.com/COOK96A/problems/ORMATRIX
	*/

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
ll fpow(ll x,ll y){x=x%hell;ll res=1;while(y){if(y&1)res=res*x;res%=hell;y=y>>1;x=x*x;x%=hell;}return res;}
ll inv(ll n){
	return fpow(n,hell-2);
}
ll modmul(ll x,ll y){
    	return (x*1ll*y)%hell;
}
ll modadd(ll x,ll y){
    	ll temp = x%hell + y%hell;
    	temp%=hell;
    	if(temp<0)
    		temp = (temp+hell)%hell;
    	return temp;
}
int main()
{
    	ios
    	ll t;
    	cin >> t;
    	//t = 1;
    	while(t--)
    	{
    		ll n,m;
    		cin >> n >> m;
    		char a[n][m];
    		ll ans[n][m]={-1},cnt = 0;
    		vector<ll>row(1005,0),col(1005,0);
    		/* answer will be 1 for element a[i][j] if in ith row or in jth column count of 1 is atleast 1 else answer is 2,if count of 1 in whole matrix is zero then answer is -1 for each a[i][j]*/
    		for(int i=0;i<n;i++)
    		{
    			string s;
    			cin >> s;
    			for(int j=0;j<s.size();j++)
    			{
    				ans[i][j] = -1;
    				if(s[j]=='1')
    				{
    					ans[i][j] = 0;
    					row[i] = 1;
    					col[j] = 1;
    					cnt++;
    				}
    			}
    		}
    		if(!cnt)
    		{
    			for(int i=0;i<n;i++)
    			{
    				for(int j=0;j<m;j++)
    					cout << -1 << " ";
    				cout << "\n";
    			}
    		}
    		else
    		{
    			for(int i=0;i<n;i++)
    				for(int j=0;j<m;j++)
    					if(ans[i][j]!=0)
    					{
    						if(row[i] || col[j])
    							ans[i][j] = 1;
    						else
    							ans[i][j] = 2;
    					}
    			for(int i=0;i<n;i++)
    			{
    				for(int j=0;j<m;j++)
    					cout << ans[i][j] << " ";
    				cout << "\n";
    			}
    		}
    	}
}     
