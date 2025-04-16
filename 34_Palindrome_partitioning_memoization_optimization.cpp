// Question Link :- https://leetcode.com/problems/palindrome-partitioning-ii/
// Palindrome Partitioning II

// Memoization Optimized (striver)
// T.C = O(N^2) There are a total of N states and inside each state, a loop of size N(apparently) is running.
// S>C = O(N) ->[dp array] + Auxiliary stack space O(N)
class Solution {
public:
    bool isPalindrome(string& X, int i, int j) {  // Note:- pass string by reference, to avoid TLE
        while (i <= j) {
            if (X[i] != X[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    int Solve(string &str, int i, int j, vector<int> &t) {
        // Base case: If we've reached the end of the string.
        if (i >= j) {
            return 0;
        }
        if (t[i] != -1) {
            return t[i];
        }
        int ans = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int k = i; k <= j-1; k++) {
            if (isPalindrome(str, i, k)) {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int temp_ans = 1 + Solve(str, k + 1, j, t);
                ans = min(ans, temp_ans);
            }
        }
        return t[i] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> t(n, -1);
        return Solve(s, 0, n, t) - 1;
    }
};

//Added By rahman
//LeetCode solution passing all test cases. When we get a palindrome, we take it as one cut and then recursively solve the rest. 
// Recursion calls are reduced this way. Also, string should be passed as reference both in isPalindrome and solve functions, otherwise would give TLE.

class Solution {
public:
 int t[2001][2001];
 	bool isPalindrome(string &s, int i, int j)
 	{
 		while (i < j)
 		{
 			if (s[i] != s[j])
 			{
 				return false;
 			}

 			i++;
 			j--;
 		}

 		return true;
 	}

 	int solve(string &s, int i, int j)
 	{
 		if (i >= j)
 		{
 			return 0;
 		}

 		if (t[i][j] != -1)
 		{
 			return t[i][j];
 		}

 		if (isPalindrome(s, i, j) == true)
 		{
 			return 0;
 		}

 		int ans = INT_MAX;
 		for (int k = i; k<=j-1; k++)
 		{
 			if (isPalindrome(s, i, k))
 			{
 				ans = min(ans, 1 + solve(s, k + 1, j));
 			}
 		}

 		return t[i][j] = ans;
 	}

 	int minCut(string s)
 	{
 		int i = 0;
 		int j = s.length() - 1;
 		memset(t, -1, sizeof(t));
 		return solve(s, i, j);
 	}
};
