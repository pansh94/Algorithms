#include<iostream>
#include<string>
using namespace std;
/*
race a car --> NO
I am :IronnorI Ma, i --> YES
Ab?/Ba --> YES
*/
int main(){
int t ;
cin>>t;
string st2 ;
getline(cin,st2) ;

while(t--){

	string str1 ;
	getline(cin,str1);
	//cout<<str1<<endl ;
	int len = str1.length() ;
	string::iterator start = str1.begin();
	string::reverse_iterator end =  str1.rbegin() ;
	
	int flag = 1; 
	while(start!=str1.end() && end!= str1.rend()){
		while(1){
			if((*start<48 || *start>57) && (*start<65 || *start>90) && (*start<97 || *start>122) )
				start++;
			else if((*end<48 || *end>57) && (*end<65 || *end>90) && (*end<97 || *end>122) )
				end++ ;
			else
				break ;

		}
		
		if((*start>=65 || *start<=90))
			*start = tolower(*start) ;
			
		if((*end>=65 || *end<=90))
			*end = tolower(*end) ; 
		
	//	cout<<*start<<"--"<<*end<<endl ;

		if(*start == *end){
			start++;
			end++ ;
		}
		else{
			flag=0;	
			break ;	
		}
		
	}
	if(flag)
		cout<<"YES"<<endl ;
	else
		cout<<"NO"<<endl  ; 
	
}
return 0;
}
