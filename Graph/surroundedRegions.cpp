#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

void floodfill(vector<vector<char>>& board, char src, char dest, int i, int j){
        
    if( i<0 || i>=board.size() || j<0 || j>=board[0].size() ){
        return;
    }
    
    if( board[i][j]!=src ){
        return;
    }
    
    board[i][j] = dest;
    
    floodfill(board, src, dest, i, j-1);
    floodfill(board, src, dest, i, j+1);
    floodfill(board, src, dest, i-1, j);
    floodfill(board, src, dest, i+1, j);
    
    return;        
}

void solve(vector<vector<char>>& board) {
    
    if(board.size()<3){
        return;
    }
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]=='O'){
                board[i][j] = '-';
            }
        }
    }
    
    for(int i=0; i<board.size(); i++){
        if(board[i][0]=='-'){
            floodfill(board, '-', 'O', i, 0);
        }
    }
    
    for(int i=0; i<board.size(); i++){
        if(board[i][board[0].size()-1]=='-'){
            floodfill(board, '-', 'O', i, board[0].size()-1);
        }
    }
    
    for(int i=0; i<board[0].size(); i++){
        if(board[0][i]=='-'){
            floodfill(board, '-', 'O', 0, i);
        }
    }
    
    for(int i=0; i<board[0].size(); i++){
        if(board[board.size()-1][i]=='-'){
            floodfill(board, '-', 'O', board.size()-1, i);
        }
    }
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]=='-'){
                board[i][j] = 'X';
            }
        }
    }
    
    return;
    
}


void testcases(){

    int n, m;
    cin>> n >> m;

    vector<vector<char> > board( n, (m, 'O') );

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> board[i][j];
        }
    }

    solve(board);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<< board[i][j] <<" ";
        }
    }

    return;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}