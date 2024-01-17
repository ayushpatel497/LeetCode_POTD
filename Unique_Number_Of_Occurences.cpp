class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>um;
        unordered_set<int>s;
        for(auto i:arr)
            um[i]++;
        for(auto i:um)
            s.insert(i.second);
        return s.size()==um.size();
    }
};