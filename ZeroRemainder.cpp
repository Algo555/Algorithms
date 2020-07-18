//codeforces div3 round 653 D.


#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
using namespace std;
map<int,int> ar;
lli n , k;
int main()
{
	int t , x;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ar.clear();
		
		REP(i , n)
		{
			cin>>x , ar[x%k]++;
		}
		
		lli mx = 0;
		for(ii P : ar)
		{
			lli cnt = P.ss;
			int i = P.ff;
			
			if(i != 0)
			mx = max(mx , cnt * k - i);//
			
			/*
			 10 6
			 8 7 1 8 3 7 5 10 8 9
			 here mp[1]=3;
			 therefore 3*6 - 1 = 17 is (cnt * k - i)
 			
			*/
		}
		
		if(mx) mx++;
		cout<<mx<<endl;
	}
}
