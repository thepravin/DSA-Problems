/*
Maximum Points You Can Obtain from Cards 
https://takeuforward.org/plus/dsa/problems/maximum-points-you-can-obtain-from-cards-
*/

 int maxScore(vector<int>& cardScore , int k){
        int n = cardScore.size();
        int lSum = 0;
        int rSum = 0;
        int maxSum = 0;
        int rIdx = n-1;

        for(int i=0;i<k;i++){    // O(k)
            lSum += cardScore[i];
        }
        maxSum = lSum;

        for(int i=k-1; i>=0; i--){   // O(k)
            lSum -= cardScore[i];
            rSum += cardScore[rIdx];
            rIdx--;
            maxSum = max(maxSum, (lSum+rSum));
        }

        return maxSum;  // O(1)
    }