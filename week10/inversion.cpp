/*
LANG: C++
TASK: inversion
*/

#include<iostream>
using namespace std;

int arr[100010];
int sortarr[100010];

long long inv;

void count_inv(int left, int right, int mid)
{
    //index
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right){
        if (arr[i] > arr[j]){
            sortarr[k] = arr[j];
            k++;
            j++;
            inv = inv + (long long)mid - (long long)i + 1;
        }
        else{
            sortarr[k] = arr[i];
            k++;
            i++;
        }
    }

    while (i <= mid){
        sortarr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right){
        sortarr[k] = arr[j];
        j++;
        k++;
    }
    for (i = left; i < k; i++){
        arr[i] = sortarr[i];
    }
    // for(int i=0; i<k; i++){
    //     cout << "-----" <<  sortarr[i] << " ";
    // }
    // cout << "\n";
}

void mergesort(int start, int n)
{
    if(start < n){
        int mid = (start+n)/2;
        mergesort(start,mid);
        mergesort(mid+1,n);
        count_inv(start,n,mid);
    }
    return ;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    mergesort(0,n-1);
    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    cout << inv << "\n";
}