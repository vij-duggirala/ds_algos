class Solution {
    map<int , vector<int>> m;
public:
    bool helper(vector<int> &color , int i )
    {
        queue<int>q;
        while(!q.empty())
                q.pop();
        q.push(i);
        color[i] = 1;
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            if(!m.count(top))
                continue;
            vector<int> neig = m[top];
            
            
            
            for(i=0;i<neig.size();i++)
                if(color[neig[i]] == color[top])
                        return true;
                else if(color[neig[i]] == 0){
                    color[neig[i]] = -1 * color[top]; q.push(neig[i]);
                }            
        }
        
        return false;
     
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        queue<int> q;
        vector<int> color(N+1 , 0);
        int i;
        for(i=0;i<dislikes.size();i++){
                m[dislikes[i][0]].push_back(dislikes[i][1]); m[dislikes[i][1]].push_back(dislikes[i][0]);}
        
        for(i=1;i<=N;i++)
            if(color[i]==0)
                if(helper(color , i))
                    return false;
       return true;
        
    }
};