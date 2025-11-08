
/*
----------------------------------------------------------------------
 Approach : 1 (my devision)
 T.C = O( n )
 S.C = O( 1 )

1. take product of all elements of array
2. divide product for each number and store division into ans array.

Note : avoide zero
----------------------------------------------------------------------
*/

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int isZeroCount = 0;
        int product = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                isZeroCount++;
            } else {
                product *= nums[i];
            }
        }

        vector<int> ans(n, 0);

        if (isZeroCount > 1) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[i] = product;
            } else if (isZeroCount > 0) {
                ans[i] = 0;
            } else {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }


/*
----------------------------------------------------------------------
 Approach : 2 (previous elements product * next all elements product)
 T.C = O( 3n )
 S.C = O( 2n ) --> use dynamic array using 'new'
----------------------------------------------------------------------
*/

 vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n,0);
        vector<int> prefixProduct(n, 0);
        vector<int> suffixProduct(n, 0);

        prefixProduct[0] = nums[0];
        suffixProduct[n - 1] = nums[n - 1];

        // prefix product 
        for (int i = 1; i < n; ++i) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i];
        }

        // suffix product
        for (int i = n - 2; i >= 0; --i) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i];
        }


        ans[0] = suffixProduct[1];
        for (int i = 1; i < n - 1; i++) 
        {
            ans[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
        }

        ans[n - 1] = prefixProduct[n - 2];

        return ans;
    }