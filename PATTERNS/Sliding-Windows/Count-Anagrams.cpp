
class Solution{
public:
    
    bool allZeros(vector<int>&frq){
        for(int& num : frq){
            if(num!=0)return false;
        }
        return true;
    }

	int search(string pat, string txt) {
	    int n = pat.length();
	    int m = txt.length();
	    
	    vector<int>frq(26,0);
	    for(char ch : pat){
	        frq[ch-'a']++;
	    }
	    
	    int i = 0;
	    int j= 0;
	    int result = 0;
	    
	    while(j<m){
	        frq[txt[j]-'a']--;
	           if((j-i+1)==n){
	               if(allZeros(frq)){
	                   result++;
	               }
	               frq[txt[i]-'a']++; // reset the frq of i char.
	               i++;
	           }
	           j++;
	    }
	    
	    return result;
	    
	}

};