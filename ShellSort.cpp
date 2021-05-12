int [] ShellSort(int a[], int n){
   for(int gap=n/2;gap>0;gap/=2){
        for(int i = gap;i<n;i++){
            int index= i;
            while(index>=gap && a[index-gap]>a[index]){
                swap(a[index-gap] , a[index]);
                index -= gap;
            }
        }
    }    
}

//decrease the gap by dividing by 2 and then sort the array formed by gap in the array using insertion sort
//this you will get a time complexity of n(logn)^2 which is kind of descent complexity