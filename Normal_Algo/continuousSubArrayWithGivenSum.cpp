#include<iostream>
#include<vector>
using namespace std ;
int main(){
/*
2
6 17
3 1 4 2 10 7
2 5
5 15
5 2 6 7 8
2 4

*/

int t ;
cin>>t ;
while(t--){
	int size,sum ;
	int startP=1,endP=1;
	cin>>size>>sum ;
	int checkSum = 0;
	int flag = 0 ;
	vector<int> arr(size) ;

	for(int i=0;i<size;i++)
		cin>>arr[i] ;


	for(int i=0;i<size;i++){
		checkSum+=arr[i] ;
		endP = 1+i ;
		if(checkSum == sum){
			flag = 1 ;
			break;
		}
		else if(checkSum > sum){
			while(checkSum > sum && startP<endP){
				checkSum -= arr[startP-1] ;
				startP++ ;
			}
			if(checkSum == sum){
				flag=1 ;
				break ;			
			}
		}
	}	
	if(flag){
		cout<<startP<<" "<<endP<<endl ;	
	}
	else{
		cout<<-1<<endl ;	
	}
}
return 0 ;
}
