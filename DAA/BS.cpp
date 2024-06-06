#include<iostream>
using namespace std;

int firstOccur(int arr[], int n, int k){
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == k){
            ans = mid;
            e = mid-1;
        }
        else if(k > arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        int mid = s + (e-s)/2;
    }
    return ans;

}
int lastOccur(int arr[], int n, int k){
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }
        else if(k > arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        int mid = s + (e-s)/2;
    }
    return ans;

}

int main(){

    int even[5]={1,2,3,3,4};

    cout << "first Occurrence of 3 is at index" << firstOccur(even,5,3) << endl;
    cout << "last Occurrence of 3 is at index" << lastOccur(even,5,3);

    return 0;
}