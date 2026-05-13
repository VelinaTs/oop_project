#pragma once
#include "Animal.h"

class Cat : public Animal {
private:
    bool friendlyWithOtherCats;

public:
    Cat(string name, int age, string health, bool friendlyWithOtherCats)
        : Animal(name, "Cat", age, health), friendlyWithOtherCats(friendlyWithOtherCats) {}

    bool getFriendlyWithOtherCats() const { return friendlyWithOtherCats; }
};
