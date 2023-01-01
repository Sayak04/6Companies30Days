class Solution {
public:
    void find_ans(int index, vector<int> arr, vector<vector<int>> &ans, vector<int> &temp, int &k, int &n) {
        if(k == 0) {
            if(n == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if(k != 0 && n <= 0) return;
        if(index >= arr.size()) return;

        // we take the index
        temp.push_back(arr[index]);
        k--;
        n -= arr[index];
        find_ans(index+1, arr, ans, temp, k, n);

        // we do not take the index
        temp.pop_back();
        k++;
        n += arr[index];
        find_ans(index+1, arr, ans, temp, k, n);


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for(int i = 1; i <= 9; i++) arr.push_back(i);
        vector<vector<int>> ans;   
        vector<int> temp;
        find_ans(0, arr, ans, temp, k, n);
        return ans;     
    }
};