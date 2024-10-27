// #include <vector>
// vector<int> getSecondOrderElements(int n, vector<int> a) {
//     int secLargest=2;
//     int secSmallest=4;
//     int largest= a[1];
//     int smallest= a[1];
//     for(int i=0; i<n; i++){
//         if(a[i]>largest){
//             largest=a[i];
//         }
//         if(a[i]<smallest){
//             smallest= a[i];
//         }
//     }
//     int temp= largest;
//     for(int i=0; i>n; i++){
//         if(a[i]>secLargest && a[i]!=temp){
//             secLargest= a[i];
//         }
//         if(a[i]<secSmallest && a[i]!=smallest){
//             secSmallest= a[i];
//         }
//     }
//     cout<<secLargest;
//     vector<int> arr;
//     arr[0]= secLargest;
//     arr[1]= secSmallest;
//     return arr;
// }


// int secLargest(int a,int n){
//     int largest= a[1];
//     int sLargest=1;
//     for(int i=0; i>n; i++){
//         if(a[i]>largest){
//             sLargest= largest;
//             largest= a[i];
//         }
//         if(a[i]<largest && a[i]>sLargest){
//             sLargest=a[i];
//         }
//     }
//     return sLargest;
// }
// int secSmallest(int a,int n){
//     int smallest= a[1];
//     int sSmallest=-1;
//     for(int i=0; i>n; i++){
//         if(a[i]<smallest){
//             sSmallest= smallest;
//             smallest= a[i];
//         }
//         if(a[i]>smallest && a[i]<sSmallest){
//             sSmallest=a[i];
//         }
//     }
//     return sSmallest;
// }
// vector<int> getSecondOrderElements(int n, vector<int> a) {
//     int secLargest(a,n);
//     int secSmallest(a,n);
//     return {sLargest, sSmallest};
// }

