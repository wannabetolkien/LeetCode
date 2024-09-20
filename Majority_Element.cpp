// QUESTION : Majority elements (frequency>n/2)

/*
Given an array nums of size n, return the majority element.The majority element is the element that
appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.
*/

// APPROACH : You take an element and keep count, when you find that element :count++ and if some other count--
// Note : Whenever count goes 0 , it means there are no majority element in that subarray.
// If by the end count remains non-zero, it implies that the element can be majority element. If the majority elements exist.

/* Nabeel Akhter - Bismillah */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lint long long int
#define mod 1000000007
lint brute(vector<lint> &a){
    int n= a.size();

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;i<n;i++){
            if(a[i]==a[j]){
                count++;
            }
        }
        if(count>n/2){
            return a[i];
        }
    }
}
lint better(vector<lint> &a){
    unordered_map<lint,lint> fre;
    for(lint i:a){
        fre[i]++;
    }

    for(auto i:fre){
        if(i.second>a.size()/2){
            return i.first;
        }
    }
}



int main(){
    vector<lint> a={2,2,1,1,1,2,2};
    cout<<brute(a);  
}
