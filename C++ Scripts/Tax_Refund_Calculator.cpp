/*
Title: Tax Refund Calculator
Author: Kevin Keller
Creation Date: Oct 03, 2013
Last Modified: Oct 12, 2013
Edit Comments:
    0) Refactored federal and state calculator functions into one 'tax_calcultor' function.
    1) Refactored all input functions to use validation of type and removed recurssive calls.
    2) Added test cases for functions to test user input possibilities and all edge cases.
*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

// FUNCTION DECLARATONS
int rerun_program ();
// function to check if the user wants to run the tax program again.
// validates cin using type comparison of converted string input against int
// loops until valid input is assured correct and break is hit to get to return line
int get_income_earned ();
// function to get the income from the user
// validates cin using type comparison of converted string input against int
// loops until valid input is assured correct and break is hit to get to return line
int get_dependents();
// function to get the number of dependents from the user
// validates cin using type comparison of converted string input against int
// loops until valid input is assured correct and break is hit to get to return line
int tax_calculator (int income, int dependents, bool fed_v_state);
// function to calculate either state or federal taxes due based on income and dependents (both ints).
// takes a third argument, fed_v_state (a bool value), which triggers the appropriate selection of tax rates
// for each of the tax brakets.
string due_vs_refund (int tax_statement);
// determines the correct wording for the results screen based on amount owed or due in taxes
// input is a tax statement amount, int, with the string 'owed' or 'refund' as the output


// START THE MAIN PROGRAM
int main() {
  // setup choice var
  int choice;

  // print out instructions to the user when program starts for the first time
  cout << "\n~~~~~~~~~~  INSTRUCTIONS  ~~~~~~~~~~\n"
       << "1.) CALCULATING AND ENTERING YOUR INCOME\n"
       << "Your income, for this tax year, is the TOTAL GROSS income you earned.\n"
       << "When caclulating your income it should be rounded to the nearest whole dollar.\n"
       << "This software will disregard all cents entered in, please round up or down before entering.\n"
       << "When entering your total income, do not use any commas or periods.\n"
       << "ex. Good:$15000   Bad:$15,000   Bad:$15000.80 (Round this up to $15001 first)\n"
       << endl
       << "2.) CALCULATING AND ENTERING DEPENDENTS\n"
       << "When figuring our the number of dependents you have, be sure to count yourself.\n"
       << "When entering your dependents, do not use any commas or decimals (whole numbers ONLY).\n"
       << "This software will disregard all decimal places entered in (no partial people).\n";

  // allow program to execute once before checking for user choice
  do {
    int income, state_tax, federal_tax;
    int dependents;

    // get the user's income earned this year
    income = get_income_earned();
    // get the number of dependents a user has (User counts as a dependent!!).
    dependents = get_dependents();

    //calculate the taxes due or paid to for the state and federal levels
    state_tax = tax_calculator (income, dependents, false);
    federal_tax = tax_calculator (income, dependents, true);

    //Print out the results of the tax calculator program
    cout << "\nHere are your results for this year's tax season:\n"
         << "Net Income: $" << income << endl
         << "State Taxes " << due_vs_refund (state_tax)
         << ": $" << abs(state_tax) << endl
         << "Federal Taxes " << due_vs_refund (federal_tax)
         << ": $" << abs(federal_tax) << endl
         << "------------------------------------------------------\n"
         << "Thank you for using our tax preparation software!\n";

    // check if user wants to run the program again
    choice = rerun_program();
  } while (choice == 1);
  return 0;
}

// FUNCTION DEFINITIONS
int rerun_program () {
  float choice;
  string input = "";

  cout << "\nDo you want to run the tax program again?\n";

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

int get_income_earned () {
  int income;
  string input = "";

  while (true) {
    cout << "\nEnter your total earned income: $";
    getline(cin, input); // grab user input as a string
    stringstream convert(input); // convert the string to an int with sstream
    if ( (convert >> income) && (income >= 0) ) {
      // check if valid integer type was entered and if int is greater than or equal to zero else loop
      break; // exit while loop
    }
    else {
      cout << "\nPlease enter a valid integer amount."; // throw error message to user
      cin.clear(); // clear cin to avoid the occasion error
    }
  }
  return income; // return valid income to main
}

int get_dependents() {
  int dependents_count;
  string input = "";

  while (true) {
    cout << "\nEnter total dependents: ";
    getline(cin, input); // grab user input as a string
    stringstream convert(input); // convert the string to an int with sstream
    if ( (convert >> dependents_count) && (dependents_count >= 1) ) {
      // check if valid integer type was entered and if int is greater than or equal to one else loop
      break; // exit while loop
    }
    else {
      cout << "You cannot have less than one dependent(yourself).\n"; // throw error message to user
      cin.clear(); // clear cin to avoid the occasion error
    }
  }
  return dependents_count;
}

int tax_calculator (int income, int dependents, bool fed_v_state) {
  int tax_due; // used to calculate the tax due (or owed to)
  float tax_bracket1_with_dependents;
  float tax_bracket1_no_dependents;
  float tax_bracket2;
  float tax_bracket3;

  // check if third var passed in is true, if so return federal tax %s, else return state tax %s
  if (fed_v_state == true) // setup federal tax %'s
  {
    tax_bracket1_with_dependents = 0.10; // recieve a refund for 10% of your income
    tax_bracket1_no_dependents = -0.04; // taxed at 4%.
    tax_bracket2 = -0.07; //taxed at 10%
    tax_bracket3 = -0.10; //taxed at 7%
  }
  else // setup state tax %'s
  {
    tax_bracket1_with_dependents = 0.05; // recieve a refund for 5% of your income
    tax_bracket1_no_dependents = 0; // taxed at 0%.
    tax_bracket2 = -0.05; //taxed at 5%
    tax_bracket3 = -0.10; //taxed at 10%
  }

  // if income is less than $15000 (tax bracket #1)
  if (income <= 15000)
  {
    // check if have 2 or more dependents
    if (dependents >= 2)
    {
      tax_due = (income * tax_bracket1_with_dependents);
    }
    else
    {
      tax_due = (income * tax_bracket1_no_dependents); // pay no taxes.
    }
  }
  // if income is less than or equal to $25000 but greater than $15000 (tax bracket #2)
  else if (income > 15000 && income <= 25000)
  {
    tax_due = (income * tax_bracket2);
  }
  // if income is greater than $25000 (tax bracket #3)
  else
  {
    tax_due = (income * tax_bracket3);
  }
  return tax_due; // return the tax_due
}

string due_vs_refund (int tax_statement) {
  if (tax_statement > 0)
  {
    return "refund of";
  }
  else
  {
    return "owed";
  }
}

/* TEST CASES

INPUT_FUNCTION
1)  input nothing (nil). => fails. loop once and ask for new input.
2)  input 10.0 (float). => passes. truncate all cents off. (need a fix for this!)
3)  input "money" (string). => fails. loop once and ask for new input.
4)  input 1 (positive integer). => passes.
5)  input 0 (integer). => passes.
6)  input 0.0 (float). => passes. truncate all cents off. (need a fix for this!)
7)  input -1 (negative integer). => fails. loop once and ask for new input.
8)  input -1.0 (negative float). => fails. loop once and ask for new input.
9)  input 1000000000 (large positive integer). => passes.
10) input 0.0000000001 (very small positive float). => passes. treat as a 0 integer.
11) input 0.01 (small positive float). => passes. treat as a 0 integer.
12) input 0.99 (small positive float). => passes. treat as a 0 integer.
13) input true (bool). => fails. loop once and ask for new input.
14) input false (bool). => fails. loop once and ask for new input.

GET_DEPENDENTS FUNCTION
1)  input nothing (nil). => fails. loop once and ask for new input.
2)  input 10.0 (float). => passes. truncate all decimals off. (need a fix for this!)
3)  input "money" (string). => fails. loop once and ask for new input.
4)  input 1 (minimum positive integer). => passes.
5)  input 0 (integer). => fails. loop once and ask for new input.
6)  input 0.0 (float). => fails. loop once and ask for new input.
7)  input -1 (negative integer). => fails. loop once and ask for new input.
8)  input -1.0 (negative float). => fails. loop once and ask for new input.
9)  input 1000000000 (large positive integer). => passes.
10) input 0.0000000001 (very small positive float). => fails. loop once and ask for new input.
11) input 0.01 (small positive float). => fails. loop once and ask for new input.
12) input 0.99 (small positive float). => fails. loop once and ask for new input.
13) input true (bool). => fails. loop once and ask for new input.
14) input false (bool). => fails. loop once and ask for new input.

REREUN_PROGRAM FUNCTION
1)  input nothing (nil). => fails. loop once and ask for new input.
2)  input 10.0 (float). => fails. loop once and ask for new input.
3)  input "money" (string). => fails. loop once and ask for new input.
4)  input 1 (minimum positive integer). => passes. re-starts the program.
5)  input 0 (integer). => passes. ends the program.
6)  input 0.0 (float). => fails. loop once and ask for new input.
7)  input -1 (negative integer). => fails. loop once and ask for new input.
8)  input -1.0 (negative float). => fails. loop once and ask for new input.
9)  input 1000000000 (large positive integer). => fails. loop once and ask for new input.
10) input 0.0000000001 (very small positive float). => fails. loop once and ask for new input.
11) input 0.01 (small positive float). => fails. loop once and ask for new input.
12) input 0.99 (small positive float). => fails. loop once and ask for new input.
13) input true (bool). => fails. loop once and ask for new input.
14) input false (bool). => fails. loop once and ask for new input.

*/
