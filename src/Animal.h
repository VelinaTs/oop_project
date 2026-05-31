#pragma once
#include <string>
#include <iostream>
#include "MedicalRecord.h"
using namespace std;

class Animal {
protected:
    string name;
    string type;
    int age;
    string health;
    string status;
    string foodType;
    string feedingTime;
    // Composition: Animal "has a" MedicalRecord — it owns it as a member object.
    // MedicalRecord is created automatically when Animal is constructed (stack allocation)
    // and destroyed automatically when Animal is destroyed. No manual new/delete needed.
    MedicalRecord medicalRecord;

public:
    Animal(string name, string type, int age, string health)
        : name(name), type(type), age(age), health(health), status("available"), foodType(""), feedingTime("") {}

    virtual ~Animal() {}

    string getName()   const { return name; }
    string getType()   const { return type; }
    int    getAge()    const { return age; }
    string getHealth() const { return health; }
    string getStatus() const { return status; }

    void setStatus(string s) { this->status = s; }

    void setFeedingSchedule(string food, string time) {
        foodType = food;
        feedingTime = time;
    }

    string getFoodType()    const { return foodType; }
    string getFeedingTime() const { return feedingTime; }

    // Two versions: non-const allows modifying the record (e.g. adding a vaccination),
    // const version is used when only reading (e.g. inside display()).
    MedicalRecord& getMedicalRecord() { return medicalRecord; }
    const MedicalRecord& getMedicalRecord() const { return medicalRecord; }

    virtual string generateDescription() const {
        string desc = name + " is a " + to_string(age) + "-month-old " + type
            + " looking for a loving home. ";
        if (health == "healthy")
            desc += "Currently in great health. ";
        else
            desc += "Health status: " + health + ". ";
        if (foodType != "")
            desc += "Eats " + foodType + " (fed at " + feedingTime + "). ";
        if (medicalRecord.getVaccinationCount() > 0) {
            desc += "Vaccinations: ";
            for (int i = 0; i < medicalRecord.getVaccinationCount(); i++) {
                desc += medicalRecord.getVaccination(i);
                if (i < medicalRecord.getVaccinationCount() - 1) desc += ", ";
            }
            desc += ". ";
        }
        return desc;
    }

    virtual void display() const {
        cout << "Name: " << name
             << " | Type: " << type
             << " | Age: " << age << " months"
             << " | Health: " << health
             << " | Status: " << status << "\n";
        if (foodType != "")
            cout << "   Feeding: " << foodType << " at " << feedingTime << "\n";
        // Delegates to MedicalRecord's own display() — each class prints its own data.
        medicalRecord.display();
    }
};
