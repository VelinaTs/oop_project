#pragma once
#include <string>
#include <iostream>
using namespace std;

class Volunteer {
private:
    string volunteerName;
    string assignedAnimal;

public:
    Volunteer() : volunteerName(""), assignedAnimal("") {}
    Volunteer(string volunteerName, string assignedAnimal)
        : volunteerName(volunteerName), assignedAnimal(assignedAnimal) {}

    string getVolunteerName() const { return volunteerName; }
    string getAssignedAnimal() const { return assignedAnimal; }

    void display() const {
        cout << "Volunteer: " << volunteerName
             << " -> Animal: " << assignedAnimal << "\n";
    }
};
