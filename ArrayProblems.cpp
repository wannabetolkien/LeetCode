/* Nabeel Akhter - Bismillah */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lint long long int
#define mod 1000000007

// Question No.1- Find the largest number in the array.
lint largest(vector<lint> &arr){
    lint largest=LLONG_MIN;
    for(int i=0;i<arr.size();i++){
        largest=max(largest,arr[i]);
    }

    return largest;
}

// Question No.2- Find the second largest number in the array without sorting the array.
lint secondLargest(vector<lint> &arr){
    lint largest=LLONG_MIN;
    lint sLargest=LLONG_MIN;

    for(int i=0;i<arr.size();i++){
        if(arr[i]>largest){
            sLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>sLargest){
            sLargest=arr[i];
        }
    }

    return sLargest;
}

// Question No.3- Check if the array given is roatated sorted array.
bool check(vector<lint>& arr) {
        bool flag=true;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1] && flag){
                flag=false;
                i++;
            }
            if(!flag && arr[i]<arr[i-1]){
                flag=true;
                break;
            }
        }

        if(flag || (arr[0]>=arr[arr.size()-1]))
        return true;
        else
        return false;
    }

// Question No.4: Remove duplicate elements from a sorted array inplace.
int removeDuplicates(vector<int> & a){
    int k=1;
    for(int i=1;i<a.size();i++){
        if(a[i]!=a[i-1]){
            a[k++]=a[i];
        }
    }

    for(int i=k+1;i<a.size();i++){
        a[i]=0;
    }
    return k;
}

//Question No.5: Left rotate the array by one place.
void leftRotate(vector<lint> &a){
    lint n=a.size();
    lint temp=a[0];
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1]=temp;
}

// Question No.6 : Left Rotate the Array by k places.
void leftRotateByK(vector<lint> &a,lint k){
    k%=a.size();
    reverse(a.begin(),a.begin()+k);
    reverse(a.begin()+k,a.end());
    reverse(a.begin(),a.end());
}

//Question No.7 : Move all the Zeros to the back of the array without disturbing relative ordering.
void zeroesToTheEnd(vector<lint> &arr){
    lint moved=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            arr[moved++]=arr[i];
        }
    }
    for(int i=moved;i<arr.size();i++){
        arr[i]=0;
    }

    for(lint x:arr){
        cout<<x<<" ";
    }
}

//Question No.8 : Find the union of two sorted array.
vector<lint> Union1(vector<lint> &a1, vector<lint> &a2) {
    vector<lint> ans;

    lint i = 0, j = 0;
    while (i < a1.size() && j < a2.size()) {
        if (a1[i] < a2[j]) {
            ans.push_back(a1[i]);
            i++;
            while (i < a1.size() && a1[i] == a1[i - 1]) {
                i++;
            }
        } 
        else if (a2[j] < a1[i]) {
            ans.push_back(a2[j]);
            j++;
            while (j < a2.size() && a2[j] == a2[j - 1]) {
                j++;
            }
        } 
        else {
            ans.push_back(a1[i]);
            i++;
            j++;
            while (i < a1.size() && a1[i] == a1[i - 1]) {
                i++;
            }
            while (j < a2.size() && a2[j] == a2[j - 1]) {
                j++;
            }
        }
    }

    while (i < a1.size()) {
        ans.push_back(a1[i]);
        i++;
        while (i < a1.size() && a1[i] == a1[i - 1]) {
            i++;
        }
    }

    while (j < a2.size()) {
        ans.push_back(a2[j]);
        j++;
        while (j < a2.size() && a2[j] == a2[j - 1]) {
            j++;
        }
    }

    return ans;
}

