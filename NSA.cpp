/* shivamgor498
	https://www.codechef.com/problems/NSA
	*/

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell LLONG_MAX
#define pb push_back
#define x first
#define y second
using namespace std;
int main()
{
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		string s;
		cin >> s;
		ll n = s.size(),y=0;
		if(n==1)
		{
			cout << 0 << "\n";
			continue;	
		}
		/* solution for this problem is simple just calculate initial value of y and replace each character of string with each alphabet and calculate new value let it be yn and x be absolute difference between character in string and alphabet and find minimum for better explanation please visit editorial - https://discuss.codechef.com/questions/131400/nsa-editorial */
		ll pre[n][26] = {0},suff[n][26] = {0};
		for(int i=0;i<26;i++)
			pre[0][i] = 0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<26;j++)
			{
				pre[i][j] = pre[i-1][j];
				suff[n-i-1][j] = suff[n-i][j];
				if((s[i-1]-'a')<j)
					pre[i][j]++;
				if((s[n-i]-'a')>j)
					suff[n-i-1][j]++;
			}
			y+=pre[i][s[i]-'a'];
		}
		ll ans = y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<26;j++)
				ans = min(ans,y-pre[i][s[i]-'a']-suff[i][s[i]-'a']+pre[i][j]+suff[i][j]+abs(s[i]-'a'-j));
		}
		cout << ans << "\n";
	}
}
