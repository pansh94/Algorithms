#include<iostream>
#include<vector>
using namespace std;
int size = 0 ;
int swap(vector<int> &v,int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int getParent(int i){
	return ((i-1)/2);
}
int getRight(int i){
	return (2*i + 2);
}
int getLeft(int i){
	return (2*i + 1);
}
void minHeapify(vector<int> &v,int index){
	int l = getLeft(index);
	int r = getRight(index);
	
	int s = index;
	if(r <= size && r>=0 && v[s]>v[r])
		s = r ;
	if(l <= size && l>=0 && v[s]>v[l])
		s = l ;
	
	if(s != index){
		swap(v,s,index); 
		minHeapify(v,s);
	}
	return ;	
		
}
int getMin(vector<int> &v){
        int temp = v[0] ;
        v[0] = v[size--] ;
        minHeapify(v,0);
        return temp ;
}

void minHeap(vector<int> &v){
	int mid ;
	if(size%2 != 0)
		mid = size/2 ;
	else
		mid = (size-1)/2 ;
	//cout<<"MID : "<<mid<<endl ;
	for(int i = mid; i>=0; i--)
		minHeapify(v,i);
}
int main(){
int t;
cin>>t;
while(t--){
	int n,k;
	int min;
	cin>>n;
	size = n - 1 ;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	cin>>k;
	minHeap(v);
	while(k--){
		min = getMin(v);
	}
	cout<<min<<endl;
}
return 0;
}
