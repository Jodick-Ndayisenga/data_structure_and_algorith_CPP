# Data structure and algorithms

## Linear Search

Linear search, also known as sequential search, is a simple search algorithm used to find the position of a target value within a list or array of elements. It sequentially checks each element in the list until a match is found or the end of the list is reached.

```cpp
void searchElement(){
    int value;
    bool found = false;
    cout<<"Enter the value you want to search: ";
    cin>>value;
    for(int i=0;i<size;i++){
        if(value==intArray[i]){
            cout<<value<<" was found at index "<<i;
            found = true;
        }
    }
    if(!found)cout<<value<<" was not found !!";
};
```

Here's how linear search works:

    The algorithm starts at the beginning of the list or array.

    It compares the target value with the current element in the list.

    If the target value matches the current element, the search is successful, and the position (index) of the element is returned.

    If the target value is not found, the algorithm moves to the next element in the list and repeats the comparison.

    The process continues until a match is found or the end of the list is reached.

    If the end of the list is reached without finding a match, the search is considered unsuccessful, and a special value (e.g., -1 or null) may be returned to indicate that the target value is not present in the list.

Linear search is a simple and straightforward algorithm that works well for small lists or when the elements are not in a particular order. However, it has a time complexity of O(n) in the worst case, where n is the number of elements in the list. This means that the time required for the search grows linearly with the size of the input.

Linear search is not suitable for large lists or when the elements are sorted or organized in a specific manner. In such cases, more efficient search algorithms like binary search or hash-based search algorithms are preferred, as they offer faster search times with lower time complexity.

## Binary Search

Binary search is a search algorithm used to find the position of a target value within a sorted list or array of elements. It follows a divide-and-conquer strategy by repeatedly dividing the search space in half until the target value is found or determined to be absent.

Here's how binary search works:

    Binary search requires a sorted list or array as input. If the input is not sorted, the elements must be sorted first.

    The algorithm starts with defining the boundaries of the search space, usually represented by two pointers: low and high. Initially, low points to the first element, and high points to the last element.

    The algorithm calculates the middle index mid as the average of low and high.

    It compares the target value with the element at the middle index (arr[mid]):
        If the target value is equal to arr[mid], the search is successful, and the position (index) of the element is returned.
        If the target value is less than arr[mid], the search continues in the lower half of the search space. The high pointer is updated to mid - 1.
        If the target value is greater than arr[mid], the search continues in the upper half of the search space. The low pointer is updated to mid + 1.

    The process repeats, dividing the search space in half with each iteration, until the target value is found or the low pointer becomes greater than the high pointer. In the latter case, the target value is not present in the array.

Binary search has a time complexity of O(log n), where n is the number of elements in the sorted array. This is because the search space is divided in half with each iteration, leading to a logarithmic reduction in the number of elements to search.

Binary search is efficient for large sorted arrays as it quickly eliminates half of the search space at each step, leading to faster search times compared to linear search. However, binary search requires the input to be sorted, and any changes to the array during the search would invalidate the algorithm's correctness.

It's worth noting that binary search is most effective when the access to the elements in the array is random or fast (e.g., accessing elements by index).

The provided code is an implementation of the binary search algorithm in C++. Let's go through the code and understand its purpose and functionality.

```cpp

#include<iostream>
#include<string>
using namespace std;
```

These are the header files included for input/output operations and string manipulation.

```cpp

class BinarySearch{
    int arraySize, highIndex, lowIndex;
    int myArray[100];

public:
    void getValues();
    void sortArray();
    void searchValue();
    void displayValues();
};
```

This is the declaration of a class named BinarySearch, which encapsulates the functionality related to binary search. It has private member variables arraySize, highIndex, lowIndex, and an integer array myArray of size 100. The class also declares four member functions: getValues(), sortArray(), searchValue(), and displayValues().

```cpp

void BinarySearch::getValues(){
    cout << "How many values do you want to Enter? ";
    cin >> arraySize;
    cout << "Enter your values: ";
    for (int i = 0; i <arraySize; i++){
        cin >> myArray[i];
    }
}
```

The getValues() function prompts the user to enter the number of values they want to input and then accepts these values into the myArray array.

In order to successfully find a value in array using binary search, you must sort the array.

## Three different ways to sort the array

### 1. Insertion sorting algorithm

```cpp

void BinarySearch::sortArray(){
    for(int i = 1; i<arraySize; i++){
        int j = i-1;
        int currentValue = myArray[i];

        while(j>=0 && currentValue < myArray[j])
        {
            myArray[j+1] = myArray[j];
            j--;
        }
        myArray[j+1] = currentValue;
    }
}
```

