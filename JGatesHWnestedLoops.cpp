/*********************************************************
* This template is made for XCode compiler
* file name: JGatesHWnestedLoops.cpp
* programmer name: -----------
* date created: 04/04/2024
* date of last revision: 04/07/2024
* details of the revision: fixing pyramid's format, adding comments
* short description: printing a pyramid w/ user's input
**********************************************************/

#include <iostream>
using namespace std;
int main()
{
    //Program description
    cout<<"This program will create a pyramid with user's input of total rows."<<endl;
    
    //Variable declaration/intialization
    int r, p, space, input, display=1;
    
    //Input validation
    do{
        cout << "Enter a positive integer: ";
        cin >> input;
    }while(input<0);
    
    //Creating/displaying pyramid
    for(r=1; r<=input; r++){//'r' controls number of rows printed. it runs until it matches user's input
        for(space=input; space>r; space--)
            cout<<"  ";//To prevent the pyramid from looking like a right triangle, goes until it matches user input
        
        for(p=0; p<r; p++){//'p' controls amount of numbers printed in each row.
            if (display<=9)
                cout<<display<<"   ";
            else
                cout<<display<<"  ";//Changes the amount of spaces for two digit numbers
            }
        cout<<endl;
        display++;//increase the number printed for each row (ex: first row -> 1, second row -> 2   2, etc)
    }
    return 0;}
/*
 Test run 1:
 This program will create a pyramid with user's input of total rows.
 Enter a positive integer: 5
         1
       2   2
     3   3   3
   4   4   4   4
 5   5   5   5   5
 Program ended with exit code: 0
 
 Test run 2:
 This program will create a pyramid with user's input of total rows.
 Enter a positive integer: 12
                       1
                     2   2
                   3   3   3
                 4   4   4   4
               5   5   5   5   5
             6   6   6   6   6   6
           7   7   7   7   7   7   7
         8   8   8   8   8   8   8   8
       9   9   9   9   9   9   9   9   9
     10  10  10  10  10  10  10  10  10  10
   11  11  11  11  11  11  11  11  11  11  11
 12  12  12  12  12  12  12  12  12  12  12  12
 Program ended with exit code: 0
 
 Test run 3:
 This program will create a pyramid with user's input of total rows.
 Enter a positive integer: 20
                                       1
                                     2   2
                                   3   3   3
                                 4   4   4   4
                               5   5   5   5   5
                             6   6   6   6   6   6
                           7   7   7   7   7   7   7
                         8   8   8   8   8   8   8   8
                       9   9   9   9   9   9   9   9   9
                     10  10  10  10  10  10  10  10  10  10
                   11  11  11  11  11  11  11  11  11  11  11
                 12  12  12  12  12  12  12  12  12  12  12  12
               13  13  13  13  13  13  13  13  13  13  13  13  13
             14  14  14  14  14  14  14  14  14  14  14  14  14  14
           15  15  15  15  15  15  15  15  15  15  15  15  15  15  15
         16  16  16  16  16  16  16  16  16  16  16  16  16  16  16  16
       17  17  17  17  17  17  17  17  17  17  17  17  17  17  17  17  17
     18  18  18  18  18  18  18  18  18  18  18  18  18  18  18  18  18  18
   19  19  19  19  19  19  19  19  19  19  19  19  19  19  19  19  19  19  19
 20  20  20  20  20  20  20  20  20  20  20  20  20  20  20  20  20  20  20  20
 Program ended with exit code: 0
 */
