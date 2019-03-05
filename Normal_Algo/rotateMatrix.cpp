#include<iostream>
#include<vector>
using namespace std;

int main(){
int t ;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<vector<int> > mat(n,vector<int>(n));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j] ;

	int mid = n/2 ;
	int t = n;
	for(int i = 0; i < mid ; i++){
		for(int j=i;j<(t-i-1);j++){
			int temp = mat[i][j];
			mat[i][j] = mat[n-1-j][i];
			mat[n-1-j][i] = mat[n-1-i][n-1-j];
			mat[n-1-i][n-1-j] = mat[j][n-1-i] ;
			mat[j][n-1-i] = temp ;
		}
		t--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" " ;
		}
		cout<<endl ;
	}
	
}
return 1 ;
}
