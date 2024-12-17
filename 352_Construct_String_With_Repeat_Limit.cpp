class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq_vector(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq_vector[s[i] - 'a']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < 26; i++){
            if(freq_vector[i] > 0){
                pq.push(make_pair(i,freq_vector[i]));
            }
        }
        string result;
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();

            char curr_char = curr.first + 'a' ;
            int count = min(curr.second,repeatLimit);
            curr.second -= count;
            result.append(count,curr_char);

            if(curr.second > 0){
                if(pq.empty()) break;

                pair<int,int> next = pq.top();
                pq.pop();

                char next_char = next.first + 'a';
                result.push_back(next_char);
                next.second--;

                if(next.second > 0){
                    pq.push(next);
                }
                pq.push(curr);
            }
        }
        return result;
    }
};