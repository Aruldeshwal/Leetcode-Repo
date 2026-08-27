class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_surplus = 0;
        int current_tank = 0;  
        int starting_index = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++) {
            int net_gas = gas[i] - cost[i];
            total_surplus += net_gas;
            current_tank += net_gas;
            if (current_tank < 0) {
                starting_index = i + 1;
                current_tank = 0; 
            }
        }
        if (total_surplus < 0) return -1;
        
        return starting_index;
    }
};