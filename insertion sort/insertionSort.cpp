#include<iostream>
#include<string>
using namespace std;

class SelectionSort{
    int arraySize;
    int myArray[100];
    
    public:
        void getArrayValues();
        void insertionSort();
        void displayValues();
};

void SelectionSort::getArrayValues(){
    cout << "How many values do you want to Enter? ";
    cin >> arraySize;
    cout << "Enter your values: ";
    for (int i = 0; i <arraySize; i++){
        cin >> myArray[i];
    }
}

void SelectionSort::insertionSort(){
    for(int i = 1; i<arraySize; i++){
        int j = i-1;
        int currentValue = myArray[i];

        while(j>=0 && currentValue < myArray[j])
        {
           myArray[j+1] = myArray[j];
            j -- ;
        }
        myArray[ j+1 ]=currentValue;
    }
}

void SelectionSort::displayValues(){
    for(int i = 0; i < arraySize; i++){
        cout<<myArray[i]<<" ";
    }
}

int main(){
    SelectionSort selection;
    selection.getArrayValues();
    selection.insertionSort();
    selection.displayValues();
    return 0;
}