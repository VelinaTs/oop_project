#pragma once
#include <string>
#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

class Shelter {
private:
    Animal* animals[100];
    int count;

public:
    Shelter() : count(0) {}

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

};