vector<lint> Union2(vector<lint> &a1, vector<lint> &a2) {
    vector<lint> ans;

    lint i = 0, j = 0;
    while (i < a1.size() && j < a2.size()) {
        if (a1[i] < a2[j]) {
            if (ans.empty() || a1[i] != ans.back()) { 
                ans.push_back(a1[i]);
            }
            i++;
        } 
        else if (a2[j] < a1[i]) {
            if (ans.empty() || a2[j] != ans.back()) { 
                ans.push_back(a2[j]);
            }
            j++;
        } 
        else { 
            if (ans.empty() || a1[i] != ans.back()) { 
                ans.push_back(a1[i]);
            }
            i++;
            j++;
        }
    }
  
    while (i < a1.size()) {
        if (ans.empty() || a1[i] != ans.back()) {
            ans.push_back(a1[i]);
        }
        i++;
    }

    while (j < a2.size()) {
        if (ans.empty() || a2[j] != ans.back()) {
            ans.push_back(a2[j]);
        }
        j++;
    }

    return ans;
}

// Question No.9 : Find the intersection of two sorted Array.

// Optimal Approach
vector<lint> intersectionOptimal(vector<lint> &a1,vector<lint> &a2){
    lint n=a1.size();
    lint m=a2.size();

    lint i=0,j=0;

    vector<lint> ans;
    while(i<n && j<m){
        if(a1[i]<a2[j]){
            i++;
        }
        else if(a1[i]>a2[j]){
            j++;
        }
        else{
            if(ans.empty() || ans.back()!=a1[i])
            ans.push_back(a1[i]);
            i++;
            j++;
        }
    }

    return ans;
}

// Brute Force 
vector<lint> intersectionBrute(vector<lint> &a1,vector<lint> &a2){

    lint n=a1.size();
    lint m=a2.size();

    map<lint,lint> visitation;
    for(int i=0;i<n;i++){
        visitation[a2[i]]=0;
    }

    vector<lint> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a1[i]==a2[j] && visitation[a2[j]]==0){
                visitation[a2[j]]++;
                ans.push_back(a2[j]);
                break;
            }
        }
    }

    return ans;
}

//Question No.10 :Find the maximum number of consecutive ones.
int maximumConsecutiveOnes(vector<lint> &a){
    lint n=a.size();
    lint maximum=0;
    lint current=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            current++;
        }
        else{
            maximum=max(maximum,current);
            current=0;
        }
    }
    maximum=max(maximum,current);
    return maximum;
}

// Question No.11 : Find the length of longest subarray with the give sum K.
//Brute Force
int lengthLongestSubArrayWithSumK_Brute(vector<lint> &a,lint k){
    int maximum=0;
    for(int i=0;i<a.size();i++){
        int sum=0;
        int length=0;
        for(int  j=i;j<a.size();j++){
            sum+=a[j];
            length++;
            if(sum>=k){
                maximum=max(maximum,length);
                break;
            }
        }
    }

    return maximum;
}
// Better Solution(If there are only positives ) - Optimal if positives as well as negatives are present.
lint lengthLongestSubArrayWithSumK_Better(vector<lint> &a,lint k){
   map<lint,lint> prefixSum;
   prefixSum[0]=-1;
   
   lint length=0;
   lint sum=0;
   for(int i=0;i<a.size();i++){
        sum+=a[i];

        if(prefixSum.find(sum)==prefixSum.end()){
            prefixSum[sum]=i;
        }

        lint diff=sum-k;
        if(prefixSum.count(diff)){
            length=max(length,i-prefixSum[diff]);
        }
   }

   return length;
}
//Optimal Solution : If there are only positives;
lint lengthLongestSubArrayWithSumL_Optimal_Positives(vector<lint> &a,lint k){
    lint i=0;
    lint j=0;
    lint sum=0;
    lint length=0;
    while(j<a.size()){

        sum+=a[i];

        while(sum>k && i<=j){
            sum-=a[i];
            i++;
        }

        if(sum==k)
        length=max(length,j-i+1);

        j++;
    }

    return length;
}
int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    vector<lint> a1={1,2,3,4,5,6,6,6};
    vector<lint> a2={3,3,3,4,4,5,6,7,7,8};
    vector<lint> ans=intersectionBrute(a1,a2);
    for(lint i:ans){
        cout<<i<<" "; 
    }
}