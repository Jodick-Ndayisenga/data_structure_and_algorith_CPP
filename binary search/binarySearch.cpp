#include<iostream>
#include<string>
using namespace std;

class BinarySearch{
    int arraySize, highIndex, lowIndex;
    int myArray[100];

    public:
        void getValues();
        void sortArray();
        void searchValue();
        void displayValues();
};
void BinarySearch::getValues(){
    cout << "How many values do you want to Enter? ";
    cin >> arraySize;
    cout << "Enter your values: ";
    for (int i = 0; i <arraySize; i++){
        cin >> myArray[i];
    }
}

void BinarySearch::sortArray(){
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

void BinarySearch::searchValue(){
    sortArray();
    displayValues();
    string choice;
    int searchedValue;
    do
    {
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
            else if(myArray[midPoint]>searchedValue)highIndex = midPoint-1;
            else if(myArray[midPoint]<searchedValue)lowIndex = midPoint + 1;
        }
        if(!found)cout<<"\n\n"<<searchedValue<<" was not found!!";
        cout<<"\nContinue?: ";
        cin>>choice;

    } while (choice == "yes");
}

void BinarySearch::displayValues(){
     for(int i = 0; i < arraySize; i++){
        cout<<myArray[i]<<" ";
    }
}

int main(){

    BinarySearch search;
    search.getValues();
    search.searchValue();
   
    return 0;
}