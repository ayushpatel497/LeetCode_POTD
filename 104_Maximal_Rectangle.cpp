class Solution {
public:
    int solve(vector<int>& histo){
        stack<int> s;
        int n=histo.size();
        int maxx=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || histo[s.top()]>=histo[i])){
                int height=histo[s.top()];
                s.pop();
                int width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                maxx=max(maxx,width*height);
            }
            s.push(i);
        }
        return maxx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int maxarea=0;
        vector<int> histo(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') histo[j]++;
                else histo[j]=0;
            }
            int area=solve(histo);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};