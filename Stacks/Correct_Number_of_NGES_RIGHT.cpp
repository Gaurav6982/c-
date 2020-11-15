#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
map<int,int> ans;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            int w=i;
            while(w<n1)
            ans[L[w++]]++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r)
{
    // vector<int> ans;
    if (l < r) {
 
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = (l + r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
    // return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    rep(i,n) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<ans[arr[i]]+1<<" ";
    cout<<endl;
    return 0;
}