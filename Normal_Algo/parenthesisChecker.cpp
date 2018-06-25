#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
/*
4
[()]{}{[()()]()}
balanced
{([])}
balanced
()[]
balanced
[}()(]
not balanced
*/
int t;
string str1 ;
cin>>t;
getline(cin,str1);
while(t--){
	string str2 ;
	getline(cin,str2);
	
	stack<char> checker;

	int flag = 1 ;
	
	int len = str2.length() ;
	char popedElement ;
	for(int i = 0;i < len; i++){
		if(str2[i] == '{' || str2[i] == '[' || str2[i] == '(' ){
			checker.push(str2[i]);
		}
		else if(str2[i] == '}' || str2[i] == ']' || str2[i] == ')' ){
			if(!checker.empty())
				popedElement = checker.top() ;
			else{
				flag=0;
				break ;
			}
			switch(popedElement){
			case '{' :  if( str2[i] == '}')
					checker.pop() ;
				   else{
					flag =0;
					}
				   break;
			case '[' : if(str2[i] == ']')
					checker.pop() ;
				   else{
					flag =0;
					}		
			 	   break;
			case '(' : if(str2[i] ==')')
					checker.pop() ;
				   else{
					flag =0;
					}				   
				   break ;	
			}		
		}
	}
	if(checker.empty() && flag)
		cout<<"balanced"<<endl ;
	else
		cout<<"not balanced"<<endl ;
}


return 0 ;
}
