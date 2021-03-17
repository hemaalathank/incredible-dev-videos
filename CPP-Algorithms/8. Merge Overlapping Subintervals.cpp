// Merge Overlapping Subintervals

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;

    if(intervals.size() == 0){
        return mergedIntervals;
    }

    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];


    for(auto it: intervals){
        if(it[0] <= tempInterval[1]){
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else {
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }

    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
