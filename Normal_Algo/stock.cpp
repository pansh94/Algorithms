#include<iostream>
#include<vector>
using namespace std;
int findNextMax(vector< vector<int> > &matrix,int si,int sj,int num){
	if(si<num && sj<num){
		int max = matrix[si][sj] ;
		for(int i=si;i<num;i++)
			for(int j=sj;j<num;j++){
				if(matrix[i][j]>max)
					max = matrix[i][j] ;	
		}
		return max ;
	}
	else
		return 0;
}

void maxProfit(vector<int> &stock, int num ){
	vector< vector<int> > matrix(num,vector<int>(num)) ;
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++){
			if(j<=i || stock[i]>=stock[j])
				matrix[i][j] = -1 ;
			else
				matrix[i][j] = stock[j]-stock[i] ;				
		}
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			cout<<matrix[i][j]<<" " ;				
		}
		cout<<endl ;
	}
	int maxProfit = -1 ;
	int instantMax = -1 ;
	int currProfit = -1 ;
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++){
			currProfit = matrix[i][j];
			instantMax = findNextMax(matrix,j+1,j+1,num);
			if(((currProfit + instantMax) > maxProfit) && instantMax > 0)
				maxProfit = currProfit + instantMax ;
	}
	cout<<"Max profit is : "<<maxProfit<<endl;
}

int main(){
	int num;
	cout<<"Enter no. of stock entry : " ;
	cin>>num;
	vector<int> stock(num);

	cout<<"Enter stock prices in space seperated line : " ;

	for(int i=0;i<num;i++)
		cin>>stock[i] ;

	maxProfit(stock,num);
return 0;
}

