//div 3:653 C where we have to find total number of unbalanced pairs.
//imp gfg link:https://www.youtube.com/redirect?redir_token=QUFFLUhqbm12U0JPOWh6NVZHVTg3SGFIekdneTVnQXhwQXxBQ3Jtc0tsdVR4ZGVuYXZkV2g0Ymt5NnR0Y0FFOXdMMGt4THVSZnotUC1xN1Q5WHdrNXhYTEVjdVJHS0U0UkVZck14d0drczQ2dVc2UEdUSW1GblRLRVlSNklMV0JOVEhTYkd1clJHMEVJbm1wY1N4VXNwalhndw%3D%3D&q=https%3A%2F%2Fwww.geeksforgeeks.org%2Fcheck-for-balanced-parentheses-in-an-expression%2F&v=US9OHQ8qW8c&event=video_description


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
char ar[1000001];
int n;

int getAns()
{
	stack<char> st;
	
	REP(i , n)
	{
		if(ar[i] == '(')
		st.push('(');
		else
		{
			if(!st.empty() && st.top() == '(') st.pop();
			else
			st.push(')');
		}
	}
	
	return st.size();
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		REP(i , n) cin>>ar[i];
		
		cout<<(getAns())/2<<endl;  // divide by 2 because we have to print number of pairs that are mismatched .
	}
}
