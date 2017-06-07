//
//  main.cpp
//  Algorithms
//
//  Created by Pranaya Adhikari on 6/5/17.
//  Copyright © 2017 Pranaya Adhikari. All rights reserved.
//

#include <iostream>
#include <string>
#include <array>

using namespace std;

string numberAsArrayToString(int* , int );

void shiftLeft(int* inputArr, int* outputArr , int numPos ){
    int size = sizeof(inputArr) / sizeof(inputArr[0]);
    outputArr [(size + numPos)] = {};
    for(int i=0; i < size; i++){
        outputArr[i] = inputArr[i];
    }
    for(int j=size; j < (size+numPos); j++){
        outputArr[j] = 0;
    }
}

void add(int* inputArr1 , int* inputArr2 , int* outputArr) {
    int size = sizeof(inputArr1) / sizeof(inputArr1[0]);
    int sum, carry = 0;
    for( int i=size-1; i >= 0; --i){
        sum = carry;
        if(i == 0){
            sum += (inputArr1[i] + inputArr2[i]);
            outputArr[i] = sum;
        }
        
        sum += (inputArr1[i] + inputArr2[i])% 10;
        outputArr[i] = sum;
        carry = (inputArr1[i] + inputArr2[i])/ 10;
    }
    int length = sizeof(outputArr) / sizeof(outputArr[0]);
    cout << numberAsArrayToString(outputArr, length) << endl;
}

//int subtract(int inputArr1 [], int inputArr2, int outputArr) {
//    
//
//
//}
//
//
//int multiply(int inputArr1 [], int inputArr2, int outputArr) {
//    
//
//
//}

    
int multiplyLargeNumbers(int* first_number,
                         int first_number_length,
                         int* second_number,
                         int second_number_length,
                         int* result) {
    int buffer_array [first_number_length] [first_number_length];
    
    for(int i = second_number_length - 1; i >= 0 ; i--){
        int product, carryOver = 0;
        for(int j = first_number_length - 1; j >=0; j-- ){
            product = carryOver;
            if(j == 0){
                product += (first_number[j] * second_number[i]);
                buffer_array[i][j] = product;
            }
            product += (first_number[j] * second_number[i])%10;
            buffer_array[i][j] = product;
            carryOver = (first_number[j] * second_number[i])/10;
        }
    
    // Now write your code here to multiply the two numbers
    // and write the result to result, and return its number
    // of digits.
    return 0;
}

// This function parses a number as a string, saves each digit
// in the num_array that is passed in, low-digits first, and
// returns the number of digits in that number.
// If we can't parse the number, returns -1.
// Example: If num_as_string = "1234",
//          then num_array[] = {4, 3, 2, 1} and
//          the return value is 4.
int readNumberAsArrayFromString(const string& num_as_string,
                                int* num_array) {
    for (int i = 0; i < num_as_string.length(); ++i) {
        if (num_as_string[i] >= '0' &&
            num_as_string[i] <= '9') {
            num_array[i] = static_cast<int>(num_as_string[i] - '0');
        } else {
            return -1;
        }
    }
    return num_as_string.length();
}

// Takes a number represented as an array with its digits,
// low to heigh, as well as its length (i.e. number of digits)
// and return a string representation of that number.
string numberAsArrayToString(int* num_array, int length) {
    if (length <= 0 ) {
        return "NaN";
    }
    string num_string;
    for (int i = 0; i < length; ++i) {
        num_string += static_cast<char>(num_array[i] + '0');
    }
    return num_string;
}

int main() {
    int first_number[10000];
    int second_number[10000];
    int first_number_length, second_number_length;
    cout << "Let's multiply two numbers." << endl;
    {
        cout << "Please enter the first number: ";
        string first_number_as_string;
        cin >> first_number_as_string;
        first_number_length = readNumberAsArrayFromString(
                                                          first_number_as_string,
                                                          first_number);
    }
    {
        cout << "Please enter the second number: ";
        string second_number_as_string;
        cin >> second_number_as_string;
        second_number_length = readNumberAsArrayFromString(
                                                           second_number_as_string,
                                                           second_number);
    }
    
    cout << "First number is : " << numberAsArrayToString(first_number, first_number_length) << endl;
    cout << "Second number is : " << numberAsArrayToString(second_number, second_number_length) << endl;
    
    int result[20000];
    int result_length =
    multiplyLargeNumbers(first_number, first_number_length,
                         second_number, second_number_length,
                         result);
    
    cout << "Result: " << numberAsArrayToString(result, result_length) << endl;
    return 0;
}
