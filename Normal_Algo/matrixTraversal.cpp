#include<iostream>
#include<vector>
using namespace std;

void findPath(vector< vector<int> > &matrix,int n){
for(int k=0;k<n;k++){
	for(int s=0;s<n;s++){
		for(int d=0;d<n;d++){
			if(matrix[s][k]+matrix[k][d] < matrix[s][d])
				matrix[s][d] = matrix[s][k]+matrix[k][d] ;
		}
	}
}
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){

		if(matrix[i][j] == 60000)
			cout<<" INF " ;
		else
			cout<<" "<<matrix[i][j]<<" " ;	
	}
	cout<<endl ;
}
/*if(i==0 && j==(m-1)){
	cout<<"reached\n" ;
	return ;
}
else if(i<n && j<m && j>=0 && i>=0){
	if((j+1)<m && (i-1)>-1  && matrix[i][j+1]>0 && matrix[i-1][j]>0){
		cout<<i<<"="<<j<<endl ;
		matrix[i][j+1] = matrix[i][j]+1 ;
		matrix[i-1][j] = matrix[i][j]+1 ;
		findPath(matrix,n,m,i,j+1);
		findPath(matrix,n,m,i-1,j);
	}
	else if((j+1)<m && matrix[i][j+1]>0){
		cout<<i<<"="<<j<<endl ;
		matrix[i][j+1] = matrix[i][j]+1 ;
		findPath(matrix,n,m,i,j+1);	
	}
	else if((i-1)>-1 && matrix[i-1][j]>0){
		cout<<i<<"="<<j<<endl ;
		matrix[i-1][j] = matrix[i][j]+1 ;
		findPath(matrix,n,m,i-1,j);	
	}
}
*/
}

int main(){
int n;
cout<<"Enter no. of vertices : " ;
cin>>n;
vector< vector<int> > matrix(n,vector<int>(n)) ;
cout<<"Enter 60000(INF)/weight to define path between two points in matrix : " ;
for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>matrix[i][j] ;
	
findPath(matrix,n);

return 0;
}
