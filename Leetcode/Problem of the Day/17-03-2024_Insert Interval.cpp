class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ans;
        //PART 1-->NO OVERLAP BEFORE THE MERGE 
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }                           
		//PART 2- OVERLAP CASES ARE PRESENT && MERGING
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval); // MERGED PART WILL BE ADDED TO ANS
        //PART 3- NO MORE OVERLAPS ARE LEFT 
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};