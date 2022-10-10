// find occurence of pattern in given string s
// cp-algorithms: https://cp-algorithms.com/string/prefix-function.html#final-algorithm
// hackerearth: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/tutorial/ 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int bruteForce(string &pattern, string &s){           //Time complexity: O(n*k)
    int j,ans=0;
    for(int i=0;i<s.size();i++){
        j=0;
        for(;j<pattern.size();j++){
            if(s[i+j]!=pattern[j])
            break;
        }

        if(j==pattern.size())
        ans++;
    }

    return ans;
}

vector<int> kmp(string s){                             //Time Complexity: O(n+k)
    vector<int> prefix(s.size(),0);
    int j;
    for(int i=1;i<s.size();i++){
        j=prefix[i-1];
        while(j>0 && s[i]!=s[j]){
            j=prefix[j-1];
        }

        if(s[i]==s[j])
            j++;

        prefix[i]=j;
    }
}

void main(){
    string s="ascbcdcdds",p="bcd";
    
    // Two methods
    // 1)   Hackerearth
    string t=p+'#'+s;
    vector<int> res1=kmp(t);
    int ans1=0;
    for(int i=p.size()+1;i<t.size();i++){
        if(res1[i]==p.size())
            ans1++;
    }

    // 2)   ApnaCollege
    vector<int> res2=kmp(p);
    int i=0,j=0,ans2=0;
    while(i<t.size()){
        if(s[i]==p[j])
            i++,j++;
        else{
            if(j!=0)
                j=res2[j-1];
            else
                i++;
        }

        if(j==p.size())
            ans2++;
    }
}
