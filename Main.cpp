#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

// Selection Sort - Gary
void selectionSort(int a[] , int size) {
  int outer, inner, min;
  for (outer = 0; outer < size - 1; outer++) {
    min = outer;
    for (inner = outer + 1; inner < size ; inner++) {
      if (a[inner] < a[min]) {
        min = inner;
    }
  }
  int temp = a[outer];
  a[outer] = a[min];
  a[min] = temp;
  }
}
// Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort - Raf
void bubbleSort(int arr[], int size) {
    int outer, inner, temp; 

    for (outer = size - 1; outer > 0; outer--) {    // Counting Down
        for (inner = 0; inner < outer; inner++) {   // Bubbling Up
            if (arr[inner] > arr[inner + 1]) {      // Compare left item to right item
                temp = arr[inner];                  // If left item is larger, swap
                arr[inner] = arr[inner + 1];
                arr[inner + 1] = temp;
            }
        }
    }
}

// Merge Sort - Gary
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int* L = new int[n1];
    int* R = new int[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    delete[] L, R;
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 

        merge(arr, l, m, r); 
    } 
}

// Quick Sort

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort - Raf
void maxHeapify(int nodeIndex, int heapArray[], int size) {
    int largest = nodeIndex;
    int left = (2 * nodeIndex) + 1;
    int right = (2 * nodeIndex) + 2;

    if (left < size && heapArray[left] > heapArray[largest]) {
        largest = left;
    }

    if (right < size && heapArray[right] > heapArray[largest]) {
        largest = right;
    }

    if (largest != nodeIndex) {
        int temp = heapArray[nodeIndex];
        heapArray[nodeIndex] = heapArray[largest];
        heapArray[largest] = temp;
        maxHeapify(largest, heapArray, size);
    }
}

void heapSort(int arr[], int size) {
    // Turn array into a heap
    for (int i = (size / 2) - 1; i >= 0; i--) {
        maxHeapify(i, arr, size);
    }
    // Turn heap into sorted array
    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(0, arr, i);
    }
}

// Display Menu 
void displayMenu() {
    cout << "\n----- Sorting Menu -----" << endl;
    cout << "1) Print Array" << endl;
    cout << "2) Selection Sort" << endl;
    cout << "3) Insertion Sort" << endl;
    cout << "4) Bubble Sort" << endl;
    cout << "5) Merge Sort" << endl;
    cout << "6) Quick Sort" << endl;
    cout << "7) Heap Sort" << endl;
    cout << "8) Reset Array" << endl;
    cout << "9) Exit" << endl;
    cout << "Select a sorting algorithm: ";
}

void validateInput(int& userChoice) {

    cin >> userChoice;
    while (cin.fail() || userChoice < 1 || userChoice > 9)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Please enter a valid option [1-9]: ";
        cin >> userChoice;
    }
}

void randomize(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 10000) + 1;
    }
}

void copyArray(int original[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = original[i];
    }
}

void printArray(int arr[]) {
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 25; i++) {
        cout << "Array[" << i << "]: " << arr[i] << "\t\tArray[" << i+25 << "]: " << arr[i + 25] << endl;
    }
}

void printSortAnalysis(int arr[], double t1, double t2, int sortType) {
    string type;

    switch (sortType) {
    case 1: type = "Selection";
        break;
    case 2: type = "Insertion";
        break;
    case 3: type = "Bubble";
        break;
    case 4: type = "Merge";
        break;
    case 5: type = "Quick";
        break;
    case 6: type = "Heap";
        break;
    }
    cout << "---------------------------------------" << endl;
    cout << "      Array after " << type <<"Sort" << endl;
    printArray(arr);
    cout << "Run Time: " << fixed << t2 - t1 << endl;
}

void ResetArray(int arr[], int copyarr[], int size) {
  for (int i = 0; i < size; i++) {
        arr[i] = copyarr[i];
    }
  printArray(arr);
  cout << "\n             ARRAY RESET " << endl;
  cout << "---------------------------------------" << endl;
}

double TimeSnap() {
    time_t t = clock();
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken;
}

int main() {
    int const size = 10000;
    int numList[size];
    int numListBackup[size];
    int userChoice = 0;
    double t1, t2;
  
    randomize(numList, size);
    copyArray(numList, numListBackup, size);
  
    while (userChoice != 9)
      {
        displayMenu();
        validateInput(userChoice);
    
        switch (userChoice) {
          case 1: printArray(numList);
          break;
          case 2: 
            t1 = TimeSnap();
            selectionSort(numList, size);
            t2 = TimeSnap();
            printSortAnalysis(numList, t1, t2, 1);
          break;
          case 3:
            t1 = TimeSnap();
            insertionSort(numList, size - 1);
            t2 = TimeSnap();
            printSortAnalysis(numList, t1, t2, 2); 
          break;
          case 4: 
              t1 = TimeSnap();
              bubbleSort(numList, size);
              t2 = TimeSnap();
              printSortAnalysis(numList, t1, t2, 3);
          break;
          case 5: 
            t1 = TimeSnap();
            mergeSort(numList, 0, size - 1);
            t2 = TimeSnap();
            printSortAnalysis(numList, t1, t2, 4);
          break;
          case 6:
            t1 = TimeSnap();
            quickSort(numList, 0, size - 1);
            t2 = TimeSnap();
            printSortAnalysis(numList, t1, t2, 5);
          break;
          case 7: 
            t1 = TimeSnap();
            heapSort(numList, size);
            t2 = TimeSnap();
            printSortAnalysis(numList, t1, t2, 6);
          break;
          case 8: 
            ResetArray(numList, numListBackup, size);
          break;
      }
    
    }

}
