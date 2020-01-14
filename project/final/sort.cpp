// Carter Mooring, Jared Alano-Gray, & Jackson Lindsay
// Dr. Bowers
// CPSC 223
// sort.cpp
// This code sorts an array using cocktail, shell, separation and pigeon sort

using namespace std;

void separation_sort(int arr[], int n){
  int start = 0, end = n-1;
  int min, max = start;
while (start != end){                  // while the starting point of sorting
  for (int i = 0; i <= end; i++) {     // is not equal to end point of sorting
    if (arr[i] > arr[max]) {           // traverse up array to find max value
      max = i;
    }
  }
  if (max != end) {                    // checks if max is at the end
    swap(arr[max], arr[end]);          // if not swap max value with end
  }
  end--;                               // decrement unsorted region
  min = end;                           // initialize min val to be last val
  for (int j = end; j >= start; j--) { // traverse down the array to find min
    if (arr[j] < arr[min]) {
      min = j;
    }
  }
  if (start == end) {                  // Resolves case of even number size
    break;                             // array
  }
  if (min != start) {                  // checks if min is at the start
    swap(arr[min], arr[start]);        // if not swap min val and start
  }
  start++;                             // increment sorted region
  max = start;                         // initialize min to be first value
  }
}

// Sorts arrar a[0..n-1] using Cocktail sort
void cocktail_sort(int arr[], int n){
   bool flag = true;
   int start = 0, end = n-1;
   while(flag){
      flag = false;
      for(int i = start; i<end; i++){ //scan from left to right as bubble sort
         if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            flag = true;
         }
      }
      if(!flag){ //if nothing has changed simply break the loop
         break;
      }
      flag = false;
      end--; //decrease the end pointer
      for(int i = end - 1; i >= start; i--){ //scan from right to left
         if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            flag = true;
         }
      }
      start++;
   }
}

void shell_sort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
// The first gap elements a[0..gap-1] are already in gapped order
// keep adding one more element until the entire array is gap sorted
            int temp = arr[i];// save a[i] in temp and make a hole at position i
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
              // shift earlier gap-sorted elements up until the correct
              arr[j] = arr[j - gap];
            }
            arr[j] = temp; //  put temp in its correct location
        }
    }
}

void pigeonhole_sort(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) //while i is less than the size of the array
    {
        if (arr[i] < min){  //if spot is less than the min value,
                            //replace the min value
          min = arr[i];
        }
        if (arr[i] > max){  //also if spot is greater that max value,
                            //replace the max value
          max = arr[i];
        }
    }
    int range = max - min + 1;
    vector<int> holes[range]; //Create an array of vectors. Size of array range.
    //Each vector represents a hole that is going to contain matching elements.

    for (int i = 0; i < n; i++){
   // Traverse through input array and put every element in its respective hole
        holes[arr[i]-min].push_back(arr[i]);
    }

    // Traverse through all holes one by one.
    // For every hole, take its elements and put in array.
    int index = 0;  // index in sorted array
    for (int i = 0; i < range; i++){
      vector<int>::iterator it;
      for (it = holes[i].begin(); it != holes[i].end(); ++it){
        arr[index++]  = *it;
      }
    }
}