The sortArray() function performs an insertion sort algorithm on the myArray array. It iterates over the array, compares each element with the preceding elements, and shifts them accordingly to sort the array in ascending order.

### 2. bubble sort algorithm

```cpp
void sortArray(){
    int mySize = arraySize;
    for(int i = 0; i < mySize; i++){

        for(int k = 0; k < mySize-1; k++){
            if(myArray[k] > myArray[k + 1])
                swap(myArray[k], myArray[k + 1]);
        }

    }
}
```

The sortArray() function performs the sorting of the myArray array using the bubble sort algorithm. Here's how it works:

    It starts by initializing the mySize variable with the value of arraySize, which represents the number of elements in the array.

    The outer loop for(int i = 0; i < mySize; i++) runs mySize times, ensuring that each element is compared and sorted.

    Inside the outer loop, there is an inner loop for(int k = 0; k < mySize-1; k++). This loop iterates over the array from the first element to the second-to-last element.

    Within the inner loop, there is an if statement if(myArray[k] > myArray[k + 1]) that checks if the current element (myArray[k]) is greater than the next element (myArray[k + 1]).

    If the condition is true, the swap() function is called to swap the positions of the current and next elements, putting them in ascending order.

    After the inner loop completes, the outer loop moves to the next iteration, and the process continues until all elements are sorted.

### 3. Selection sort algorithm

```cpp
void selectionSort(){
    for (int i = 0; i < arraySize; i++){
        int min = i;
        for (int j = i + 1; j < arraySize; j++){
            if (myArray[min] > myArray[j])
                min = j;
        }
        swap(myArray[i], myArray[min]);
    }
}
```

The selectionSort() function performs the sorting of the myArray array using the selection sort algorithm. Here's how it works:

    The outer loop for (int i = 0; i < arraySize; i++) iterates through each element of the array.

    Inside the outer loop, a variable min is initialized with the value of i. This variable represents the index of the minimum element found so far in the unsorted portion of the array.

    The inner loop for (int j = i + 1; j < arraySize; j++) starts from the next element after i and iterates through the remaining unsorted elements of the array.

    Within the inner loop, there is an if statement if (myArray[min] > myArray[j]) that compares the value of the current minimum element (myArray[min]) with the value of the current element being checked (myArray[j]).

    If the value of the current element (myArray[j]) is smaller than the current minimum element (myArray[min]), it updates the value of min to the index j, indicating that myArray[j] is the new minimum element.

    After the inner loop completes, it means that the smallest element in the remaining unsorted portion of the array has been found. To move this smallest element to its correct position, the swap() function is called to swap the elements at indices i and min.

    The outer loop continues iterating, selecting the next smallest element from the remaining unsorted portion of the array and placing it in its correct position.

    The process continues until the entire array is sorted.

In summary, the selectionSort() function implements the selection sort algorithm to sort the myArray array in ascending order. It repeatedly selects the smallest element from the unsorted portion of the array and swaps it with the element at the beginning of the unsorted portion, gradually building the sorted portion of the array.

Selection sort has a time complexity of O(n^2) and is not the most efficient sorting algorithm for large arrays.

## Binary Search

```cpp
void BinarySearch::searchValue(){
    sortArray();
    displayValues();
    string choice;
    int searchedValue;
    do {
        cout<<"\nWhat is the number you want to search: ";
        cin>>searchedValue;
        lowIndex = 0;
        highIndex = arraySize-1;
        bool found = false;

        while(lowIndex <= highIndex){
            int midPoint = (lowIndex + highIndex)/2;
            if(searchedValue == myArray[midPoint]){
                cout<<searchedValue<<" was found at index "<<midPoint;
                found = true;
                break;
            }
            else if(myArray[midPoint] > searchedValue)
                highIndex = midPoint - 1;
            else if(myArray[midPoint] < searchedValue)
                lowIndex = midPoint + 1;
        }

        if(!found)
            cout<<"\n\n"<<searchedValue<<" was not found!!";

        cout<<"\nContinue?: ";
        cin>>choice;
    } while (choice == "yes");
}
```

The searchValue() function performs binary search on the sorted myArray array. It first calls the sortArray() function to ensure the array is sorted. Then, it displays the sorted array by calling the displayValues() function.

After that, it enters a loop where it asks the user for a value to search (searchedValue). It initializes the lowIndex and highIndex variables to the boundaries of the array. It uses a binary search algorithm to find the searchedValue in the array. If the value is found, it displays the index where it was found.
