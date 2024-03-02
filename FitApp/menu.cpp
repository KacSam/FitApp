#include "menu.h"
#include <vector>
using namespace std;


void randomExercise(std::vector<Exercise*>gym, std::vector<Exercise*>withoutGym) {


    while (true) {
        cout << "Choose exercise type:\n1 - Gym exercise\n2 - Exercise without gym\n3 - Back\n";
        int exerciseType;

        while (!(std::cin >> exerciseType)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }



        switch (exerciseType) {
        case 1:
        {
            int randomindex = rand() % gym.size();
            Exercise* randomGymExercise = gym[randomindex];
            randomGymExercise->perform();
            cout << "---------------------------------" << endl;
            break;
        }
        break;
        case 2:
        {
            int randomindex = rand() % withoutGym.size();
            Exercise* randomGymExercise = withoutGym[randomindex];
            randomGymExercise->perform();
            cout << "---------------------------------" << endl;
            break;
        }
        case 3:
            break;
        default:
            cout << "choose correct option\n";
            break;

        }
        if (exerciseType == 3) {
            break;
        }

    }
}


void submenu(Human& person, std::vector<Exercise*>& gym, std::vector<Exercise*>& withoutGym) {
    while (true) {
        cout << "Choose option: \n1 - Display Person Info\n2 - Count BMI\n3 - Count caloric demand\n4 - Random Exercise\n5 - Exit\n";
        int subOption;

        while (!(std::cin >> subOption)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();  // Resetowanie flag b³êdu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        cout << "\n";
        switch (subOption) {
        case 1:
            cout << "Person Information:\n";
            cout << person;
            cout << "\n";
            break;
        case 2:
            cout << "Your BMI:\n";
            cout << person.countBmi() << endl;
            cout << "\n";
            break;
        case 3:
            cout << "Your caloric demand\n";
            cout << person.countCaloricDemand() << endl;
            cout << "\n";
            break;
        case 4:
            randomExercise(gym, withoutGym);
            cout << "\n";
            break;
        case 5:
            cout << "END\n";
            exit(1);
        default:
            cout << "Choose a valid option\n\n";
            break;
        }
    }
}




void menu(People& people, std::vector<Exercise*>& gym, std::vector<Exercise*>& withoutGym) {
    while (true) {
        cout << "Menu: \n1 - New person\n2 - Load Person\n3 - Exit\n";
        int mainOption;
        
        while (!(std::cin >> mainOption)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }


        switch (mainOption) {
        case 1:
            cout << "New person\n";
            {
                Human newPerson;
                newPerson.loadDataFromUser();
                people.addPerson(newPerson);
                people.saveToFile();
                submenu(newPerson, gym, withoutGym);
            }
            break;
        case 2:
            cout << "Choose person from the list\n";
            {
                Human loadedPerson;
                people.loadFromFile();
                people.displayAllPeople();
                loadedPerson = people.selectPerson();
                submenu(loadedPerson, gym, withoutGym);
            }
            break;
        case 3:
            cout << "Exit\n";
            exit(0);
        default:
            cout << "Choose correct option\n\n";
            break;
        }
    }
}
