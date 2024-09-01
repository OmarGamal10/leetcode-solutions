class Solution {
public:
//next inc,,,next dec,, candidate for monotonic stack:))
//good problem..i watched solution, could only brute force it
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int size=temperatures.size();
        vector<int> ans(size); 
        st.push(make_pair(temperatures[0],0));
        for(int i=1;i<size;i++){
            while(!st.empty()&&temperatures[i]>st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
                st.push(make_pair(temperatures[i],i));
        }
        return ans;
    }
};