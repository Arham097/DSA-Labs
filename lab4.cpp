// 1.	Give implementation of bubble sort algorithm let‟s assume Array “A” is consisting of 6elements which are stored in descending order.
#include<iostream>
using namespace std;
// void bubbleSort(int *A, int n){
//     int sorted = true;
//     for(int i=0; i<n-1; i++){
//         for(int j = 0 ; j<n-i; j++){
//             if(A[j]>A[j+1]){
//                 sorted = false;
//                 swap(A[j],A[j+1]);
//             }
//         }
//         if(sorted==true) break;
//     }
//  }

// 2.	Re-write bubble sort algorithm for recursive function call, Also analyze the worst time complexity ofrecursive bubble sort algorithm.

// void  recursive_bubbleSort(int *A, int n){
//     int i=0;
//     if(i==n-1){
//         return;
//     }
//     for(i; i<n-1; i++){
//         if(A[i]>A[i+1]){
//             swap(A[i],A[i+1]);
//         }
//     }
//     recursive_bubbleSort(A,n-1);
// }

// 3.	Select any other sorting algorithm and implement. Assume A[]={ 9,7,5,11,12,2,14,3,10,6}
void selectionSort(int* A, int n){
    for(int i=0; i<n-1; i++){
        int minindex = i;
        for(int j=i+1; j<n; j++){
            if(A[minindex]>A[j]){
                minindex = j;
            }
        }
        swap(A[i],A[minindex]);
    }
}

int main(){
    int A[] = {9,7,5,11,12,2,14,3,10,6};
    // int A[] = {6,5,4,3,2,1};
    int n = 10;

    // recursive_bubbleSort(A,n);

    selectionSort(A,n);

    // bubbleSort(A,n);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}