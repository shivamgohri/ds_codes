//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define max 5

void printString(int maze[][max], string output, vector<string>& result, int i, int j, int r, int c){

	if( i>r || j>c || i<0 || j<0 || maze[i][j]==0 || maze[i][j]==5 ){
		return;
	}
	else if(i==r && j==c){
		result.push_back(output);
		return;
	}
	else{
		maze[i][j] = 5;

		printString(maze, (output+"R"), result, i, j+1, r, c);
		printString(maze, (output+"D"), result, i+1, j, r, c);
		printString(maze, (output+"U"), result, i-1, j, r, c);
		printString(maze, (output+"L"), result, i, j-1, r, c);

		maze[i][j] = 1;
		return;
	}
}


int main(){

	int rows, columns;
	cin>> rows >>columns;

	int maze[max][max] = {0};

	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cin>> maze[i][j];            //0-BLOCK, 1-CLEAR
		}
	}

	string output = "";
	vector<string> result;

	printString(maze, output, result, 0, 0, rows-1, columns-1);

	if(!result.empty()){
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