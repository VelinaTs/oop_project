#pragma once
#include <string>
#include <iostream>
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

    virtual void display() const {
        cout << "Name: " << name
             << " | Type: " << type
             << " | Age: " << age << " months"
             << " | Health: " << health
             << " | Status: " << status << "\n";
        if (foodType != "")
            cout << "   Feeding: " << foodType << " at " << feedingTime << "\n";
    }
};
