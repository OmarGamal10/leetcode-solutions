class Solution {
public:
//would need to move one by one for obstacle checks
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        set<vector<int>>obstacleSet; // i dont need ordering, but cpp doesnt have hash for unordered set for pairs and vectors
        for(auto o:obstacles){
            obstacleSet.insert(o);
        }
        int d=0; //initial north
        int x=0,y=0; //current coords
        int ans=0; //max eucledian dist
        for(int cmd:commands){
            if(cmd==-1)
                d=(d+1)%4;
            else if(cmd==-2)
                d=(d+3)%4;
            else{ //normal command...move one by one to detect obstacles
                while(cmd>0){
                    x+=directions[d][0];
                    y+=directions[d][1];
                    if(obstacleSet.count({x,y})){
                    x-=directions[d][0];
                    y-=directions[d][1];
                    }
                    cmd--;
                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};