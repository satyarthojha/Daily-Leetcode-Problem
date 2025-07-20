 long long minimumDifference(vector<int>& nums) {
         int n = nums.size() / 3;
        int sz = nums.size();
        //best ques for priority  queue
        // Step 1: Prepare left max-heaps to track min sum of n largest elements in left part and store in vector 
        priority_queue<int> leftPQ;
        vector<long long> leftSum(sz, 0);
        long long sum = 0;

        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
            leftPQ.push(nums[i]);

            if (leftPQ.size() > n) {
                sum -= leftPQ.top();
                leftPQ.pop();
            }

            if (leftPQ.size() == n) {
                leftSum[i] = sum;
            }
        }

        // Step 2: Prepare right min-heaps to track max sum of n smallest elements in right part and store in vector 
        priority_queue<int, vector<int>, greater<int>> rightPQ;
        vector<long long> rightSum(sz, 0);
        sum = 0;

        for (int i = sz - 1; i >= n; i--) {
            sum += nums[i];
            rightPQ.push(nums[i]);

            if (rightPQ.size() > n) {
                sum -= rightPQ.top();
                rightPQ.pop();
            }

            if (rightPQ.size() == n) {
                rightSum[i] = sum;
            }
        }

        // Step 3: Compare left and right sums and using leftSum vector and rightSum vector find minimum difference 
        long long minDiff = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            if (rightSum[i + 1] != 0) {
                minDiff = min(minDiff, leftSum[i] - rightSum[i + 1]);
            }
        }

        return minDiff;
    
        
    }