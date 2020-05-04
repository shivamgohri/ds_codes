//just tells how many possible ways are there to place queens in n*n board

#include <iostream>
#include <bitset>

using namespace std;

bitset<10> col;
bitset<19> leftDiagonal;
bitset<19> rightDiagonal;

void solve(int row, int n, int& ans){

	if(row==n){ans++; return;}

	for(int c=0; c<n; c++){
		if( !col[c] && !leftDiagonal[row-c+n-1] && !rightDiagonal[row+c] ){
			col[c] = leftDiagonal[row-c+n-1] = rightDiagonal[row+c] = 1;
			solve(row+1, n, ans);
			col[c] = leftDiagonal[row-c+n-1] = rightDiagonal[row+c] = 0;
		}
	}

}

int main(){

	int n;
	cin>>n;

	int ans = 0;

	solve( 0, n, ans );

	cout<< ans <<endl;

}