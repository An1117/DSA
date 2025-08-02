class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        // //combinatorial formula approach: stored entire triangle
        // for(int i = 0; i < numRows; i++) {
        //     vector<int> temp(i + 1, 1);
        //     for(int j = 1; j < i; j++) {
        //         temp[j] = result[i - 1][j - 1] + result[i - 1][j];
        //     }
        //     result.push_back(temp);
        // }
        // return result;

        //DP 1d array: keeps only last row in memory.
        vector<int> prevRow;

        for(int i = 0; i < numRows; i++){
            vector<int> currentRow(i + 1, 1);

            for(int j = 1; j < i; j++) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }
            result.push_back(currentRow);
            prevRow = currentRow;
        }
        return result;
    }
};