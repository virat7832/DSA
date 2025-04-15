class Solution {
public:
vector<vector<int>>ans;
void findCombination(int index,int target,vector<int>&arr,vector<int>&ds){
    if(index==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[index]<=target){
        ds.push_back(arr[index]);
        findCombination(index,target-arr[index],arr,ds);
        ds.pop_back();
    }
    findCombination(index+1,target,arr,ds);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>ds;
        findCombination(0,target,candidates,ds);
        return ans;
    }
};