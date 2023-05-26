#include<iostream>
#include<string>
using namespace std;

class ArrayBuffer{
    int sizeOfArray;
    int myArray[50];

    public:
        void insertValue();
        void getArrayValues();
        void deleteArrayValue();
        void displayValues();
};


void ArrayBuffer::getArrayValues(){
    cout<<"How many values do you want to enter?: ";
    cin>>sizeOfArray;
    cout<<"Enter your values: ";
    for(int i=0; i<sizeOfArray; i++){
        cin >> myArray[i];
    }
};

void ArrayBuffer::insertValue(){
    int position, number;
    cout<<"Enter the position you want to insert: ";
    cin>>position;
    for(int i = sizeOfArray; i>= position; i--){
        myArray[i] = myArray[i-1];
    }
    cout<<"Enter the number you want to enter at that position: ";
    cin>>number;
    myArray[position] = number;
    sizeOfArray ++;
}

void ArrayBuffer::deleteArrayValue(){
    int indexOfValue;
    cout<<"Enter the index of the value you want to delete: ";
    cin>> indexOfValue;

    for (int i = indexOfValue; i<sizeOfArray; i++){
        myArray[i]= myArray[i+1];
    }
    sizeOfArray --;
}

void ArrayBuffer::displayValues() {
    cout<<"\n\n";
    for(int i=0; i<sizeOfArray; i++){
        cout<<myArray[i]<<"  ";
    }
    cout<<"\n\n";

};

int main(){
    int choice;
    string conti;
    ArrayBuffer array;
    array.getArrayValues();
    array.displayValues();

    do
    {
    cout<<"What do you want to do:\n1. Delete value\n2. Insert Value\n3. Display Values\nType choice: ";
    cin>>choice;
    if(choice == 1){
        array.deleteArrayValue();
        array.displayValues();
    }
     else if(choice == 2){
        array.insertValue();
        array.displayValues();
    }

    else if(choice == 3)array.displayValues();
    cout<<"Continue?: ";
    cin>>conti;
    }
    while(conti == "yes");

    return 0;
}