// Q#1) Assume array [ ] = {2, 4, 6, 8,}. Give implementation of Linear search algorithm to ;
// i) Find element 8 in array
// ii) Find element 3 in array

// #include<iostream>
// using namespace std;

// int linearSearch(int arr[], int n, int k){
//     for(int i =0; i<n; i++){
//         if(arr[i]==k) {
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     int arr[] = {2,4,6,8};
//     int n=4;
//     int key = 8;  // (i) when key is 8
//     // int key = 3;  // (ii) when key is 3
//     int ans = linearSearch(arr,n,key);
//     if(ans==-1){
//         cout<<"Element is not present "<< endl;
//     } 
//     else{
//         cout<<"Element is present at: "<<ans<<endl;
//     }
//     return 0;
// }


/* Q#2) let assume A[]= {2,5,5,5,6,6,8,9,9,9} sorted array of integers containing duplicates,
 apply binary search algorithm to Count occurrences of a number provided, 
 if the number is not found in the array report that as well. (Give implementation).
*/


#include<iostream>
using namespace std;

int leftOccurence(int *arr, int n, int k){
    int s = 0;
    int e = n-1;
    int result = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k) {
            result = mid;
            e = mid - 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return result;
}

int rightOccurence(int *arr, int n, int k){
    int s = 0;
    int e = n-1;
    int result = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k) {
            result = mid;
            s = mid + 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return result;
}


int main(){
    int arr[] = {2,5,5,5,6,6,8,9,9,9};
    int n=10;
    int key = 5; // (case 1)
    //int key = 4; //(case 2)

    int left = leftOccurence(arr,n,key);
    int right = rightOccurence(arr,n,key);

    int ans = right-left+1;
    if(left==-1|| right==-1){
        cout<<"Element "<<key<<" is not present "<<endl;
    } 
    else{
        cout<<"Element "<<key<<" occurs "<<ans<<" times"<<endl;
    }
    return 0;
}

