#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;
typedef map< char,lli> mp;

int hashTableSize=20;
int Frequency[26];


void countFre(string S)
    {
        for(int i = 0;i < S.length();++i)
        {
            int index = S[i]-'a';
            Frequency[index]++;
        }
        int min1=S.length();
        for(int i = 0;i < 26;++i){
            if(Frequency[i]>1)
            min1=min(min1,Frequency[i]);
        }
        cout<<S.length()-min1;
            
    }
int main()
{
    int t;
    string s,p;
    cin>>s>>p;
    int k=s.size();
    s+=p;
    int n=s.size();
    int z[n];

    int L = 0, R = 0;
    for (int i = 1; i < n; i++) 
    {
        if (i > R) 
        {
            L = R = i;
            while (R < n && s[R-L] == s[R]) 
            {
                R++;
            }
            z[i] = R-L; 
            R--;
        } 
        else 
        {
            int k = i-L;
            if (z[k] < R-i+1) 
            {
                z[i] = z[k];
            } 
            else 
            {
                L = i;
                while (R < n && s[R-L] == s[R]) 
                {
                    R++;
                }
                z[i] = R-L; 
                R--;
            }
        }
    }
    int count=0;
    for(lli i=k;i<n;i++){
        if(z[i]>=k)count++;
    }
    cout<<count<<endl;

    return 0;
}