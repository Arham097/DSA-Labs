// 1.	Let an array named LA consist of 4 elements 2,4,6 & 8 . 
// write down the code to traverse(or print) all elements in the array.

// #include<iostream>
// using namespace std;

// int main(){
//     int LA[4] = {2,4,6,8};
//     int n = sizeof(LA)/sizeof(LA[0]);
//     for(int i=0; i<n; i++){
//         cout<<LA[i]<<" ";
//     }
//     return 0;
// }

// 2.	Use insertion algorithm to add an element (Give implementation)
// i.	1 at index 0 ii.	5 at index 2	iii. 3 at index 4

// #include <iostream>
// using namespace std;

// int* insert(int *arr, int& n, int x, int pos) {
//     if (n >= 10) {
//         cout << "Array is full. Cannot insert more elements." << endl;
//         return arr;
//     }

//     for (int i = n; i > pos; i--) {
//         arr[i] = arr[i - 1];
//     }
//     arr[pos] = x;
//     n++;

//     return arr;
// }

// int main() {
//     cout << "Original Array" << endl;
//     int LA[10] = {2, 4, 6, 8};
//     int n = 4;
//     for (int i = 0; i < n; i++) {
//         cout << LA[i] << " ";
//     }
//     cout << endl;

//     // i)
//     cout << "Inserted 1 at index 0" << endl;
//     int x1 = 1;
//     int pos1 = 0;
//     insert(LA, n, x1, pos1);

//     // ii)
//     cout << "Inserted 5 at index 2" << endl;
//     int x2 = 5;
//     int pos2 = 2;
//     insert(LA, n, x2, pos2);

//     // iii)
//     cout << "Inserted 3 at index 4" << endl;
//     int x3 = 3;
//     int pos3 = 4;
//     insert(LA, n, x3, pos3);

//     // Print the updated array
//     for (int i = 0; i < n; i++) {
//         cout << LA[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


// 3.	Consider the array in question 2 ,Use deletion algorithm(Give implementation) to remove an element
// i.	1 at index 0 ii. 5 at index 2	iii. 3 at index 4

#include<iostream>
using namespace std;

int Delete(int *arr, int n, int x){
    int i;
    for(i = 0; i<n; i++){
        if(arr[i]==x){
            break;
        }
    }
    if(i<n){
        n = n - 1;
        for(int j=i; j<n; j++){
            arr[j] = arr[j+1];
        }
    }
    return n;
}

int main(){
    cout<<"Original Array"<<endl;
    int arr[] = {1,2,5,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // i)
    int arr1[] = {1,2,5,4,3};
    int n1 = 5;
    int x1 = 1;
    // int pos1 = 0;
    n1 = Delete(arr1,n,x1);
    cout<<"(i) Deleted 1 from index 0"<<endl;
    for(int i=0; i<n1; i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;

    // ii)
   int arr2[] = {1,2,5,4,3};
   int n2 = 5;
    int x2 = 5;
    n2= Delete(arr2,n,x2);
    cout<<"(ii) Deleted 5 from index 2"<<endl;
    for(int i=0; i<n2; i++){
        cout<<arr2[i]<<" ";
    }cout<<endl;
    
    // iii)
   int arr3[] = {1,2,5,4,3};
   int n3 = 5;
    int x3 = 4;
    n3= Delete(arr3,n,x3);
    cout<<"(iii) Deleted 4 from index 3"<<endl;

    for(int i=0; i<n3; i++){
        cout<<arr3[i]<<" ";
    }
    


    return 0;
}