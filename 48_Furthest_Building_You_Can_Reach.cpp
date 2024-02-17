class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int> pq;
        int count=0;
        for(int i=0;i<n-1;++i){
            if(heights[i+1]-heights[i]>0 && heights[i+1]-heights[i]<=bricks){
                pq.push(heights[i+1]-heights[i]);
                bricks=bricks-(heights[i+1]-heights[i]);
                count++;
            }
            else if(heights[i+1]-heights[i]<=0) count++;
            else{
                if(ladders==0) return count;
                if(pq.size()>0 && heights[i+1]-heights[i]>=pq.top()){
                    ladders--;
                    count++;
                }
                else if(pq.size()==0){
                    count ++;
                    ladders--;
                }
                else{
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                    --i;
                }
            }
        }
        return count;
    }
};