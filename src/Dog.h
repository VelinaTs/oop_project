#pragma once
#include "Animal.h"

class Dog : public Animal {
private:
    bool knowsCommands;

public:
    Dog(string name, int age, string health, bool knowsCommands)
        : Animal(name, "Dog", age, health), knowsCommands(knowsCommands) {}

    bool getKnowsCommands() const { return knowsCommands; }
};
