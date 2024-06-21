class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initial = 0;
        int maxExtra = 0;
        int currentWindow = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                initial += customers[i];
            } else if (i < minutes) {
                currentWindow += customers[i];
            }
        }
        
        maxExtra = currentWindow;
        
        for (int i = minutes; i < customers.size(); ++i) {
            currentWindow += customers[i] * grumpy[i];
            currentWindow -= customers[i - minutes] * grumpy[i - minutes];
            maxExtra = max(maxExtra, currentWindow);
        }
        return initial + maxExtra;
    }
};