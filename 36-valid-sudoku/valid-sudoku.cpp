class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         int n = board.size();
         int m = board[0].size();
        unordered_map<int, unordered_set<int>> box;
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;
         for( int i =0;i<n;i++){
            for( int j =0;j<m;j++){
                if( board[i][j]=='.') continue;
                if( row[i].find((int)board[i][j]) == row[i].end()){
                    row[i].insert( (int)board[i][j]);

                }
                else return false;
                if( col[j].find((int)board[i][j]) == col[j].end()){
                    col[j].insert( (int)board[i][j]);

                }
                 else  return false;
                  int d = ( i/3)*3 + ( j/3 );
                   if( box[d].find((int)board[i][j]) == box[d].end()){
                    box[d].insert( (int)board[i][j]);

                }
                else return false;

                


            }
         }
         return true;
        
        



        

        
    }
};