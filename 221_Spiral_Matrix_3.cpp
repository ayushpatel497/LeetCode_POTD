class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cells=rows*cols;
        int dirVal=0;
        vector<vector<int>>ans;
        int i=rStart,j=cStart,len=0;
        ans.push_back({rStart,cStart});
        while(ans.size()<cells){
            if(dirVal==0 || dirVal==2)len++;
            for(int k=0;k<len;k++){
                i+=directions[dirVal][0];
                j+=directions[dirVal][1];
                if(i>=0 && i<rows && j>=0 && j<cols)ans.push_back({i,j});
            }
            dirVal=(++dirVal)%4;
        }
        return ans;
    }
};