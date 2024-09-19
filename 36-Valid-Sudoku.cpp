class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row;
        unordered_set<char>col;
        map<pair<int,int>,unordered_set<char>>grid; //had to use map not unordered bcz cpp doesn't provide unordered map key to be a pair
        //rows
        for(int i=0;i<9;++i){
            row.clear();
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                    continue;
                if(row.count(board[i][j])||grid[make_pair(i/3,j/3)].count(board[i][j]))
                    return false;
                row.insert(board[i][j]);
                grid[make_pair(i/3,j/3)].insert(board[i][j]);
            }
        }
            for(int i=0;i<9;i++){
                col.clear();
                for(int j=0;j<9;j++){
                    if(board[j][i]=='.')
                        continue;
                    if(col.count(board[j][i]))
                        return false;
                    col.insert(board[j][i]);
                }
            }
            return true;
        }
};