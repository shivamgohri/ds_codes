#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(int board[][10], int i, int j, int n){

	for(int row=0; row<i; row++){
		if(board[row][j]==1){
			return false;
		}
	}

	int x = i;
	int y = j;

	while( x>=0 && y>=0 ){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	x=i;
	y=j;

	while( x>=0 && y<n ){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}

	return true;
}

bool solveNQueen(int board[][10], int i, int n, vector<vector<int> >& result){

	if(i==n){

		vector<int> solution;
		for(int row = 0; row<n; row++){
			for(int col = 0; col<n; col++){
				if( board[row][col] == 1 ){
					solution.push_back(col+1);
				}
			}
		}
		result.push_back(solution);
	}

	for(int j=0; j<n; j++){

		if( isSafe(board, i, j, n) ){

			board[i][j] = 1;

			bool RakhPaye = solveNQueen(board, i+1, n, result);

			if(RakhPaye){
				return true;
			}

			board[i][j] = 0;
		}
	}

	return false;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int board[10][10] = {0};

		vector<vector<int> > result;
		
		bool ans = solveNQueen(board, 0, n, result);

		sort(result.begin(), result.end()); 

		if(result.empty()){
			for(int i=0; i<result.size(); i++){
				cout<<'[';
				for(int j=0; j<result[i].size(); j++){
					cout<<result[i][j]<<" ";
				}
				cout<<"] ";
			}
			cout<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}

	return 0;
}