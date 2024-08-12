class KthLargest {
    priority_queue<int> minheap;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int x:nums) 
            add(x);
    }
    
    int add(int val) {
        if(minheap.size()<n)
            minheap.push(-1*val);
        else if(val>-1*minheap.top()){
            minheap.pop();
            minheap.push(-1*val);
        }
        return -1*minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */