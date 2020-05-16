 bool isMatch(string s, string p) {
        if(!p.length())
            return !s.length();
           
        int m = s.length(); 
        int n = p.length();
           int i, j;
        bool dp[m+1][n+1];
           
    
        dp[0][0] = true;
        for(i=1;i<=n;i++)
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-2];
            else
                dp[0][i] = false;
        
        for(i=1;i<=m;i++)
                    dp[i][0] = false;

        
        
           
           
           
           for(i=1;i<=m;i++)    
                for(j=1;j<=n;j++)
                {
                    dp[i][j] =false;
                   if(s[i-1] == p[j-1] || p[j-1] == '.')
                       dp[i][j] = dp[i-1][j-1];
                
                    else if(p[j-1] == '*')
                    {
                        
                        dp[i][j] = dp[i][j-2];
                        
                        if(p[j-2] == s[i-1] || p[j-2] == '.')
                                dp[i][j] = dp[i][j] || dp[i-1][j];
                                    
                    }
                    else
                        dp[i][j] = false;
                    
                }
           
           
           return dp[m][n];
        
        
        
        
        
        
        
        
        
    }