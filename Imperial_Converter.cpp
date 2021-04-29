#include <iostream>
using namespace std;

void To_Feet(){

    int In_Inches = 1;
    int In_Feet = 1;

    while (In_Inches > 0 || In_Feet > 0){
        cout << endl <<"Enter in Inches: ";
        cin >> In_Inches;

        In_Feet = ((In_Inches - (In_Inches % 12))/12);
        In_Inches = In_Inches % 12;
        cout << "In Feet: " << In_Feet << "," << In_Inches;
    }
}

void To_Inches(){

    int In_Inches = 1;
    int In_Feet = 1;

    while (In_Inches > 0 || In_Feet > 0){
        cout << endl <<"Enter in Feets and Inches: ";
        cin >> In_Feet >> In_Inches;
        In_Inches = ((In_Feet * 12) + In_Inches);
        cout << "In Inches: " << In_Inches;
    }
}

int main(){
    int Decision = 1;

    cout << "Enter '1' To_Feet and '2' To_Inches: ";
    cin >> Decision;

    if (Decision == 1){
        To_Feet();
    }
    else if (Decision == 2)
    {
        To_Inches();
    }
    
}