/*
Title: Loan Payment Calculator
Author: Kevin Keller
Date Created: 10/09/2013
Last Modified: 12/04/2013
Edit Comments:
    0) Reactored the init_loan function to include more user input validations.
    1) Added rerun_program function allowing the user to restart calculator with new inputs.
*/

// This program creates uses a structure for loan, initialize it from the keyboard, then displays the struct
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct Loan  // Loan is called structure tag
{
  int ID;  // assume an unique integer between 1111-9999
  float amount; // $ amount of the loan
  float rate; // annual interest rate
  int term;  // number of months, length of the loan
};

// FUNCTION DECARATIONS
int rerun_program ();
// function to check if the user wants to run the program again.
// validates cin using type comparison of converted string input against int
// loops until valid input is assured correct and break is hit to get to return line
Loan init_loan (Loan l);
// This function serves to initialize an instance of the class Loan using user input.
float payment (Loan l);
// Calculates the payment for a loan structure passed into it.


// START THE MAIN PROGRAM
int main( )
{
  Loan loan1; // creates an empty Loan struct object assigned to loan1
  Loan loan2; // creates an empty Loan struct object assigned to loan2
  float payment1; // monthly payment var for loan1
  float payment2; // monthly payment var for loan1
  int choice;

  do {
    cout << "\nPlease provide the following information on your first loan\n";
    loan1 = init_loan(loan1); // populate the first loan with user input
    cout << endl;
    cout << "Please provide the following information on your second loan\n";
    loan2 = init_loan(loan2); // populate the second loan with user input

    // Calculate the monthly payments for each loan
    payment1 = payment(loan1);
    payment2 = payment(loan2);

    // Output results to the user
    cout << fixed << setprecision(2);
    cout << "\nHere are your results:\n";
    cout << "The monthly payment for loan " << loan1.ID << " is: $" << payment1 << endl;
    cout << "The monthly payment for loan " << loan2.ID << " is: $" << payment2 << endl;
    cout << "The total monthly payment for both loans is: $"
         << (payment1 + payment2) << endl;

    choice = rerun_program(); // check if user wants to re-run the program
  } while (choice == 1);

  return 0;
}


// FUNCTION DEFINITIONS
int rerun_program () {
  float choice;
  string input = "";

  cout << "\nDo you want to run the program again?\n";

  while (true) {
    cout << "Enter 1 to re-run the program or 0 to exit: "; // output options for input
    getline(cin, input); // grab user input as a string
    stringstream convert(input); // convert the string to an int with sstream
    if ( (convert >> choice) && ((choice == 1) || (choice == 0)) ) {
      break;
    }
    else {
      cout << "You did not enter a valid choice.\n";
      cin.clear();
    }
  }
  return choice;
}

float payment(Loan l) {
  l.rate = l.rate/1200;  // To convert % yearly rate to monthly fraction
  return l.amount*l.rate*( pow( (l.rate+1), l.term)/ (pow( (l.rate+1), l.term) - 1) );
}

Loan init_loan (Loan l) {
  string input = ""; // Initialize the input string var needed to check the user input

  // getting the loan.ID
  while (true) {
    cout << "Enter the ID of this loan: ";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> l.ID && l.ID >= 1111 && l.ID <= 9999) { // check that input is an int falls within valid range
      break; // exit loop
    }
    else {
      cout << "That is not a valid ID.\n";
      cin.clear();
    }
  }
  // getting the loan.amount
  while (true) {
    cout << "Enter the amount of this loan: $";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> l.amount && l.amount > 0) { // check that input is a float and greater than 0
      break; // exit loop
    }
    else {
      cout << "That is not a valid amount.\n";
      cin.clear();
    }
  }
  // getting the loan.rate
  while (true) {
    cout << "Enter the annual interest rate of this loan (as a %): ";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> l.rate && l.rate >= 0 && l.rate <= 100) { // check that input is a float and falls within valid range
      break; // exit loop
    }
    else {
      cout << "That is not a valid rate.\n";
      cin.clear();
    }
  }
  // getting the loan.term
  while (true) {
    cout << "Enter the term (number of months, length of the loan): ";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> l.term && l.term >= 1) { // check that input is an int and falls within valid range
      break; // exit loop
    }
    else {
      cout << "That is not a valid term range.\n";
      cin.clear();
    }
  }
  return l; // each loan input passed. return the validated loan structure.
}

/*
TEST CASES

INIT_LOAN FUNCTION (ID PROMPT)
1)  input nothing (nil). => fails. loops and asks for new input.
2)  input 0 (int). => fails. loops and asks for new input.
3)  input 1110 (int). => fails. loops and asks for new input.
4)  input 1111 (int). => passes.
5)  input 1111.5 (float). => passes. truncates decimal places. (need a fix to this!)
6)  input 10000 (int). => fails. loops and asks for new input.
7)  input 'test' (string). => fails. loops and asks for new input.
8)  input true (bool). => fails. treated as a string. loops and asks for new input.
9)  input false (bool). => fails. treated as a string. loops and asks for new input.

*/
