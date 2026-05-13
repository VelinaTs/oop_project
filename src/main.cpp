#include <iostream>
#include <string>
#include "Shelter.h"
using namespace std;

void showMenu() {
    cout << "\n====== ANIMAL SHELTER ======\n";
    cout << "1. Add dog\n";
    cout << "2. Add cat\n";
    cout << "3. Show all animals\n";
    cout << "4. Change status (available / quarantine / adopted)\n";
    cout << "5. Search by type\n";
    cout << "6. Search by age (under X months)\n";
    cout << "7. Set feeding schedule\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

int main() {
    Shelter shelter;

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, health;
            int age;
            bool commands;
            cout << "Name: ";          getline(cin, name);
            cout << "Age (months): ";  cin >> age; cin.ignore();
            cout << "Health (e.g. healthy, sick, recovering): "; getline(cin, health);
            cout << "Knows commands (1=yes 0=no): "; cin >> commands; cin.ignore();
            shelter.addAnimal(new Dog(name, age, health, commands));
            cout << "Dog added.\n";
        }
        else if (choice == 2) {
            string name, health;
            int age;
            bool friendly;
            cout << "Name: ";          getline(cin, name);
            cout << "Age (months): ";  cin >> age; cin.ignore();
            cout << "Health (e.g. healthy, sick, recovering): "; getline(cin, health);
            cout << "Friendly with other cats (1=yes 0=no): "; cin >> friendly; cin.ignore();
            shelter.addAnimal(new Cat(name, age, health, friendly));
            cout << "Cat added.\n";
        }
        else if (choice == 3) {
            shelter.displayAll();
        }
        else if (choice == 4) {
            string name, status;
            cout << "Animal name: ";                               getline(cin, name);
            cout << "New status (available/quarantine/adopted): "; getline(cin, status);
            shelter.setStatus(name, status);
        }
        else if (choice == 5) {
            string type;
            cout << "Type (Dog / Cat): "; getline(cin, type);
            shelter.filterByType(type);
        }
        else if (choice == 6) {
            int months;
            cout << "Under how many months: "; cin >> months; cin.ignore();
            shelter.filterByAge(months);
        }

        else if (choice == 7) {
            string name, food, time;
            cout << "Animal name: ";  getline(cin, name);
            cout << "Food type: ";    getline(cin, food);
            cout << "Feeding time (e.g. 08:00, 18:00): "; getline(cin, time);
            shelter.setFeedingSchedule(name, food, time);
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
