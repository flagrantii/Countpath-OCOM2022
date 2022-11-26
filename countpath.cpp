#include<bits/stdc++.h>
using namespace std;

long long dp[101][101];

int num=-1e9;
int check(int n,int m){
	if(n<1 || m<1){
		return 0;
	}
	if(dp[n][m]!=0){
		return dp[n][m];
	}else dp[n][m]=check(n,m+1),check(n+1,m+1),check(n-1,m+1);
	num=max(num,dp);
	
	return num;
}


int main(){
		int a,b;
		cin>>a>>b;
		int arr[a][b];
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				cin>>arr[i][j];
				if(j=1){
					dp[i][j]=arr[i][j];
				}
			}
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				int mx =max(max(dp[i-1][j-1],dp[i][j-1],dp[i+1][j-1]));
				dp[i][j]=arr[i][j]+mx;
			}
		}
	
	return 0;
}
