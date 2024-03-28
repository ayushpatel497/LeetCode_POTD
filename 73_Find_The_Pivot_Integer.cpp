class Solution {
public:
    int pivotInteger(int n) {
        double x = sqrt(n * (n + 1) / 2);
        int ans;
        if (fmod(x, 1.0) != 0)
            ans = -1;
        else
            ans = x;
        return ans;
    }
};
