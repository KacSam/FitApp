#include<iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "Exercise.h"
#include "menu.h"
using namespace std;

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(0)));

    std::vector<Exercise*> exercisesGym;
    std::vector<Exercise*> exercisesWithoutGym;

    exercisesGym.push_back(new ExerciseGym("Weightlifting", "Dumbbells", "Full Body", "Medium"));
    exercisesGym.push_back(new ExerciseGym("Treadmill Run", "Treadmill", "Cardio", "Hard"));
    exercisesGym.push_back(new ExerciseGym("Elliptical Workout", "Elliptical", "Legs", "Hard"));
    exercisesGym.push_back(new ExerciseGym("Bench Press", "Barbell", "Chest", "Hard"));
    exercisesGym.push_back(new ExerciseGym("Squat", "Barbell", "Legs", "Medium"));


    exercisesWithoutGym.push_back(new ExerciseWithoutGym("Running", "Park", "Cardio", "Easy"));
    exercisesWithoutGym.push_back(new ExerciseWithoutGym("Yoga", "Home", "Flexibility", "Medium"));
    exercisesWithoutGym.push_back(new ExerciseWithoutGym("Jumping Jacks", "Home", "Cardio", "Easy"));
    exercisesWithoutGym.push_back(new ExerciseWithoutGym("Push-ups", "Home", "Upper Body", "Medium"));
    exercisesWithoutGym.push_back(new ExerciseWithoutGym("Planks", "Home", "Core", "Hard"));

    cout << "\t\tFitApp\n";
    People people;




    if (argc > 1) {
        int parameter = atoi(argv[1]);

        if (parameter == 1) {
            Human loadedPerson;
            people.loadFromFile();
            people.displayAllPeople();
            loadedPerson = people.selectPerson();
            submenu(loadedPerson, exercisesGym, exercisesWithoutGym);

        }

    }

    else {
        
        menu(people, exercisesGym, exercisesWithoutGym);
    }
    

    for (Exercise* exercise : exercisesGym) {
        delete exercise;
    }
    exercisesGym.clear();
    for (Exercise* exercise : exercisesWithoutGym) {
        delete exercise;
    }
    exercisesWithoutGym.clear();

    
    
    
    
    return -1;

}
