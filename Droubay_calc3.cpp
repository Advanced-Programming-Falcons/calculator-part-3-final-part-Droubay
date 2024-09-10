#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

float num1, num2;
char optr;
string input;
float answer = 0.0;
char see_hist;
string history = "";
string equation;

bool parseInput();
//bool noMoreError();

int main(void){
    //instructions for calc
    cout << endl << "Enter your problem like so: number, operator, number" << endl;
    cout << "operators you can use include: + - * / ^\n";
    cout << "to view your history, type 0h0\n\n";

    //infinite loop
    while(true){
        cout << "Enter your equation: \n";
        getline(cin, input);
        
        if (parseInput()){

        //solves equation
            if(optr == '+'){
                answer = num1 + num2;
                cout << "= " + to_string(answer) << endl;}
            else if(optr == '-'){
                answer = num1 - num2;
                cout << "= " + to_string(answer) << endl;}
            else if(optr == '*'){
                answer = num1 * num2;
                cout << "= " + to_string(answer) << endl;}
            else if(optr == '/'){
                answer = num1/num2;
                cout << "= " + to_string(answer) << endl;}
            else if(optr == '^'){
                answer = pow(num1,num2);
                cout << "= " + to_string(answer) << endl;}
            else if(optr == 'h'){
                cout << history << endl;
                continue;
            }
            else{
                cout << "Invalid equation" << endl;
                continue;}
        }
        else{
            cout << "Invalid equation" << endl;
            continue;}
        
        equation = to_string(num1) + optr + to_string(num2) + " = " + to_string(answer) + ",\n";
        history = history + equation;
    }
}

bool parseInput(){
    istringstream iss(input);
    if (iss >> num1 >> optr >> num2){
        return true;
    }
    else{
        return false;}
}
