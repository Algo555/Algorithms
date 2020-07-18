// this code does bfs and finds shortest path for horse to reach from start to end
// https://www.codechef.com/problems/PRGCUP01

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 998244353
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<lli>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"

using namespace std;
int col(char c)
{
	if(c=='a')
		return 0;
	if(c=='b')
		 return 1;
	if(c=='c')
		return 2;
	if(c=='d')
		return 3;
	if(c=='e')
		return 4;
	if(c=='f')
		return 5;
	if(c=='g')
		return 6;
	else if(c=='h')	
		return 7;
	return -1;
}
int vis[8][8];
int dx[] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
int dy[] = { 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
int dist[8][8];

bool isValid(int x , int y)
{
	if(x < 1 || x > 8 || y < 1 || y > 8) return false;
	
	if(vis[x][y] == 1) return false;
	
	return true;
}
 
int bfs(int sr,int sc,int er,int ec)
{
	vis[sr][sc]=1;
	dist[sr][sc]=0;
	queue<pair<int,int>> q;
	q.push({sr,sc});

	while(!q.empty())
	{
		int curx=q.front().first;
		int cury=q.front().second; 
		q.pop();

		for(int i=0;i<8;i++)
		{
			if(isValid(curx+dx[i],cury+dy[i]))
			{
				dist[curx+dx[i]][cury+dy[i]]=dist[curx][cury]+1;
				vis[curx+dx[i]][cury+dy[i]]=1;
				q.push({curx+dx[i],cury+dy[i]}); 
				if(curx+dx[i]==er && cury+dy[i]==ec ) 
					return dist[curx+dx[i]][cury+dy[i]];
				

			} 
		}
	}
// return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	 int t;
	 cin>>t;
	 // enum cols { a,b,c,d,e,f,g,h };
	 while(t--)
	 {
	     
	     	for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
			vis[i][j] = 0,dist[i][j]=0;
		}
	 	string s1,s2;
	 	cin>> s1>>s2;
	 	int sr,sc,er,ec;
	 	sc=col(s1[0]);
	 	ec=col(s2[0]);
	 	sr= s1[1]-48;
	 	er=s2[1]-48;
	 	// cout<<sr<<" "<<sc<<" "<<er<<" "<<ec<<" ";	

	 	cout<<bfs(sr,sc,er,ec)<<endl;


	 }

	return 0;
}

