// Question : Find the sum of Subarray that has the maximum Sum.

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

// APPROACH (Optimal) : Kadane's Algorithm
// Keep a variable sum and a variable max.
// When the value of sum goes negative, it's time to start a new SubArray because it will
// decrease the further summation.

/* Nabeel Akhter - Bismillah */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lint long long int
#define mod 1000000007


int  brute(vector<lint> & a){

    int m=INT_MIN;

    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }

            m=max(m,sum);
        }
    }

    return m;
}


void optimal(vector<lint> & a){
    lint sum=0;
    lint m=INT_MIN;

    vector<lint> ans;
    vector<lint> temp_ans;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        temp_ans.push_back(a[i]);

        if(sum<0){
            temp_ans.clear();
            sum=0;
        }

        if(sum>m){
            ans=temp_ans;
            m=sum;
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl<<"Maximum Sum of SubArray : "<<m;
}

int main(){
    vector<lint> a={-2,1,-3,4,-1,2,1,-5,4};
    optimal(a);
}