// Question Link :- https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Rod Cutting

// T.C = O(N^2)
// S.C = O(N)

// Approach - 1
class Solution{
  public:
    int cutRod(vector<int> &price) {
       int n=price.size();
       
        
    int length[n];
	for (int i =0; i <n; i++) {
	     length[i]=i+1;
	}
	
	int t[n+1][n+1];
	
	for(int i=0;i<n+1;i++){
	    for(int j=0;j<n+1;j++){
	        if(i==0 || j==0)t[i][j]=0;
	        
	        
	    }
	}
	
	for(int i=1;i<n+1;i++){
	    for(int j=1;j<n+1;j++){
	        if(length[i-1]<=j){
	            t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
	        }else{
	            t[i][j]=t[i-1][j];
	        }
	    }
	}
	return t[n][n];
    }
};




// Approach - 2
class Solution{
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                dp[j] = max(dp[j], dp[j-i] + price[i-1]);
            }
        }
        return dp[n];
    }
};
