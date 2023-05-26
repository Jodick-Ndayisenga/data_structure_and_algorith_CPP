#include<iostream>
#include<string>
using namespace std;

class BubbleSort{
    int arraySize;
    int myArray[50];

    public:
        void getValues();
        void sortArray();
        void displayValues();
};
void BubbleSort::getValues(){
    cout << "How many values do you want to Enter? ";
    cin >> arraySize;
    cout << "Enter your values: ";
    for (int i = 0; i <arraySize; i++){
        cin >> myArray[i];
    }
}
int jewe[] = {3,4,5,6,7};
void BubbleSort::sortArray(){
    int mySize = arraySize;
    for(int i = 0; i < mySize; i++){

        for(int k = 0; k < mySize-1; k++){
            if(myArray[k] > myArray[k +1])swap(myArray[k],myArray[k + 1]);
        }
        
    }
}

void BubbleSort::displayValues(){
    for(int i = 0; i < arraySize; i++){
        cout<<myArray[i]<<" ";
    }
}

int main(){
    BubbleSort arr;
    arr.getValues();
    arr.sortArray();
    arr.displayValues();

    return 0;
}