class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ind = 0;
        int currGas = 0;
        int totalGas = 0;
        int totalCost = 0;

        for(int i=0;i<n;i++) {
            currGas+=gas[i];
            currGas-=cost[i];
            if(currGas<0) {
                currGas = 0;
                ind = i+1;
            }
            totalGas+=gas[i];
            totalCost+=cost[i];
        }

        if(totalCost>totalGas) return -1;
        return ind;
    }
};
