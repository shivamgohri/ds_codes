//https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps/0

#include <iostream>

using namespace std;

#define max 10

bool isSafe(int maze[][max], int i, int j, int n){

	if( i>=0 && i<n && j>=0 && j<n && maze[i][j]!=0 )
		return true;

	return false;
}


bool solveMaze(int maze[][max], int i, int j, int solution[][max], int N){

	if( i==N-1 && j==N-1 ){
		solution[i][j] = 1;
		//print solution

		cout<<endl;
		for(int row=0; row<N; row++){
			for(int col=0; col<N; col++){
				cout<< solution[row][col]<<" ";
			}
			cout<<"\n";
		}
		cout<<endl;
		
		return true;
	}	

	if( isSafe(maze, i, j, N)==true ){

		solution[i][j] = 1;

		for(int jump=1; jump<=maze[i][j] && jump<N; jump++){

			//forward
			if( solveMaze(maze, i, j+jump, solution, N)==true ){
				return true;
			}

			//downward
			if( solveMaze(maze, i+jump, j, solution, N)==true ){
				return true;
			}
		}

		//none worked
		solution[i][j] = 0;
		return false;
	}

	return false;
}


int main(){

	int t;
	cin>>t;

	while(t--){

		int N;
		cin>> N;

		int maze[max][max] = {0};

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin>> maze[i][j];
			}
		}

		int solution[max][max] = {0};

		bool done = solveMaze(maze, 0, 0, solution, N);

		if(done==false){
			puts("-1");
		}
	}

	return 0;
}