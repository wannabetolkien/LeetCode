// Question : NEXT PERMUTATION

// Approach : Closer the permuation in dictionary, longer the prefix they share.
// When you have used the the amount of numbers and formed the biggest number, now
// it is just about finding the number that slides and then swapping it with the next greatest
// number.

/* Nabeel Akhter - Bismillah */

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lint long long int
#define mod 1000000007

void nextPermutation(vector<lint> &a){
    int size=a.size()-1;
    int i=size;
    int index1=-1;
    while(i>0 && a[i]<=a[i-1]){
        i--;
    }
    int index1=i-1;
    
    if(i!=0){
        int j=size;
        while(a[j]<=a[index1]){
            j--;
        }

        swap(a[index1],a[j]);
    }

    reverse(a.begin()+index1+1,a.end());
}

int main(){
    vector<int> a={2,1,5,4,3,0,0};
    next_permutation(a.begin(),a.end());
    for(int i:a){
        cout<<i<<" "; 
    }
}