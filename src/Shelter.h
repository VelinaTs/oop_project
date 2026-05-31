#pragma once
#include <string>
#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Volunteer.h"
using namespace std;

class Shelter {
private:
    Animal* animals[100];
    int count;
    Volunteer volunteers[100];
    int volunteerCount;

public:
    Shelter() : count(0), volunteerCount(0) {}

    ~Shelter() {
        for (int i = 0; i < count; i++)
            delete animals[i];
    }

    void addAnimal(Animal* a) {
        if (count < 100)
            animals[count++] = a;
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No animals in shelter.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "[" << i + 1 << "] ";
            animals[i]->display();
        }
    }

    void setStatus(string name, string newStatus) {
        for (int i = 0; i < count; i++) {
            if (animals[i]->getName() == name) {
                animals[i]->setStatus(newStatus);
                if (newStatus == "adopted") {
                    cout << animals[i]->getName() << " has been adopted. Removing from shelter.\n";
                    delete animals[i];
                    for (int j = i; j < count - 1; j++)
                        animals[j] = animals[j + 1];
                    count--;
                }
                return;
            }
        }
        cout << "Animal not found.\n";
    }

    void setFeedingSchedule(string name, string food, string time) {
        for (int i = 0; i < count; i++) {
            if (animals[i]->getName() == name) {
                animals[i]->setFeedingSchedule(food, time);
                cout << "Feeding schedule set.\n";
                return;
            }
        }
        cout << "Animal not found.\n";
    }

    void filterByType(string type) const {
        cout << "Results for type '" << type << "':\n";
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (animals[i]->getType() == type) {
                animals[i]->display();
                found = true;
            }
        }
        if (!found) cout << "  None.\n";
    }

    void filterByAge(int maxMonths) const {
        cout << "Animals under " << maxMonths << " months:\n";
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (animals[i]->getAge() < maxMonths) {
                animals[i]->display();
                found = true;
            }
        }
        if (!found) cout << "  None.\n";
    }

    void addVaccination(string name, string vaccine) {
        for (int i = 0; i < count; i++) {
            if (animals[i]->getName() == name) {
                animals[i]->getMedicalRecord().addVaccination(vaccine);
                cout << "Vaccination added.\n";
                return;
            }
        }
        cout << "Animal not found.\n";
    }

    void addCheckup(string name, string date) {
        for (int i = 0; i < count; i++) {
            if (animals[i]->getName() == name) {
                animals[i]->getMedicalRecord().addCheckup(date);
                cout << "Checkup date added.\n";
                return;
            }
        }
        cout << "Animal not found.\n";
    }

    void generateResourceList() const {
        if (count == 0) {
            cout << "No animals in shelter - nothing to buy.\n";
            return;
        }
        cout << "--- Shopping List (" << count << " animals) ---\n";
        cout << "FOOD:\n";
        bool anyFood = false;
        for (int i = 0; i < count; i++) {
            string food = animals[i]->getFoodType();
            string time = animals[i]->getFeedingTime();
            if (food != "") {
                cout << "  " << animals[i]->getName() << ": " << food
                     << " (feeding time: " << time << ")\n";
                anyFood = true;
            }
        }
        if (!anyFood)
            cout << "  (no feeding schedules set yet)\n";

        cout << "MEDICINE / CHECKUPS:\n";
        bool anyMed = false;
        for (int i = 0; i < count; i++) {
            const MedicalRecord& rec = animals[i]->getMedicalRecord();
            if (rec.getCheckupCount() > 0) {
                cout << "  " << animals[i]->getName() << " - next checkup: "
                     << rec.getCheckupDate(rec.getCheckupCount() - 1) << "\n";
                anyMed = true;
            }
        }
        if (!anyMed)
            cout << "  (no checkups scheduled yet)\n";
    }

    void addVolunteer(string volunteerName, string animalName) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (animals[i]->getName() == animalName) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Animal '" << animalName << "' not found.\n";
            return;
        }
        if (volunteerCount < 100) {
            volunteers[volunteerCount++] = Volunteer(volunteerName, animalName);
            cout << "Volunteer added.\n";
        } else {
            cout << "Volunteer list full.\n";
        }
    }

    void showVolunteers() const {
        if (volunteerCount == 0) {
            cout << "No volunteers registered.\n";
            return;
        }
        cout << "--- Volunteer Diary ---\n";
        for (int i = 0; i < volunteerCount; i++) {
            cout << "[" << i + 1 << "] ";
            volunteers[i].display();
        }
    }

    void removeVolunteer(string volunteerName) {
        for (int i = 0; i < volunteerCount; i++) {
            if (volunteers[i].getVolunteerName() == volunteerName) {
                for (int j = i; j < volunteerCount - 1; j++)
                    volunteers[j] = volunteers[j + 1];
                volunteerCount--;
                cout << "Volunteer removed.\n";
                return;
            }
        }
        cout << "Volunteer not found.\n";
    }

};
