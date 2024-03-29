bool cmp(vector<int> a, vector<int> b)
{
	return b[1] > a[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;

        // To sort our array according
        // to end position of balloons
        sort(points.begin(), points.end(), cmp);

        // Initialize end variable with
        // the end of first balloon
        int end = points[0][1];

        // Initialize arrow with 1
        int arrow = 1;

        // Iterate through the entire
        // arrow of points
        for (int i = 1; i < points.size(); i++)
        {

            // If the start of ith balloon
            // <= end than do nothing
            if (points[i][0] <= end)
            {
                continue;
            }

            // if start of the next balloon
            // >= end of the first balloon
            // then increment the arrow
            else
            {

                // Update the new end
                end = points[i][1];
                arrow++;
            }
        }

        // Return the total count of arrows
        return arrow;
    }
};
