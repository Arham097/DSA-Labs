or(int i=0; i<n-1; i++){
        int minindex = i;
        for(int j=i+1; j<n; j++){
            if(A[minindex]>A[j]){
                minindex = j;
            }
        }
        swap(A[i],A[minindex]);
    }