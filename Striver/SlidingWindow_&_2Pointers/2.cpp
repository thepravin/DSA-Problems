/*
Longest Substring Without Repeating Characters
*/


// O(n2) , O(256)

int func(string str){
    int n = str.length();

    int maxLeng = 0;
    for(int i=0;i<n;i++){
        int hash[256] = {0};

        for(int j=i;j<n;j++){
            if(1 == hash[str[i]-'0']){
                break;
            }

            int len = j-i+1;
            maxLeng = max(maxLeng, len);
        }
    }

    return maxLeng;
}