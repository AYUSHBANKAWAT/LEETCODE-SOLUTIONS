class Solution {
public:
    bool check( vector<string>&board,int row,int col,int n ){
        
        for( int i=0;i<row;i++){
            if(  board[i][col]=='Q' )return false;
        }
        for( int i=0;i<col;i++){
            if(  board[row][i]=='Q' )return false;
        }
        int i = row-1;
        int j = col-1;
        while( i>=0 && j>=0 ){
            if( board[i][j]=='Q' )return false;
            i--;
            j--;
        }
        i=row-1;
        j=col+1;
        while( i>=0 && j<n ){
            if( board[i][j]=='Q' )return false;
            i--;
            j++;
        }
        return true;
    }
    void solve( int row,vector<vector<string>>&ans,vector<string>&board,int n){
        if( row==n ){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if( check( board,row,i,n) ){
                board[row][i]='Q';
                solve( row+1,ans,board,n);
                board[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n,s);
        solve( 0,ans,board,n);
        return ans;
    }
};