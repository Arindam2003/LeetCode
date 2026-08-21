class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue<int,vector<int>,greater<int>> pq;
    int curr_elem;
    SmallestInfiniteSet() {
        curr_elem=1;
    }
    
    int popSmallest() {
        int ans;
        if(!pq.empty())
        {
            ans=pq.top();
            pq.pop();
            st.erase(ans);
        }
        else{
            ans=curr_elem;
            curr_elem++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(num>=curr_elem || st.find(num)!=st.end())
        {
            return;
        }
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */