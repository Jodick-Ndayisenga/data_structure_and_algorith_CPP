#include<iostream>
#include<string>
using namespace std;

class SelectionSort{
    int arraySize;
    int myArray[100];
    
    public:
        void getArrayValues();
        void selectionSort();
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

void SelectionSort::selectionSort(){
    for (int i = 0; i<arraySize; i++){
        int min = i;
        for(int j=i+1;j<arraySize; j++){
            if(myArray[min]>myArray[j]) min = j;
        }
        swap(myArray[i], myArray[min]);
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
    selection.selectionSort();
    selection.displayValues();
    return 0;
}