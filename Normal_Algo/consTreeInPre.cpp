#include<iostream>
#include<vector>

using namespace std;
int size;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node *root=NULL;
struct Node* createNode(int data){
	struct Node * temp = new Node ;
	temp->data =  data;
	temp->left = temp->right = NULL;
	return temp ;
}
int search(vector<int> &in,int start, int end, int key){
	if(start<=end){
		for(int i= start;i<=end;i++){
			if( key == in[i] ){
				return i;
			}
		}
	}
	return -1;
}
struct Node* createTree(vector<int> &pre,vector<int> &in,int start,int end){
	static int prePointer = 0;
	struct Node *temp = NULL ;
	int index_key_in = -1;
	if(start <= end){
		index_key_in = search(in,start, end, pre[prePointer]);
		if(index_key_in != -1){	
			cout<<"Preorder Value : "<<pre[prePointer]<<"  Inorder Index :"<<index_key_in<<endl ;
			temp  = createNode(pre[prePointer++]);
			if(!root)
				root = temp;
			if(start!=end){
				temp->left = createTree(pre,in,start,index_key_in-1);
	        		temp->right = createTree(pre,in,index_key_in+1,end);
			}
			return temp ;
		}
		else
			return NULL ;
	}
	else
		return NULL;
}
void inOrder(struct Node* temp){
	if(!temp)
		return ;
	else{
		inOrder(temp->left);
		cout<<temp->data<<" ";
		inOrder(temp->right);
	}
}
void preOrder(struct Node* temp){
	if(!temp)
                return ;
        else{
                cout<<temp->data<<" ";
		preOrder(temp->left);
                preOrder(temp->right);
        }
}
int main(){
	int n;
	cout<<"Enter size of array :";
	cin>>n;
	size = n;
	vector<int> pre(n),in(n);
	cout<<"Enter in_order sequence of tree :";
	for(int i=0;i<n;i++)
		cin>>in[i];
	cout<<"Enter pre_order sequence of tree :";
	for(int i=0;i<n;i++)
                cin>>pre[i];
	createTree(pre,in,0,n-1);	
	cout<<"\nTree id ...\n" ;
	inOrder(root);
	cout<<endl;
	preOrder(root);
	cout<<endl ;
	return 0;
}
