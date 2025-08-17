class NumArray {
public:
    vector<int>store;  //prefixSum
    NumArray(vector<int>& nums) {
        store.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            store.push_back(nums[i]+store.back());
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return store[right];
        }
        return store[right]-store[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */