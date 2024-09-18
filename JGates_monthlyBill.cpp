//  
//  JGates_monthlyBill.cpp
//  HW
//  Calculate best phone plan
//  8/28/24.
//

#include <iostream>
#include <iomanip>
using namespace std;
//function prototypes
float getDataUsage();
float getTaxRate();
void calcBasic(float, float, float&);
void calcStandard(float, float, float&);
void calcPremium(float, float&);
void customerResponse (char&);

int main() {
    //program description
    cout << "This program will help you find the best phone plan\nfor you, based on monthly data usage and tax rate.";
    //variable declaration
    float dataUsage, taxRate, basic, standard, premium;
    char response;
    
    //function calling and variable intialization
    dataUsage = getDataUsage();
    taxRate = getTaxRate();
    calcBasic(dataUsage, taxRate, basic);
    calcStandard(dataUsage, taxRate, standard);
    calcPremium(taxRate, premium);
    
    //display formatting
    cout << fixed << setprecision(2)<<endl;
    
    //display results
    if((basic <standard) &&(basic <premium))
        cout << "The best plan for you would be the basic plan!\nMonthly Fee: $" <<basic<<endl;
    else if((standard<basic)&&(standard < premium))
        cout << "The best plan for you would be the standard plan!\nMonthly Fee: $" <<standard<<endl;
    else
        cout << "The best plan for you would be the premium plan!\nMonthly Fee: $" <<premium<<endl;
    
    //function call and variable intialization
    customerResponse(response);
   
    //display results based on user input (then end program)
    if(response == 'Y'){
        cout << "Basic Monthly Plan: $" << basic <<endl
             << "Standard Monthly Plan: $" << standard <<endl
             << "Premium Monthly Plan: $" << premium <<endl
        << "\nThank you for using this service!"<<endl;
        return 0;
    }
    else if (response == 'N'){
        cout<<"Thank you for using this service!"<<endl;
        return 0;
    }
    //end program
    return 0;
}

//function definitions
float getDataUsage(){
/*
 Purpose: get the possible monthly data usage
 Input: possible data usage (inside of function)
 Output: the entered possible data usage
 Process: ask user for possible monthly data usage
 */
    //variable declaration
    float dataUsage; /*this variable stays inside/doesn't duplicate.*/
    
    //variable intialization (with data validation)
    do {
        cout << "\nWhat is your possible monthly data usage (in GIG)?"<<endl;
        cin >> dataUsage;
    } while (dataUsage <= 0);
    
    //return value
    return dataUsage;
}
float getTaxRate(){
    /*
     Purpose: get the tax rate
     Input: tax rate (inside of function)
     Output: tax rate in decimal form
     Process: ask user for tax rate
     */
    //variable declaration
    float taxRate; /*this variable stays inside/doesn't duplicate.*/
    
    //variable intialization (with data validation)
    do {
        cout << "What is the tax rate percent(exclude the '%' sign)?"<<endl;
        cin >> taxRate;
    } while (taxRate < 0);
    taxRate = taxRate/100;
    //return value
    return taxRate;
}
void calcBasic(float dataUsage, float taxRate, float &basic){
    /*
     Purpose: calculate the basic plan monthly bill based on user input
     Input: reported data usage, tax rate, and basic bill price (call by ref)
     Output: none
     Process: if reported data usage is 4 GIG or less, do base monthly price + taxes. if higher, do the same equation from before, then add cost for additional data (additional data * 10).
     */
    if (dataUsage <=4){
        basic = 34.99+(34.99*taxRate);
    }
    else{
        dataUsage=dataUsage-4;
        basic = 34.99+(dataUsage*10);
        basic = basic+(basic*taxRate);
    }
}
void calcStandard(float dataUsage, float taxRate, float &standard){
    /*
     Purpose: calculate the standard plan monthly bill based on user input
     Input: reported data usage, tax rate, and standard bill price (call by ref)
     Output: none
     Process: if reported data usage is 8 GIG or less, do base monthly price + taxes. if higher, do the same equation from before, then add cost for additional data (additional data * 5).
     */
    //no need to do variable declaration, since variable already exists and it's doing call by ref.
    //variable initialization (with data validation)
    if (dataUsage <=8){
        standard = 55.99+(55.99*taxRate);
    }
    else{
        dataUsage=dataUsage-8;
        standard = 55.99+(dataUsage*5);
        standard = standard+(standard*taxRate);
    }
}
void calcPremium(float taxRate, float &premium){
    /*
     Purpose: calculate the premium plan monthly bill based on user input
     Input: tax rate, and premium bill price (call by ref)
     Output: none
     Process: take the base monthly price and add the taxes (using tax rate entered by user).
     */
    //no need to do variable declaration, since variable already exists and it's doing call by ref.
    //variable initialization (with data validation)
    premium = 69.99+(69.99*taxRate);
}
void customerResponse(char& response){
    /*
     Purpose: record the customer's response to seeing additonal plans monthly bill
     Input: the response (call by ref)
     Output: none
     Process: Ask user if they want to see the bill total of other plans. Keep asking until a proper response is entered (Y, y, n, or N).
     */
    //variable initialization (w/ data validation)
    do{
        cout << "Would you like to see the monthly fee for the other phone plans? (Y/N): ";
        cin >> response;}while((response != 'y')&&(response != 'Y')&&(response != 'n')&&(response != 'N'));
    response = toupper(response);
}

