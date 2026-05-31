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
    cout << "8. Add vaccination to medical record\n"; 
    cout << "9. Add checkup date to medical record\n"; 
    cout << "10. Generate resource/shopping list\n";
    cout << "11. Volunteer diary (add / show / remove)\n";
    cout << "12. Save to file\n";
    cout << "13. Load from file\n";
    cout << "14. Print adoption description\n";
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
            try {
                string name, health;
                int age;
                bool commands;
                cout << "Name: ";          getline(cin, name);
                if (name.empty()) throw invalid_argument("Name cannot be empty.");
                cout << "Age (months): ";  cin >> age; cin.ignore();
                if (age < 0) throw invalid_argument("Age cannot be negative.");
                cout << "Health (e.g. healthy, sick, recovering): "; getline(cin, health);
                if (health.empty()) throw invalid_argument("Health field cannot be empty.");
                cout << "Knows commands (1=yes 0=no): "; cin >> commands; cin.ignore();
                shelter.addAnimal(new Dog(name, age, health, commands));
                cout << "Dog added.\n";
            } catch (invalid_argument& e) {
                cout << "Error: " << e.what() << "\n";
                cin.clear(); cin.ignore(1000, '\n');
            }
        }
        else if (choice == 2) {
            try {
                string name, health;
                int age;
                bool friendly;
                cout << "Name: ";          getline(cin, name);
                if (name.empty()) throw invalid_argument("Name cannot be empty.");
                cout << "Age (months): ";  cin >> age; cin.ignore();
                if (age < 0) throw invalid_argument("Age cannot be negative.");
                cout << "Health (e.g. healthy, sick, recovering): "; getline(cin, health);
                if (health.empty()) throw invalid_argument("Health field cannot be empty.");
                cout << "Friendly with other cats (1=yes 0=no): "; cin >> friendly; cin.ignore();
                shelter.addAnimal(new Cat(name, age, health, friendly));
                cout << "Cat added.\n";
            } catch (invalid_argument& e) {
                cout << "Error: " << e.what() << "\n";
                cin.clear(); cin.ignore(1000, '\n');
            }
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
    
        else if (choice == 8) {
            string name, vaccine;
            cout << "Animal name: ";   getline(cin, name);
            cout << "Vaccination (e.g. Rabies, Parvovirus): ";   getline(cin, vaccine);
            shelter.addVaccination(name, vaccine);
        }
        
        else if (choice == 9) {
            string name, date;
            cout << "Animal name: ";          getline(cin, name);
            cout << "Checkup date (e.g. 2024-03-15): "; getline(cin, date);
            shelter.addCheckup(name, date);
        }

        else if (choice == 10) {
            shelter.generateResourceList();
        }
        else if (choice == 11) {
            cout << "  a. Add volunteer\n"
                 << "  b. Show all volunteers\n"
                 << "  c. Remove volunteer\n"
                 << "Sub-choice: ";
            char sub;
            cin >> sub; cin.ignore();
            if (sub == 'a') {
                string vname, aname;
                cout << "Volunteer name: "; getline(cin, vname);
                cout << "Animal name: ";    getline(cin, aname);
                shelter.addVolunteer(vname, aname);
            } else if (sub == 'b') {
                shelter.showVolunteers();
            } else if (sub == 'c') {
                string vname;
                cout << "Volunteer name to remove: "; getline(cin, vname);
                shelter.removeVolunteer(vname);
            } else {
                cout << "Unknown sub-choice.\n";
            }
        }

        else if (choice == 12) {
            shelter.saveToFile("shelter.dat");
        }
        else if (choice == 13) {
            shelter.loadFromFile("shelter.dat");
        }
        else if (choice == 14) {
            string name;
            cout << "Animal name: "; getline(cin, name);
            shelter.printDescription(name);
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
