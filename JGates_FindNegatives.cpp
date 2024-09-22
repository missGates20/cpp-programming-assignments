//
//  JGates_FindNegatives.cpp
//  hw9.18
//  number input system
//  9/12/24.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//function prototypes
void getSize(int&);
/*
 purpose: get the size of input from user
 input: size (call by ref)
 output: none (size)
 process: ask for a size between 1-50, and use this size value for the variable
 */
bool getInput(float [10][5], float[10][5], int, bool&);
/*
 purpose: getting array input from user (amount of input dictated by size value)
 input: numInput1, numInput2, size, anyNegatives
 output: anyNegatives (true or false)
 process: get input from user to add to numInput1/numInput2. If input is negative, change it to positive and add it to numInput2.
 */
void displayResult(float [10][5], float [10][5], int, bool);
/*
 purpose: display the values in arrays numInput1 and numInput2
 input: numInput1, numInput2, anyNegatives
 output: none (display message under anyNegatives if it == false, numInput1, and numInput2.
 process: use for loop to display arrays
 */
int main() {
    //array declaration
    float numInput[10][5];
    float numInput2[10][5];
    //varible declaration/initialization
    int size;
    bool anyNegatives=false;
    //program description
    cout<<"This program will store user input inside a 10x5 array,"<<endl
    <<"and display the input and also modify input to only positive numbers."<<endl;
    //function calling
    getSize(size);
    getInput(numInput, numInput2, size, anyNegatives);
    displayResult(numInput, numInput2, size, anyNegatives);
    
    return 0;
}
void getSize(int& size){
    //getting size (w/ data validation)
    do{
        cout << "How many numbers are you entering into the system (must be between 1-50)?>>";
        cin >> size;}while (size <= 0 || size > 50);
}

bool getInput(float numInput[10][5], float numInput2[10][5], int size, bool& anyNegatives){
    //getting array input
    //variable declaration/initialization
    float input;
    int i=0;
    int counter =1;
    //if user input/size of input is 1, do if statment below.
    if(size==1){
        cout << "Enter number "<<counter<<">> ";/*ask user for array input*/
        cin >> input;
        //add input to first array
        numInput[0][0]=input;
        //what to do if input is negative number
        if(input <0){
            anyNegatives =true;
            input=abs(input);/*change input to positive*/
            numInput2[0][0]=input;}/*add new input to modified array*/
        else
            numInput2[0][0]=input;/*add input to modified array*/
        cout << endl;}
    //do else statement below if user input/size of input is more than 1
    else{
        while (counter < size){
            for (int j = 0; j < size; j++){
                cout << "Enter number "<<counter<<">> ";
                cin >> input;
                //add input to first array
                numInput[i][j]=input;
                //what to do if input is negative number
                if(input <0){
                    anyNegatives =true;
                    input=abs(input);/*change input to positive*/
                    numInput2[i][j]=input;}/*add new input to modified array*/
                else
                    numInput2[i][j]=input;/*add input to modified array*/
                cout << endl;
                counter++;}//add to counter after input
            i++;}}//after column is filled, move to next row
        return anyNegatives;/*notes whether or not any inputs were negative*/}

