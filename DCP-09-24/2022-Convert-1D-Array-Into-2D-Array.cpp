class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        vector<int>row;
        int size=original.size();
        if(size!=m*n)
            return ans;
        //row by row, and n(cols) tells the length of each row
        for(int i=0;i<m;i++){  
            for(int j=i*n;j<(i*n)+n;j++){
                row.push_back(original[j]);
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};