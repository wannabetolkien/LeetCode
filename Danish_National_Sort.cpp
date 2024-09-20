//  QUESTION - Danish National Flag Sorting ( Sort 0,1,2) 

/* 

Given an array nums with n objects colored red, white, or blue,sort them in-place so that objects of
the same color are adjacent,with the colors in the order red, white, and blue.We will use the integers
0,1 and2 to represent the color red, white, and blue, respectively.

*/
// APPROACH - Optimal

//           1) Array from 0 to low-1 are all zeros.
//           2) Array from low to mid-1 is made up of 1s.
//           3) Array from mid to high-1 is unsorted.
//           4) Array from high to n-1 is sorted.

// Now the idea is that first,second and last portion are of size zero.
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lint long long int
#define mod 1000000007

void brute(vector<lint> &a){
    sort(a.begin(),a.end());
    for(int i:a)
    cout<<i<<" ";
}
void better(vector<lint> &a){

    int n=a.size();

    lint zero=0,one=0,two=0;

    for(int i=0;i<n;i++){
        if(a[i]==0){
            zero++;
        }
        else if(a[i]==1){
            one++;
        }
        else{
            two++;
        }
    }

    for(int i=0;i<zero;i++){
        a[i]=0;
    }
    for(int i=zero;i<(zero+one);i++){
        a[i]=1;
    }
    for(int i=(zero+one);i<n;i++){
        a[i]=2;
    }

    for(int i:a)
    cout<<i<<" ";
}
void optimal(vector<lint> &a){

    int low=0,mid=0,high=a.size()-1;
    
    while(mid<=high){
        if(a[mid]==0){
            // Element at a[low] will be 1 and Element at a[mid] is zero.
            // Swapping the would bring zero at low and low++ so the rule of zero till low-1 remains.
            // Swapping would bring one at mid and mid++ so rule of elements from low to mid-1 being 1 remains.
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==2){
            // at a[mid], there is some 2 and if  swapped to high, a[high] will be 2.
            // high-- will ensure that elements from high+1 to n-1 are 2.
            // Now the element that has came to mid can be anything and hence need further checks.
            // So, No mid++;
            swap(a[mid],a[high]);
            high--;
        }
        else{
            mid++;
            // It means that a[mid]==1 and hence just move forward.
        }
    }
}

int main(){
    vector<lint> nums= {2,0,2,1,1,0};
    better(nums);
}