void displayResult(float numInput[10][5], float numInput2[10][5], int size, bool anyNegatives){
    //variable declaration/initialization
    int p = 0;
    int k = 0;
    int counter1 = 1;
    int counter2 = 1;
    
    if (anyNegatives == false)/*displays message if no inputs were negative*/
        cout << "\nAll inputs were positive"<<endl;
    
    cout << setw(5);//for formatting
    //run the below if statement if input is equal to 1
    if(size==1){//displays results
        cout<<"Original input array: "<<endl;
        cout<<numInput[0][0]<<endl;
        cout<<"Modified input array: "<<endl;
        cout<<numInput2[0][0]<<endl;
    }
    //run this if input is greater than one
    else{
        cout<<"Original input array: "<<endl;
        //run until all numbers are displayed (doesn't have to be whole array)
        while (counter1 < size){
            for (int j = 0; j < size; j++){//column
                cout<<setw(5)<<numInput[p][j];
                counter1++;
                if(counter1%5 == 1)//for formatting: make a new row when first row is full(5 numbers)
                    cout << endl;}
            p++;//next row
    }
        
        cout<<"Modified input array: "<<endl;
        //run until all numbers are displayed (doesn't have to be whole array)
        while (counter2 < size){
            for (int j = 0; j < size; j++){//column
                cout<<setw(5)<<numInput2[k][j];
                counter2++;
                if(counter2%5 == 1)//for formatting: make a new row when first row is full(5 numbers)
                    cout << endl;
            }
            k++;}//new row
    }
}
/*
 Test run 1:
 This program will store user input inside a 10x5 array,
 and display the input and also modify input to only positive numbers.
 How many numbers are you entering into the system (must be between 1-50)?>>1
 Enter number 1>> 7


 All inputs were positive
 Original input array:
 7
 Modified input array:
 7
 Program ended with exit code: 0
 
 
 Test run 2:
 This program will store user input inside a 10x5 array,
 and display the input and also modify input to only positive numbers.
 How many numbers are you entering into the system (must be between 1-50)?>>1
 Enter number 1>> -209

 Original input array:
  -209
 Modified input array:
   209
 Program ended with exit code: 0
 
 
 Test run 3:
 This program will store user input inside a 10x5 array,
 and display the input and also modify input to only positive numbers.
 How many numbers are you entering into the system (must be between 1-50)?>>-1
 How many numbers are you entering into the system (must be between 1-50)?>>-9
 How many numbers are you entering into the system (must be between 1-50)?>>80
 How many numbers are you entering into the system (must be between 1-50)?>>100
 How many numbers are you entering into the system (must be between 1-50)?>>10
 Enter number 1>> 1

 Enter number 2>> 2

 Enter number 3>> 3

 Enter number 4>> 4

 Enter number 5>> 5

 Enter number 6>> 6

 Enter number 7>> 7

 Enter number 8>> 8

 Enter number 9>> 9

 Enter number 10>> 0


 All inputs were positive
 Original input array:
     1    2    3    4    5
     6    7    8    9    0
 Modified input array:
     1    2    3    4    5
     6    7    8    9    0
 Program ended with exit code: 0
 
 
 Test run 4:
 This program will store user input inside a 10x5 array,
 and display the input and also modify input to only positive numbers.
 How many numbers are you entering into the system (must be between 1-50)?>>25
 Enter number 1>> 1

 Enter number 2>> 2

 Enter number 3>> 3

 Enter number 4>> 2

 Enter number 5>> 3

 Enter number 6>> 4

 Enter number 7>> 3

 Enter number 8>> 4

 Enter number 9>> 5

 Enter number 10>> -4

 Enter number 11>> 5

 Enter number 12>> -6

 Enter number 13>> 6

 Enter number 14>> 7

 Enter number 15>> -8

 Enter number 16>> 7

 Enter number 17>> 8

 Enter number 18>> -9

 Enter number 19>> 8

 Enter number 20>> 9

 Enter number 21>> 10

 Enter number 22>> 20

 Enter number 23>> 30

 Enter number 24>> 40

 Enter number 25>> -50

 Original input array:
     1    2    3    2    3
     4    3    4    5   -4
     5   -6    6    7   -8
     7    8   -9    8    9
    10   20   30   40  -50
 Modified input array:
     1    2    3    2    3
     4    3    4    5    4
     5    6    6    7    8
     7    8    9    8    9
    10   20   30   40   50
 Program ended with exit code: 0
 
 Test run 5:
 This program will store user input inside a 10x5 array,
 and display the input and also modify input to only positive numbers.
 How many numbers are you entering into the system (must be between 1-50)?>>51
 How many numbers are you entering into the system (must be between 1-50)?>>50
 Enter number 1>> -749

 Enter number 2>> 773

 Enter number 3>> -183

 Enter number 4>> 783

 Enter number 5>> 366

 Enter number 6>> -48

 Enter number 7>> -58

 Enter number 8>> 470

 Enter number 9>> 226

 Enter number 10>> 444

 Enter number 11>> -374

 Enter number 12>> -366

 Enter number 13>> -996

 Enter number 14>> -14

 Enter number 15>> -799

 Enter number 16>> 800

 Enter number 17>> -852

 Enter number 18>> 576

 Enter number 19>> -717

 Enter number 20>> -837

 Enter number 21>> -459

 Enter number 22>> 505

 Enter number 23>> 209

 Enter number 24>> 763

 Enter number 25>> 59

 Enter number 26>> 848

 Enter number 27>> -574

 Enter number 28>> 244

 Enter number 29>> -70

 Enter number 30>> -347

 Enter number 31>> -314

 Enter number 32>> -602

 Enter number 33>> -193

 Enter number 34>> 8.12

 Enter number 35>> 83

 Enter number 36>> -5.15

 Enter number 37>> -384

 Enter number 38>> 110

 Enter number 39>> -152

 Enter number 40>> -479

 Enter number 41>> -372

 Enter number 42>> 4.20

 Enter number 43>> 56.8

 Enter number 44>> -.775

 Enter number 45>> -340

 Enter number 46>> -258

 Enter number 47>> -431

 Enter number 48>> 377

 Enter number 49>> 743

 Enter number 50>> 872

 Original input array:
  -749  773 -183  783  366
   -48  -58  470  226  444
  -374 -366 -996  -14 -799
   800 -852  576 -717 -837
  -459  505  209  763   59
   848 -574  244  -70 -347
  -314 -602 -193 8.12   83
 -5.15 -384  110 -152 -479
  -372  4.2 56.8-0.775 -340
  -258 -431  377  743  872
 Modified input array:
   749  773  183  783  366
    48   58  470  226  444
   374  366  996   14  799
   800  852  576  717  837
   459  505  209  763   59
   848  574  244   70  347
   314  602  193 8.12   83
  5.15  384  110  152  479
   372  4.2 56.80.775  340
   258  431  377  743  872
 Program ended with exit code: 0
 */
