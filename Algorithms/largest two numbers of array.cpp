int largest(int n, int num[])
 {
     int largest,second;
     if(num[0]<num[1]){
      largest = num[1];
      second = num[0];
   }
   else{
      largest = num[0];
      second = num[1];
   }
   for (int i = 2; i< n ; i ++) {

      if (num[i] > largest) {
         second = largest;
         largest = num[i];
      }

      else if (num[i] > second && num[i] != largest) {
         second = num[i];
      }
   }
   cout<<"Second Largest Element and first largest in array is: "<<second<<" "<<largest;
   return 0;
 }
