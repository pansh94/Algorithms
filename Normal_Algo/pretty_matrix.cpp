#include<iostream>
#include<vector>
using namespace std ;
vector< vector<int> > prettyPrint(int A){
	/* It will generate pretty matrix, ex for A=2
		222
		212
		222
	*/ 
	int n = 2*A - 1 ;
	vector< vector<int> > matrix(n,vector<int>(n)) ;
	int startCol = 0 ;
	int endCol = n ;

	int startRow =0 ;
	int endRow = n ;

	int num =  A ;
	int i,j ;

	int constRow = 0 ;
	int constCol = n-1 ;
	while(1){
		
		for ( i=startCol ; i<endCol ; i++)
			matrix[constRow][i] = num ;
		constCol = i-1 ; 
		startRow++ ;
		for ( j=startRow ; j<endRow ; j++)		
			matrix[j][constCol] = num;
		constRow = j-1 ;
		endCol-- ;
		for( i=(endCol-1);i>=startCol;i--)
			matrix[constRow][i] = num ;
		constCol = i+1 ;
		endRow-- ;
		for( j=(endRow-1) ;j>=startRow;j--)
			matrix[j][constCol] = num ;
		constRow= j+1 ;
		startCol++ ;
		if(startRow>endRow)
			break;		
		num-- ;
	}
return matrix ;
}

int main(){
int A ;
cin>>A;
int n = 2*A-1 ;
vector< vector<int> > matrix(n,vector<int>(n)) ;
matrix = prettyPrint(A);
for (int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" " ;
		}	 
		cout<<endl ;
	}

return 0 ;
}
