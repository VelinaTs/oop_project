#pragma once
#include <string>
#include <iostream>
using namespace std;

// MedicalRecord is a standalone class responsible only for health tracking.
// It is not a subclass of anything — it is composed inside Animal
// (Animal "has a" MedicalRecord, it does not "inherit" one).
// This separation keeps each class focused on one responsibility.
class MedicalRecord {
private:
    // All data is private — outside code cannot modify it directly.
    // Access is only through the public methods below (encapsulation).
    string vaccinations[10];
    string checkupDates[10];
    int vaccinationCount;
    int checkupCount;

public:
    // Default constructor: initializes counters to 0 so the object is
    // in a valid state the moment it is created (Lesson 3 — Object Lifecycle).
    MedicalRecord() : vaccinationCount(0), checkupCount(0) {}

    // Adds a vaccination name (e.g. "Rabies") to the list.
    // Guards against overflow — max 10 entries.
    void addVaccination(string vaccine) {
        if (vaccinationCount < 10)
            vaccinations[vaccinationCount++] = vaccine;
    }

    // Adds a checkup date (e.g. "2024-03-15") to the list.
    void addCheckup(string date) {
        if (checkupCount < 10)
            checkupDates[checkupCount++] = date;
    }

    // Getters — marked const because they do not modify the object (Lesson 5).
    int getVaccinationCount() const { return vaccinationCount; }
    int getCheckupCount()     const { return checkupCount; }

    string getVaccination(int i) const {
        if (i >= 0 && i < vaccinationCount) return vaccinations[i];
        return "";
    }

    string getCheckupDate(int i) const {
        if (i >= 0 && i < checkupCount) return checkupDates[i];
        return "";
    }

    void display() const {
        if (vaccinationCount == 0)
            cout << "   Vaccinations: none\n";
        else {
            cout << "   Vaccinations: ";
            for (int i = 0; i < vaccinationCount; i++) {
                cout << vaccinations[i];
                if (i < vaccinationCount - 1) cout << ", ";
            }
            cout << "\n";
        }

        if (checkupCount == 0)
            cout << "   Checkup dates: none\n";
        else {
            cout << "   Checkup dates: ";
            for (int i = 0; i < checkupCount; i++) {
                cout << checkupDates[i];
                if (i < checkupCount - 1) cout << ", ";
            }
            cout << "\n";
        }
    }
};
