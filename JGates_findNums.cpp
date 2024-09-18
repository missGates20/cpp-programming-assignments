// Jossie Gates 1338229
//  HW
//  JGates_findNums
//  create unique array of numbers
//  9/4/24.
//

#include<iostream>
#include<iomanip>
using namespace std;
//function prototypes
void getAndCheckInput(double [], int);
float findMax(double [], int);
float findMin(double [], int);

int main() {
    //program description
    cout << "This program will store user's input and display the largest and smallest numbers entered."<<endl;
    //variable declaration
    double maximum, minimum;
    double nums[100];//array to store input
    int size;//how many numbers the user will input

    //variable initialization part 1: get size from user
    do{
        cout << "What is the size of the array (between 10-100)?>> ";
        cin >> size;
    }while(size<10 || size>100); // has to be 10 or larger to continue
 
    //variable initialization part 2: call function to get array input from user
    getAndCheckInput(nums, size);

    //variable intialization part 3: call function to find the min and max number in the array
    //display finding
    cout << "Largest entry: " << findMax(nums, size) << endl;
    cout << "Smallest entry: " << findMin(nums, size) << endl;
    
    return 0;
}
//function definitions
void getAndCheckInput(double nums[], int size){
    /*
     Task: get user's input and also check for repeating numbers
     Input: the user-entered array and the size/number of numbers in the array
     Output: nums array with numbers inside it (done inside of the function. no output outside function).
     Process: use cin to fill the array and compare inputs to find repeating numbers. ask user for new input if there is a repeating number.
     */
    double input;//user's input
    bool repeat = false;
    for (int i = 0; i < size; i++)
    {
        cout << "Please enter element " << (i + 1) << ">> ";
        cin >> input;//get user input
        
        for(int j = 0; j<size;j++){
            if (nums[j]==input){
                repeat=true;
                break;}}//checking for any repeats
        
        //if there are repeats
        if (repeat){
            cout << "Duplicate input found\nPlease input an unique number.."<<endl;
            --i;
            repeat=false;}//reset boolen
        //if there aren't any repeats
        else{
            nums[i]=input;//add input to the array
            repeat=false;}//reset boolean
        
    }}

float findMax(double nums[], int size)
/*
 Task: find and store the largest number in the array
 Input: the user-entered array and the size/number of numbers in the array
 Output: the largest number in the array
 Process: compare input to the previous entry, and store the input if it's larger than the previous entry
 */
{
    int max = nums[0];//the first input in the array
    for (int i = 1; i < size; i++)
        if (max < nums[i])
            max = nums[i];
    //the value of the max variable changes as more numbers are put into the array.
    return max;
}

float findMin(double nums[], int size)
/*
 Task: find and store the smallest number in the array
 Input: the user-entered array and the size/number of numbers in the array
 Output: the smallest number in the array
 Process: compare input to the previous entry, and store the input if it's smaller than the previous entry
 */
{
    int min = nums[0]; //the first input
    for (int i = 1; i < size; i++)
        if (min > nums[i])
            min = nums[i];
    //the value of the min variable changes as more numbers are put into the array
    return min;
}

/*
 Test Run 1:
 This program will store user's input and display the largest and smallest numbers entered.
 What is the size of the array (between 10-100)?>> 15
 Please enter element 1>> 1
 Please enter element 2>> 2
 Please enter element 3>> 3
 Please enter element 4>> 4
 Please enter element 5>> 5
 Please enter element 6>> 6
 Please enter element 7>> 7
 Please enter element 8>> 8
 Please enter element 9>> 9
 Please enter element 10>> 10
 Please enter element 11>> 11
 Please enter element 12>> 12
 Please enter element 13>> 13
 Please enter element 14>> 14
 Please enter element 15>> 15
 Largest entry: 15
 Smallest entry: 1
 Program ended with exit code: 0
 
 Test Run 2:
 This program will store user's input and display the largest and smallest numbers entered.
 What is the size of the array (between 10-100)?>> 2
 What is the size of the array (between 10-100)?>> 7
 What is the size of the array (between 10-100)?>> 10
 Please enter element 1>> 10
 Please enter element 2>> 9
 Please enter element 3>> 1
 Please enter element 4>> 2
 Please enter element 5>> 4
 Please enter element 6>> 5
 Please enter element 7>> 6
 Please enter element 8>> 7
 Please enter element 9>> 8
 Please enter element 10>> 3
 Largest entry: 10
 Smallest entry: 1
 Program ended with exit code: 0
 
 Test Run 3:
 This program will store user's input and display the largest and smallest numbers entered.
 What is the size of the array (between 10-100)?>> 10
 Please enter element 1>> 1
 Please enter element 2>> 1
 Duplicate input found
 Please input an unique number..
 Please enter element 2>> 2
 Please enter element 3>> 3
 Please enter element 4>> 4
 Please enter element 5>> 1
 Duplicate input found
 Please input an unique number..
 Please enter element 5>> 5
 Please enter element 6>> 6
 Please enter element 7>> 7
 Please enter element 8>> 1
 Duplicate input found
 Please input an unique number..
 Please enter element 8>> 8
 Please enter element 9>> 1
 Duplicate input found
 Please input an unique number..
 Please enter element 9>> 9
 Please enter element 10>> 1
 Duplicate input found
 Please input an unique number..
 Please enter element 10>> 10
 Largest entry: 10
 Smallest entry: 1
 Program ended with exit code: 0
 
 Test Run 4:
 This program will store user's input and display the largest and smallest numbers entered.
 What is the size of the array (between 10-100)?>> 10
 Please enter element 1>> 10
 Please enter element 2>> 29
 Please enter element 3>> 40
 Please enter element 4>> 22
 Please enter element 5>> 44
 Please enter element 6>> 43
 Please enter element 7>> 29
 Duplicate input found
 Please input an unique number..
 Please enter element 7>> 10
 Duplicate input found
 Please input an unique number..
 Please enter element 7>> 23
 Please enter element 8>> 88

 Please enter element 9>> 100
 Please enter element 10>> 123
 Largest entry: 123
 Smallest entry: 10
 Program ended with exit code: 0
 
 Test run 5:
 This program will store user's input and display the largest and smallest numbers entered.
 What is the size of the array (between 10-100)?>> 101
 What is the size of the array (between 10-100)?>> 9
 What is the size of the array (between 10-100)?>> 4
 What is the size of the array (between 10-100)?>> 200
 What is the size of the array (between 10-100)?>> 10
 Please enter element 1>> 1
 Please enter element 2>> 2
 Please enter element 3>> 3
 Please enter element 4>> 4
 Please enter element 5>> 5
 Please enter element 6>> 6
 Please enter element 7>> 7
 Please enter element 8>> 8
 Please enter element 9>> 9
 Please enter element 10>> 10
 Largest entry: 10
 Smallest entry: 1
 Program ended with exit code: 0
 */

