class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        int fir=0,sec=1,thi=1;
        int i=3;
        int ans=0;
        while(i<=n){
            ans=fir+sec+thi;
            fir=sec;
            sec=thi;
            thi=ans;
            i++;
        }
        return ans;
    }
};