/*
 Test run 1:
 This program will help you find the best phone plan
 for you, based on monthly data usage and tax rate.
 What is your possible monthly data usage (in GIG)?
 4

 What is the tax rate percent(exclude the '%' sign)?
 2


 The best plan for you would be the basic plan!
 Monthly Fee: $35.69
 Would you like to see the monthly fee for the other phone plans? (Y/N): Y
 Basic Monthly Plan: $35.69
 Standard Monthly Plan: $57.11
 Premium Monthly Plan: $71.39

 Thank you for using this service!
 Program ended with exit code: 0

 
 Test run 2:
 This program will help you find the best phone plan
 for you, based on monthly data usage and tax rate.
 What is your possible monthly data usage (in GIG)?
 8

 What is the tax rate percent(exclude the '%' sign)?
 1


 The best plan for you would be the standard plan!
 Monthly Fee: $56.55
 Would you like to see the monthly fee for the other phone plans? (Y/N): Y
 Basic Monthly Plan: $75.74
 Standard Monthly Plan: $56.55
 Premium Monthly Plan: $70.69

 Thank you for using this service!
 Program ended with exit code: 0
 
 
 Test run 3:
 This program will help you find the best phone plan
 for you, based on monthly data usage and tax rate.
 What is your possible monthly data usage (in GIG)?
 12

 What is the tax rate percent(exclude the '%' sign)?
 3


 The best plan for you would be the premium plan!
 Monthly Fee: $72.09
 Would you like to see the monthly fee for the other phone plans? (Y/N): Y
 Basic Monthly Plan: $118.44
 Standard Monthly Plan: $78.27
 Premium Monthly Plan: $72.09

 Thank you for using this service!
 Program ended with exit code: 0
 
 
 Test run 4:
 This program will help you find the best phone plan
 for you, based on monthly data usage and tax rate.
 What is your possible monthly data usage (in GIG)?
 11

 What is the tax rate percent(exclude the '%' sign)?
 3


 The best plan for you would be the premium plan!
 Monthly Fee: $72.09
 Would you like to see the monthly fee for the other phone plans? (Y/N): n
 Thank you for using this service!
 Program ended with exit code: 0
 
 
 Test run 5:
 This program will help you find the best phone plan
 for you, based on monthly data usage and tax rate.
 What is your possible monthly data usage (in GIG)?
 0


 What is your possible monthly data usage (in GIG)?
 0


 What is your possible monthly data usage (in GIG)?
 .5

 What is the tax rate percent(exclude the '%' sign)?
 0


 The best plan for you would be the basic plan!
 Monthly Fee: $34.99
 Would you like to see the monthly fee for the other phone plans? (Y/N): N
 Thank you for using this service!
 Program ended with exit code: 0
 */
