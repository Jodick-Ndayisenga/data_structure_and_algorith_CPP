#include<iostream>
#include<string>

using namespace std;

class BinarySearch{
    int size;
    int intArray[50];

    public:
        void getElements();
        void searchElement();
        void displayElements();
};

void BinarySearch::getElements(){
    cout<<"How many values do you want to enter?: ";
    cin>>size;
    cout<<"Enter your values: ";
    for(int i=0;i<size;i++){
        cin>>intArray[i];
    }
}

void BinarySearch::searchElement(){
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

void BinarySearch::displayElements(){
    cout<<"\n";
    for(int i=0; i<size; i++){
        cout<<intArray[i]<<" ";
    }
    cout<<"\n";
};

int main(){
    BinarySearch firstSearch;
    firstSearch.getElements();
    firstSearch.searchElement();
    firstSearch.displayElements();
    return 0;
}