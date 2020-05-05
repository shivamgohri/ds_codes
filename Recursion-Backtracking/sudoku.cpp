#include <iostream>

using namespace std;

#define max 9

bool canPlace(int grid[][max], int row, int col, int num, int size){

	for(int c=0; c<=size; c++){
		if(grid[row][c]==num && c!=col){
			return false;
		}
	}

	for(int r=0; r<=size; r++){
		if(grid[r][col]==num && r!=row){
			return false;
		}
	}

	//check in small grid
	int sx = (row/3)*3;
	int sy = (col/3)*3;

	for(int i=sx; i<sx+3; i++){
		for(int j=sy; j<sy+3; j++){
			if(grid[i][j]==num){
				return false;
			}
		}
	}


	return true;
}

bool solveSudoku(int grid[][max], int row, int col, int size){

	cout<<row<<","<<col<<endl;

	if( row==9 ){
		//print solved sudoku

		for(int num=1; num<=9; num++){
			if( canPlace( grid, row, col, num, size) ){
				grid[row][col] = num;
			}
		}

		for(int i=0; i<=size; i++){
			for(int j=0; j<=size; j++){
				cout<<grid[i][j]<<" ";
			}
		}
		cout<<endl;

		return true;
	}
	
	if( col==9 ){
		return solveSudoku(grid, row+1, 0, size);
	}

	if(grid[row][col]!=0){
		return solveSudoku(grid, row, col+1, size);
	}

	for(int num=1; num<=9; num++){
		if( canPlace( grid, row, col, num, size) ){

			grid[row][col] = num;

			bool successAhead;
			if(col==size){
				successAhead = solveSudoku(grid, row+1, 0, size);
			}
			else{
				successAhead = solveSudoku(grid, row, col+1, size);
			}

			if(successAhead){
				return true;
			}
		}
	}

	grid[row][col] = 0;
	return false;
}

int main(){

	int n;
	cin>>n;

	int grid[max][max] = {0};

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>> grid[i][j];
		}
	}

	solveSudoku(grid, 0, 0, n-1);

	return 0;
}