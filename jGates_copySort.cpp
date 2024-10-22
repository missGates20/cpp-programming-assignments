// File name: jGates_copySort.cpp
// Author: JGates
// ID: 1338229
// Last version date: 10/9/2024
// Short description: sort array
#include <iostream>
using namespace std;

//function prototypes
void getSize(int &);
void getDisplay(char &);
int * fillArray(int[], int);
void copyArray(int[], int[], int);
void displayA(int[], int);//ascending
void displayD(int[], int);//descending

int main() {
// program introduction
    cout<<"This program will allow you to input numbers into an array\nand the system will print out in ascending or descending order.\n";
    //variable/array declarations
    int input[100];
    int size;
    char order;
    
    //call functions
    getSize(size);
    //copy array
    int copy[100];
   
    int *ptr = fillArray(input, size);//assign ptr, so it can used in copyArray function
    copyArray(ptr, copy, size);
    
    getDisplay(order);
    
    //do one function or another, based on user input.
    if(order == 'A')
        displayA(copy, size);
    else
        displayD(copy, size);
    
    
    return 0;
}

void getSize(int &size){
    /*
     purpose: get the number of inputs (size) from user
     input: size (pass by ref)
     output: none (updated size, done inside of function)
     process: accept size input if the number is between 1-100.
     */
    //get size/number of inputs from user
    do{
        cout << "How many numbers are you entering? (1-100)>> ";
        cin >> size;
    }while (size<1 || size > 100);//data validation
}

void getDisplay(char &order){
    /*
     purpose: get display preferance from user
     input: order (pass by ref)
     output: none (updated order, done inside of function)
     process: accept order input if the char is 'A' or 'D'
     */
    //get user input on display preference
    do{
        cout << "Do you want the display in ascending or descending order (A or D)>> ";
        cin >> order;
        order = toupper(order);
    }while (order != 'A' && order != 'D');//data validation
}


int * fillArray(int input[], int size){
    /*
     purpose: get input for input array
     input: input array, size
     output: pointer (ptr)
     process: use for loop to fill input array, return pointer (ptr)
     */
    //pointer
    int * ptr = nullptr;
    ptr = input;
    //get user input
    for(int i = 0; i <size; i++){
        cout <<"enter integer "<<i+1<<" >> ";
        cin >> *(ptr + i);
    }
    //return value
    return ptr;
}

void copyArray(int *ptr, int copy[], int size){
    /*
     purpose: copy input array value to "copy" array
     input: *ptr, copy array, size
     output: none (updated copy array, done inside of function)
     process: use for loop to add values from input array to the "copy" array
     */
    
    //copying original array
    for(int i = 0; i <size; i++){
        *(copy+ i) = *(ptr+i);
    }
}

void displayA(int copy[], int size){
    /*
     purpose: sort the copy array into ascending order, and display the array
     input: copy array, size
     output: none (updated copy array, and display, done inside of function)
     process: sort array in ascending order, and display
     */
    //variable declaration
    int max_index;
    //selection sort
    for (int k = 0; k < size-1; k++)
    {
        max_index = k;//gets first element in array
        for (int i = k+1; i < size; i++){//comparing max_index to next element in array
            if(*(copy + i)<*(copy+ max_index)){
                max_index=i;}//if next element is smaller, create new index
        }
        
        if(max_index!=k)//swap value max_index with the "first" value, if needed
            swap(*(copy+ max_index),*(copy+ k));
    }
    //display result
    cout << "{ ";
    for(int e =0; e < size; e++){
        cout << *(copy + e) << " ";}
    cout << "}" <<endl;
}

void displayD(int copy[], int size){
    /*
     purpose: sort the copy array into descending order, and display the array
     input: copy array, size
     output: none (updated copy array, and display, done inside of function)
     process: sort array in descending order, and display
     */
    //variable declaration
    int min_index;
    //selection sort
    for (int k = 0; k < size-1; k++)
    {
        min_index = k;//gets first element in array
        for (int i = k+1; i < size; i++){//comparing max_index to next element in array
            if(*(copy + i)>*(copy+ min_index)){
                min_index=i;}//if next element is larger, create new index
        }
        
        if(min_index!=k)//swap value max_index with the "first" value, if needed
            swap(*(copy+ min_index),*(copy+ k));
    }
    //display result
    cout << "{ ";
    for(int e =0; e < size; e++){
        cout << *(copy + e) << " ";}
    cout << "}" <<endl;
}

/*
Test data:
Sample 1:
 This program will allow you to input integers into an array
 and the system will print out in ascending or descending order.
 How many numbers are you entering? (1-100)>> 5
 enter integer 1 >> 4
 enter integer 2 >> 0
 enter integer 3 >> 3
 enter integer 4 >> 6
 enter integer 5 >> 7
 Do you want the display in ascending or descending order (A or D)>> A
 { 0 3 4 6 7 }
 Program ended with exit code: 0
 
Sample 2:
 This program will allow you to input integers into an array
 and the system will print out in ascending or descending order.
 How many numbers are you entering? (1-100)>> 5
 enter integer 1 >> 4
 enter integer 2 >> 10
 enter integer 3 >> 3
 enter integer 4 >> 8
 enter integer 5 >> 2
 Do you want the display in ascending or descending order (A or D)>> D
 { 10 8 4 3 2 }
 Program ended with exit code: 0
 
 Sample 3:
 This program will allow you to input integers into an array
 and the system will print out in ascending or descending order.
 How many numbers are you entering? (1-100)>> 0
 How many numbers are you entering? (1-100)>> 101
 How many numbers are you entering? (1-100)>> -1
 How many numbers are you entering? (1-100)>> -5
 How many numbers are you entering? (1-100)>> 200
 How many numbers are you entering? (1-100)>> 8
 enter integer 1 >> 10
 enter integer 2 >> 30
 enter integer 3 >> 20
 enter integer 4 >> 1
 enter integer 5 >> 4
 enter integer 6 >> 6
 enter integer 7 >> 7
 enter integer 8 >> 8
 Do you want the display in ascending or descending order (A or D)>> A
 { 1 4 6 7 8 10 20 30 }
 Program ended with exit code: 0
 
 Sample 4:
 This program will allow you to input integers into an array
 and the system will print out in ascending or descending order.
 How many numbers are you entering? (1-100)>> 5
 enter integer 1 >> 9
 enter integer 2 >> 2
 enter integer 3 >> 8
 enter integer 4 >> 4
 enter integer 5 >> 1
 Do you want the display in ascending or descending order (A or D)>> t
 Do you want the display in ascending or descending order (A or D)>> T
 Do you want the display in ascending or descending order (A or D)>> R
 Do you want the display in ascending or descending order (A or D)>> E
 Do you want the display in ascending or descending order (A or D)>> d
 { 9 8 4 2 1 }
 Program ended with exit code: 0
 
 Sample 5:
 This program will allow you to input integers into an array
 and the system will print out in ascending or descending order.
 How many numbers are you entering? (1-100)>> 10
 enter integer 1 >> 4
 enter integer 2 >> 20
 enter integer 3 >> 3
 enter integer 4 >> 56
 enter integer 5 >> 1
 enter integer 6 >> 20
 enter integer 7 >> 8
 enter integer 8 >> 7
 enter integer 9 >> 9
 enter integer 10 >> 0
 Do you want the display in ascending or descending order (A or D)>> a
 { 0 1 3 4 7 8 9 20 20 56 }
 Program ended with exit code: 0
 
*/
