//https://www.interviewbit.com/problems/combination-sum/
void backtrack(vector<int>A,vector<int>&path,vector<vector<int>>&res,int sum,int id){
    int n=A.size();
    if(sum<0)return ;
    if(sum==0){
        sort(path.begin(),path.end());
        auto it=find(res.begin(),res.end(),path);
        if(it==res.end())
        res.push_back(path);
        return;
    }
    for(int i=id;i<n;i++){
        if(sum+A[i]>=0){
            path.push_back(A[i]);
            backtrack(A,path,res,sum-A[i],i);
            path.pop_back();
        }
    }
    return ;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<int>path;
    vector<vector<int>>res;
    backtrack(A,path,res,B,0);
    sort(res.begin(),res.end());
    return res;
}



//https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#

vector<vector<int>>res;
    
    void backtrack(vector<int>A,vector<int>&ans,int start,int sum){
        if(sum==0){
            res.push_back(ans);
            return ;
        }
        if(sum<0)return;
        
        for(int i=start;i<A.size();i++){
            if(i>start&&A[i]==A[i-1])continue;
            ans.push_back(A[i]);
            backtrack(A,ans,i,sum-A[i]);
            ans.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>ans;
        res.clear();
        sort(A.begin(),A.end());
        backtrack(A,ans,0,B);
        return res;
    }
