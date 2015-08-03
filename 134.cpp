class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int nums = gas.size();
    	if (nums == 0)
    	    return -1;
    	int gas_sum = 0;
    	int cost_sum = 0;
    	int start = 0;
    	int i = 0;
    	for (int count = 0; count < 2 * nums; count++) {
    		gas_sum += gas[i % nums];
    		cost_sum += cost[i % nums];
    		if (gas_sum < cost_sum) {
    			i = (i + 1) % nums;
    			start = i;
    			gas_sum = 0;
    			cost_sum = 0;
    		}
    		else {
    			i = (i + 1) % nums;
    			if (i == start)
    				return start;
    		}
    	}
    	return -1;
    }
};