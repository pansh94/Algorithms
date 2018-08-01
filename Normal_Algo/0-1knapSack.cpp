#include<iostream>
#include<vector>
/*
Input:
1
3
4
1 2 3
4 5 1
Output:
3
Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
*/
using namespace std;
int max(int i,int j){
	return (i>j?i:j) ;
}
int main(){
int t;
cin>>t;
while(t--){
	
	int n ;
	cin>>n ;
	int k_w ;
	cin>>k_w ;

	vector<int> value(n),weight(n) ;

	vector< vector<int> >k(n+1,vector<int>(k_w+1)) ;
	
	for(int i=0;i<n;i++)
		cin>>value[i] ;
	
	for(int i=0;i<n;i++)
		cin>>weight[i] ;

	for(int i=0;i<=n;i++){
		for(int w=0;w<=k_w;w++){
			if(i==0 || w==0)
				k[i][w] = 0;
			else if(weight[i-1] <= w){
				k[i][w] = max(k[i-1][w],k[i-1][w-weight[i-1]] + value[i-1]) ;			
			}
			else
				k[i][w] = k[i-1][w] ;
				
		}
	}
	cout<<k[n][k_w]<<endl ;
}
return 0;
}
