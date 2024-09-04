class Solution {
public:
// had to look at the solution, pretty tough to come up with tbh
//depends on that the relative position of cars is never gonna change(cannot pass)
//a fleet will arrive at the time that the slower one(higher position) gets to the target
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        int fleetsAns=0;
        vector<pair<int,double>>pairs;
        //sort the pairs relative to position
        for (int i=0; i < n; ++i) {
        pairs.push_back(make_pair(position[i], double(target-position[i])/speed[i]));
        }
        sort(pairs.begin(),pairs.end(),[](auto& a,auto& b){
            return a.first>b.first; //sort based on positions
        });
        double highestPositionTime=-1;
        for(int i=0;i<n;i++){
            if(pairs[i].second<=highestPositionTime){
                continue;
            }
                highestPositionTime=pairs[i].second;
                fleetsAns++;
        }
        return fleetsAns; 
    
    }
};