class Node{
    public:
        Node *next[26];
        bool end;
        Node(){
            end = false;
            for(int i =0 ;i<26;i++){
                next[i] = NULL;
            }
        }
};


class Trie{
    public:
        Node* parent;
        Trie(){
            parent = new Node();
        }
        void insert_word(string &s){
            Node *p = parent;
            for(char c:s){
                if (p->next[c-'a'] == NULL){
                    p->next[c-'a'] = new Node();
                }
                p = p->next[c-'a'];
            }
            p->end = true;
        }
        vector<int> find_word(string &s, int i){
            Node *p = parent;
            vector<int>ans;
            for(int j = i;j<s.size();j++){
                if (p->next[s[j]-'a'] == NULL){
                    return ans;
                }
                p = p->next[s[j]-'a'];
                if (p->end){
                    ans.push_back(j-i);
                }
            }
            return ans;
        }
};

class Solution {
public:

    int go(string &s, int i, Trie &t, vector<int>&dp){
        if (i>=s.size()){
            return 0;
        }
        if (dp[i] != -1){
            return dp[i];
        }
        vector<int>v = t.find_word(s, i);
        if (v.size() == 0){
            return dp[i] = 1 + go(s, i+1, t, dp);
        } else {
            int ans = INT_MAX;
            for(int j:v){
                ans = min(ans, go(s, i+j+1, t, dp));
            }
            ans = min(ans, go(s, i+1, t, dp) + 1);
            return dp[i] = ans;
        }
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        Trie t;
        for(string word:dictionary){
            t.insert_word(word);
        }
        vector<int>dp(s.size(), -1);
        return go(s, 0, t,dp);
    }
};