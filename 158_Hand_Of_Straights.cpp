class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : hand)
            pq.push(x);
        while (!pq.empty()) {
            int cnt = groupSize;
            int i = pq.top();
            vector<int> temp;
            while (cnt > 0) {
                if (pq.empty())
                    return false;
                if (i == pq.top() + 1) {
                    temp.push_back(pq.top());
                    pq.pop();
                } else if (i == pq.top()) {
                    cnt--;
                    i++;
                    pq.pop();
                } else
                    return false;
            }
            for (int i = 0; i < temp.size(); i++)
                pq.push(temp[i]);
        }
        return true;
    }
};