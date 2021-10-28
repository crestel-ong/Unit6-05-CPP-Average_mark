// Copyright (c) 2021 Crestel Ong All rights reserved
//
// Created by: Crestel Ong
// Created on: October 2021
// this program calculates the average mark
// this program uses lists

#include <iostream>
#include <list>
#include <cmath>


float CalculateAverage(std::list<int> listOfMarks) {
    // this function calculates the average

    // declaring
    int total = 0;
    int numItems = 0;
    float average = 0;

    // process
    for (float singleMark : listOfMarks) {
        // get sum of contents of the list
        total = total + singleMark;
        // get the number of elements in list
        numItems = numItems + 1;
    }
    average = total / numItems;
    average = static_cast<int>(average);
    average = round(average);

    return average;
}

int main() {
    // declaring
    std::list<int> markList;
    int inputtedMark;
    std::string inputtedMarkAsString;
    float retunedAverage;

    // tell the user what this program does and what to do
    std::cout << "This program calculates the average of inputted marks."
    << std::endl;
    std::cout << "Enter one mark at a time, and enter -1 to stop inputting."
    << std::endl;
    std::cout << "The marks must be from 0 to 100."
    << std::endl;
    std::cout << " " << std::endl;

    // input
    while (true) {
        std::cout << "What is the mark? (as %): ";
        std::cin >> inputtedMarkAsString;
        try {
            // convert from string to integer
            inputtedMark = std::stoi(inputtedMarkAsString);
            if (inputtedMark >= 1 && inputtedMark <= 100) {
                markList.push_back(inputtedMark);
            } else if (inputtedMark == -1) {
                break;
            } else {
                std::cout << "Invalid input, that won't be included"
                << " in caculating the average." << std::endl;
                break;
            }

        // catches any issue
        // https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
        } catch (...) {
            std::cout << "Invalid input, that won't be included"
            << " in caculating the average." << std::endl;
            break;
        }
    }

    // call function
    retunedAverage = CalculateAverage(markList);

    std::cout << "\nThe average is " << retunedAverage << "%" << std::endl;

    std::cout << "\nDone." << std::endl;
}
