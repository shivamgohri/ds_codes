#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007



void testcases1(){

	int n;
	cin>> n;

	vector<vector<double>> arr(n, vector<double> (3, 0.00));

	for(int i=0; i<n; i++){
		cin>> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	//taking input array as 'arr'
	set<vector<double>> s;

	for(int i=0; i<arr.size(); i++){

		if( arr[i][2]<=arr[i][1] ){
			swap(arr[i][1], arr[i][2]);
		}


		if(s.find(arr[i])==s.end()){
			s.insert(arr[i]);
			// cout<< i <<endl;
		}
	}

	vector<vector<double>> ans;

	for(int i=0; i<arr.size(); i++){
		if( s.find(arr[i])!=s.end() ){
			// cout<< arr[i][0] <<","<< arr[i][1] <<","<< arr[i][2] <<endl;
			ans.push_back(arr[i]);
			s.erase( arr[i] );
		}
	}

	return ans;

	for(int i=0; i<ans.size(); i++){
		cout<< ans[i][0] <<","<< ans[i][1] <<","<< ans[i][2] <<endl;
	}

	return;
}


// void testcases1(){
	
// 	//head is input, ans is output
// 	if(head==NULL || head->next==NULL){
//         return;
//     }
    
//     //alternate
//     Singlylinkedlist* first = head;
//     Singlylinkedlist* second = head->next;
    
//     Singlylinkedlist* temp1 = first, *temp2 = second;
    
//     while( temp1!=NULL && temp2!=NULL ){
        
//         Singlylinkedlist* temp = temp2->next;
        
//         if(temp==NULL){
//             temp1->next = NULL;
//             break;
//         }
        
//         temp1->next = temp;
        
//         if(temp->next==NULL){
//             temp2->next = NULL;
//             break;
//         }
//         else{
//             temp2->next = temp->next;
//         }
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }
    
//     //reverse
//     Singlylinkedlist* prev = NULL;
//     Singlylinkedlist* temp = second;
    
//     while(temp!=NULL){
//         Singlylinkedlist* x = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = x;
//     }
    
//     second = prev;
    
//     //merge
//     Singlylinkedlist* ans = first;
    
//     while( second!=NULL ){
        
//         Singlylinkedlist* x = first->next;
//         Singlylinkedlist* y = second->next;
        
//         first->next = second;
//         second->next = x;
        
//         first = x;
//         second = y;
//     }
    
//     return ans;
// }


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}