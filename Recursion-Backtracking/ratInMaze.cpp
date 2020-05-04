#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define max 5

bool printString(int maze[][max], string output, vector<string>& result, int i, int j, int r, int c){

	if( i>r || j>c ){
		return false;
	}

	if( maze[i][j] == 0 ){
		return false;
	}

	if(i==r && j==c){
		result.push_back(output);
		return true;
	}

	bool rightSuccess = printString(maze, (output+"R"), result, i, j+1, r, c);
	bool downSuccess = printString(maze, (output+"D"), result, i+1, j, r, c);

	if( rightSuccess || downSuccess ){
		return true;
	}

	return false;
}



bool solve( int maze[][max], int solution[][max], int i, int j, int r, int c){

	if( i>r || j>c ){
		return false;
	}

	if( maze[i][j] == 0 ){
		return false;
	}

	if(i==r && j==c){
		solution[i][j] = 1;
		//solution

		for(int a=0; a<=r; a++){
			for(int b=0; b<=c; b++){
				cout<<solution[a][b]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;

		return true;
	}

	solution[i][j] = 1;

	bool rightSuccess = solve(maze, solution, i, j+1, r, c);
	bool downSuccess = solve(maze, solution, i+1, j, r, c);

	//backtracking
	solution[i][j] = 0;

	if( rightSuccess || downSuccess ){
		return true;
	}

	return false;
}

int main(){

	int rows, columns;
	cin>> rows >>columns;

	int maze[max][max] = {0};
	int solution[max][max] = {0};

	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cin>> maze[i][j];            //0-BLOCK, 1-CLEAR
		}
	}

	string output = "";
	vector<string> result;
	//bool ratSuccess = solve( maze, solution, 0, 0, rows-1, columns-1 );
	bool ratSuccess = printString(maze, output, result, 0, 0, rows-1, columns-1);

	if(ratSuccess){
		sort(result.begin(), result.end());
		for(int i=0; i<result.size(); i++){
			cout<<result[i]<<" ";
		}
	}
	else{
		cout<<-1<<endl;
	}

	return 0;
}