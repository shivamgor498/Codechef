/* shivamgor498
	https://www.codechef.com/LTIME62A/problems/FRCPRT
	Explanation :- First move matters because it makes all particles to one of the corner and then last horizontal and vertica moves matters for example once first move is done all particles are in one of the corner then if apply:-
	1) UUUUUUUUUUUUUUUUUUUUUU it is equivalent to single U operation
	2) UUUUUUUUUUUDDDDDDUUUUD it is equivalent to single D operation
	so we calculate last horizontal move and last vertical move and first move and apply it in order */
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define unsigned long long int ull;
#define MAXL 1000006
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
int main(){
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--){
		ll n,m;
		cin >> n >> m;
		ll a[n][m];
		string s;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				char c;
				cin >> c;
				if(c=='1')
					a[i][j] = 1;
				else
					a[i][j] = 0;
			}
		cin >> s;
		string move;
		move = "";
		bool hh = false,vv = false;
		for(int i=s.size()-1;i>=0;i--)
		{
			if(!hh && (s[i]=='L' || s[i]=='R'))
			{
				move+=s[i]; // last horizontal move
				hh = true;
			}
			else if(!vv && (s[i]=='U' || s[i]=='D'))
			{
				move+=s[i]; // last vertical move
				vv = true;
			}
			else if(hh && vv)
				break;
		}
		move+=s[0]; // first move
		reverse(move.begin(),move.end()); //apply in order i.e. first move then last moves
		for(int l=0;l<move.size();l++)
		{
			if(move[l]=='L') // left move
			{
				for(int i=0;i<n;i++)
				{
					ll cnt = 0;
					for(int j=0;j<m;j++)
					{
						if(a[i][j])cnt++;
						a[i][j] = 0;
					}
					for(int j=0;j<cnt;j++)
						a[i][j] = 1;
				}	
			}
			else if(move[l]=='R') // right move
			{
				for(int i=0;i<n;i++)
				{
					ll cnt = 0;
					for(int j=0;j<m;j++)
					{
						if(a[i][j])cnt++;
						a[i][j] = 0;
					}
					if(cnt)
						for(int j=m-1;j>=0;j--)
						{
							a[i][j] = 1;
							cnt--;
							if(!cnt)
								break;
						}
				}
			}
			else if(move[l]=='U') // up move
			{
				for(int i=0;i<m;i++)
				{
					ll cnt = 0;
					for(int j=0;j<n;j++)
					{
						if(a[j][i])cnt++;
						a[j][i] = 0;
					}
					for(int j=0;j<cnt;j++)
						a[j][i] = 1;
				}
			}
			else if(move[l]=='D') // down move
			{
				for(int i=0;i<m;i++)
				{
					ll cnt = 0;
					for(int j=0;j<n;j++)
					{
						if(a[j][i])cnt++;
						a[j][i] = 0;
					}
					if(cnt)
						for(int j=n-1;j>=0;j--)
						{
							a[j][i] = 1;
							cnt--;
							if(!cnt)
								break;
						}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout << a[i][j];
			cout << "\n";
		}
	}
}
