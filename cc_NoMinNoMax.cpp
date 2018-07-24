/* shivamgor498
	https://www.codechef.com/JULY18A/problems/NMNMX*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell2 1000000006
#define pb push_back
#define x first
#define y second
using namespace std;
ll D[5004][5004]={0};
ll fpow(ll n, ll k, ll p = hell) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
void ncr(){//Function to calculate NCR
  D[1][1] = 1;
  for(int i=2;i<5004;i++)
  {
    D[i][1] = 1;
    for(int j=2;j<=i;j++)
      D[i][j] = (D[i-1][j]%hell2 + D[i-1][j-1]%hell2)%hell2;
  }
  //D[i][j] is iCj
}

int main()
{
	ios
	ll t;
	cin >> t;
  	ncr();
	while(t--)
	{
      ll n,k;
      cin >> n >> k;
      vector<ll>a(n);
      for(int i=0;i<n;i++)
        cin >> a[i];
      sort(a.begin(),a.end());
      /* Sort the array and element at index i occurs nCK subsequences of size k
      	element at index i is max in (n-i)Ck subsequences
      	element at index i is min in iCk subsequences*/
      vector<ll>pow(n,0);
      ll temp = 0;
      if(n>=k)
          temp = D[n][k]%hell2;
      for(int i=0;i<n;i++)
      {
        ll temp2 = 0;
        if(n-i>=k)
          temp2 = D[n-i][k]%hell2;
        ll temp3 = 0;
        if(i+1>=k)
          temp3 = D[i+1][k]%hell2;
        ll temp1 = (temp2%hell2 + temp3%hell2)%hell2;
        pow[i] = (temp%hell2 - temp1%hell2)%hell2;
        if(pow[i]<0)
          pow[i] = (pow[i]+hell2)%hell2;
        //pow[i] stores no. of times elements at index i occurs not max or min in subsequence of size k
      }
      ll ans = 1;
      for(int i=0;i<n;i++)
      {
            ans = ((ans%hell)*(fpow(a[i],pow[i],hell))%hell)%hell; // a[i] will repeat pow[i] times
      }
      cout << ans << "\n";
	}
}
