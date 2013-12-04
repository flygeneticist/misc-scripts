/*
Title: Clothing Sizes Predictor
Author: Kevin Keller
Date Created: 10/09/2013
Last Modified: 12/05/2013
Edit Comments:
    0) Refactored rerun_program function to remove recursive call and added better input validation.
    1) Added a Person structure to hold initial vars. Modified the dependent calculation functions to take Person struct.
    2) Moved the user inputs from main to a seperate function with vailidation checks added.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

// Setup a Person structure to hold common vars
struct Person {
  float height;
  float weight;
  float age;
};

// FUNCTION DECLARATIONS
int rerun_program ();
// function to check if the user wants to run the program again.
// validates cin using type comparison of converted string input against int
// loops until valid input is assured correct and break is hit to get to return line
Person init_person (Person p);
// function takes in an empty Person structure.
// gets several user inputs, checks them for validitity, and outputs a completed Person structure.
int calc_waist_size (Person p);
// takes in a user defined Person structure p. Returns the calculated weight size.
int calc_jacket_size (Person p);
// takes in a user defined Person structure p. Returns the calculated jacket size.
int calc_hat_size (Person p);
// takes in a user defined Person structure p. Returns the calculated hat size.


// START THE MAIN PRORGAM
int main() {
  // setup vars needed for main
  int choice; // var to control program loop/restart
  Person user_person; // empty person structure
  int jacket_size, waist_size, hat_size, predict_jacket_size, predict_waist_size; // vars to hold output calculations

  do {
    user_person = init_person (user_person); // setup Person structure from user input.

    // calculate the user's clothing sizing based on their given measurements
    jacket_size = calc_jacket_size(user_person);
    waist_size = calc_waist_size(user_person);
    hat_size = calc_hat_size(user_person);

    // now calculate predictions of what the user_person measurements will be after 10 years
    user_person.age += 10; // add 10 years to the user_person structure age
    predict_jacket_size = calc_jacket_size(user_person); // new jacket calc based on modified age
    predict_waist_size = calc_waist_size(user_person); // new waist calc based on modified age

    // output results of the calculations to the user
    cout << "\nHere are your predicted clothing sizes:" << endl
         << "Your jacket size is: " << jacket_size << endl
         << "Your waist size is: " << waist_size << endl
         << "Your hat size is: " << hat_size << endl
         << endl
         << "~~~~~~~~~~ Prediction time! ~~~~~~~~~~" << endl
         << "After 10 years, your sizes will be:" << endl
         << "Your new jacket size is: " << predict_jacket_size << endl
         << "Your new waist size is: " << predict_waist_size << endl;

    // check if the user wants to re-run the program
    choice = rerun_program();
  } while (choice == 1);

  return 0; // close main with 0
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

Person init_person (Person p) {
  // setup vars needed for IO and validation checks
  string input = ""; // Initialize the input string var needed to check the user input

  // getting the p.age
  while (true) {
    cout << "\nEnter your age (in years): ";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> p.age && p.age >= 1) { // check that input maps to an int falls within valid range
      break; // exit loop
    }
    else {
      cout << "That is not a valid age.\n";
      cin.clear();
    }
  }
  // getting the p.weight
    while (true) {
    cout << "Enter your weight (in pounds): ";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> p.weight && p.weight >= 1) { // check that input maps to a float and falls within valid range
      break; // exit loop
    }
    else {
      cout << "That is not a valid weight.\n";
      cin.clear();
    }
  }
  // getting the p.height
  while (true) {
    cout << "Enter your height (in inches): ";
    getline(cin,input);
    stringstream convert(input);
    if (convert >> p.height && p.height >= 1) { // check that input maps to a float and falls within valid range
      break; // exit loop
    }
    else {
      cout << "That is not a valid height.\n";
      cin.clear();
    }
  }
  return p; // each measurement input passed. return the validated Person structure.
}

int calc_waist_size (Person p) {
  int age_level;
  float boost_calc=0;
  if (p.age > 27) // calculate the extra boost to measurements for user's age
  {
    age_level = floor((p.age-28)/2);
    boost_calc = (0.10*age_level); // apply boost preportionate to age level
  }
  return ((p.weight / 7.5) + boost_calc);
}

int calc_jacket_size (Person p) {
  int age_level;
  float boost_calc=0;
  if (p.age > 29) // calculate the extra boost to measurements for user's age
  {
    age_level = floor((p.age-30)/10);
    boost_calc = (0.08*age_level); // apply boost preportionate to age level
  }
  return ((p.height * p.weight / 228) + boost_calc);
}

int calc_hat_size (Person p) {
  return (p.weight / p.height * 2.9);
}
