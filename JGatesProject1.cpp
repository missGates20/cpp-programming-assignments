
/*********************************************************
* This template is made for XCode compiler
* file name: JGatesProject1.cpp
* programmer name: ---------
* date created: 04/21/2024
* date of last revision: 05/05/2024
* details of the revision: finishing the program
* short description: Calculating multiple grade averages using functions
**********************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void description();
double getExams();
double getStudents();
double average(double examCount, int count);
void displayGrade(double avg);

int main()
{
//Program description
    //function call for description:
    description();
    
//Variable declaration/initalization
    int count=1;
    double examCount, studentCount;
    //variable initialization using functions
    examCount = getExams();
    studentCount = getStudents();
    
    //run functions according to the number of students
    while (count <= studentCount){
        double avg = average(examCount, count);
        displayGrade(avg);
        count++;
    }
  
    
return 0;
}

//function definitions

//function 1:
void description(){
    cout << "This program will calculate and display the average grade\nfor each student in the class.\n\n";
}

//function 2:
double getExams(){
    //variable declaration
    double examNum;
    //get number of exams (w/ data validation)
    do{
        cout << "Enter the number of exams in the course>> ";
        cin >> examNum;
    }while(examNum <= 0);
    
    //return value
    return examNum;
}

//function 3:
double getStudents(){
    //variable declaration
        double studentNum;
    //get number of students (w/ data validation)
    do{
        cout << "Enter the number of students in the class>> ";
        cin >> studentNum;
    }while(studentNum <= 0);
    
    //return value
    return studentNum;
}

//function 4:
double average(double examCount, int count){ //this function will run once for each student
    //variable declaration/initialization
    double grade, test = 1, total = 0;
    //get grades per exam
        while (test <= examCount)
        {
                cout << "\nEnter the exam " << test << " grade for student " << count << ">> ";
                cin >> grade;
            if((grade >= 0)&&(grade <=100)){
                total += grade;
                ++test;
                }
            else{
                test--;
                cout << "\nEnter a valid exam grade.>> ";
                test++;
            }
            
        }
   //find average
    double Average = (total/examCount);
    
    //return value
    return Average;
}

//function 5:
void displayGrade(double avg){
    //find and display average grade
    cout << setprecision(2) <<fixed; //for number formatting
    cout << "Average grade: " << avg << endl;
    if (avg >= 90)
        cout << "Letter Grade: A"<<endl;
    else if (avg >= 80)
        cout << "Letter Grade: B"<<endl;
    else if (avg >= 70)
        cout <<  "Letter Grade: C"<<endl;
    else if (avg >= 60)
        cout << "Letter Grade: D"<<endl;
    else
        cout <<  "Letter Grade: F"<<endl;
    
}

/*Test run 1:
 This program will calculate and display the average grade
 for each student in the class.

 Enter the number of exams in the course>> 3
 Enter the number of students in the class>> 3

 Enter the exam 1 grade for student 1>> 80

 Enter the exam 2 grade for student 1>> 80

 Enter the exam 3 grade for student 1>> 80
 Average grade: 80.00
 Letter Grade: B

 Enter the exam 1 grade for student 2>> 90

 Enter the exam 2 grade for student 2>> 90

 Enter the exam 3 grade for student 2>> 90
 Average grade: 90.00
 Letter Grade: A

 Enter the exam 1 grade for student 3>> 86

 Enter the exam 2 grade for student 3>> 86

 Enter the exam 3 grade for student 3>> 86
 Average grade: 86.00
 Letter Grade: B
 Program ended with exit code: 0
 
 ----------------------
 
 Test 2:
 This program will calculate and display the average grade
 for each student in the class.

 Enter the number of exams in the course>> -80
 Enter the number of exams in the course>> -5
 Enter the number of exams in the course>> 2
 Enter the number of students in the class>> 0
 Enter the number of students in the class>> -1
 Enter the number of students in the class>> -8
 Enter the number of students in the class>> 4

 Enter the exam 1 grade for student 1>> 90

 Enter the exam 2 grade for student 1>> 100
 Average grade: 95
 Letter Grade: A

 Enter the exam 1 grade for student 2>> 90

 Enter the exam 2 grade for student 2>> 90
 Average grade: 90
 Letter Grade: A

 Enter the exam 1 grade for student 3>> 80

 Enter the exam 2 grade for student 3>> 90
 Average grade: 85
 Letter Grade: B

 Enter the exam 1 grade for student 4>> 76

 Enter the exam 2 grade for student 4>> 86
 Average grade: 81
 Letter Grade: B
 Program ended with exit code: 0
 
 ----------------------
 
 Test 3:
 This program will calculate and display the average grade
 for each student in the class.

 Enter the number of exams in the course>> 4
 Enter the number of students in the class>> 2

 Enter the exam 1 grade for student 1>> 78

 Enter the exam 2 grade for student 1>> 90

 Enter the exam 3 grade for student 1>> 78

 Enter the exam 4 grade for student 1>> 100
 Average grade: 86.50
 Letter Grade: B

 Enter the exam 1.00 grade for student 2>> 100

 Enter the exam 2.00 grade for student 2>> 70

 Enter the exam 3.00 grade for student 2>> 80

 Enter the exam 4.00 grade for student 2>> 94
 Average grade: 86.00
 Letter Grade: B
 Program ended with exit code: 0
 
 ----------------------
 
 Test 4:
 This program will calculate and display the average grade
 for each student in the class.

 Enter the number of exams in the course>> 3
 Enter the number of students in the class>> 1

 Enter the exam 1 grade for student 1>> 75

 Enter the exam 2 grade for student 1>> 70

 Enter the exam 3 grade for student 1>> 87
 Average grade: 77.33
 Letter Grade: C
 Program ended with exit code: 0
 
 ----------------------
 
 Test 5:
 This program will calculate and display the average grade
 for each student in the class.

 Enter the number of exams in the course>> 2
 Enter the number of students in the class>> 10

 Enter the exam 1 grade for student 1>> 100

 Enter the exam 2 grade for student 1>> 90
 Average grade: 95.00
 Letter Grade: A

 Enter the exam 1.00 grade for student 2>> 80

 Enter the exam 2.00 grade for student 2>> 90
 Average grade: 85.00
 Letter Grade: B

 Enter the exam 1.00 grade for student 3>> 100

 Enter the exam 2.00 grade for student 3>> 70
 Average grade: 85.00
 Letter Grade: B

 Enter the exam 1.00 grade for student 4>> 50

 Enter the exam 2.00 grade for student 4>> 55
 Average grade: 52.50
 Letter Grade: F

 Enter the exam 1.00 grade for student 5>> 78

 Enter the exam 2.00 grade for student 5>> 76
 Average grade: 77.00
 Letter Grade: C

 Enter the exam 1.00 grade for student 6>> 60

 Enter the exam 2.00 grade for student 6>> 71
 Average grade: 65.50
 Letter Grade: D

 Enter the exam 1.00 grade for student 7>> 40

 Enter the exam 2.00 grade for student 7>> 0
 Average grade: 20.00
 Letter Grade: F

 Enter the exam 1.00 grade for student 8>> 800

 Enter a valid exam grade.>>
 Enter the exam 1.00 grade for student 8>> 80

 Enter the exam 2.00 grade for student 8>> 80
 Average grade: 80.00
 Letter Grade: B

 Enter the exam 1.00 grade for student 9>> 100

 Enter the exam 2.00 grade for student 9>> 101

 Enter a valid exam grade.>>
 Enter the exam 2.00 grade for student 9>> 11
 Average grade: 55.50
 Letter Grade: F

 Enter the exam 1.00 grade for student 10>> 70

 Enter the exam 2.00 grade for student 10>> 100
 Average grade: 85.00
 Letter Grade: B
 Program ended with exit code: 0
*/
