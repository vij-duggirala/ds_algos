
int rotOranges(vector<vector<int>> &matrix, int R, int C)
{
    queue<pair<int, int>> q;
    int i ,j;
    
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            if(matrix[i][j] == 2)
                q.push(make_pair(i , j));
        
    
    int ans = 0;
    bool flag;
    
    pair<int, int> null = {-1  , -1};
    q.push(null);
    int row[4] = {-1 , 0 , 1 , 0};
    int col[4] = {0 , -1  , 0 , 1};
    
    while(!q.empty())
    {
        flag  = false;
        while(q.front().first != -1)
        {
            pair<int , int> p = q.front();
            q.pop();
            
            for(int k =0;k<4;k++)
            {
                i=p.first + row[k];
                j = p.second+ col[k];
                
                if(i>=0 && j>=0 && i<R && j<C && matrix[i][j]==1)
                {
                    matrix[i][j] = 2;
                    q.push(make_pair(i,j));
                    
                    if(!flag)
                    {
                        flag = true;
                        ans++;
                    }
                }
            }
        }
        q.pop();
        if(flag)
            q.push(make_pair(-1 , -1));
    }
        
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)    
            if(matrix[i][j] == 1)
                return -1;
                
    return ans;
}