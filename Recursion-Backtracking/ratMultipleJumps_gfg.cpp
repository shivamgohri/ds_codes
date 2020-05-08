//https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps/0

#include <iostream>

using namespace std;

int n;

bool canJump(int maze[][n], int i, int j, int val, char way){



}

bool solveMaze(int maze[][n], int i, int j, int n){

	if( i>n || j>n ){
		return false;
	}

	if( i==n && j==n ){
		return true;
	}

	if(j+1<=n && maze[i][j+1]==0){
		if( canJump(maze, i, j, maze[i][j], 'r') ){
			return true;
		}
		else{
			return false;
		}
	}

	if( i+1<=n && maze[i+1][j]==0 ){
		if( canJump(maze, i, j, maze[i][j], 'd') ){
			return true;
		}
		else{
			return false;
		}
	}

	bool rightSuccess = solveMaze(maze, i, j+1, n);
	bool downSuccess = solveMaze(maze, i+1, j, n);

	if( rightSuccess || downSuccess ){
		return true;
	}

	return false;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		cin>> n;

		int maze[n][n] = {0};

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>> maze[i][j];
			}
		}



	}

}