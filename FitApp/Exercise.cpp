
#include "Exercise.h"


Exercise::Exercise(const std::string& name) : name(name), difficulty(""), bodyPart("") {}

void Exercise::perform() const {
    cout << "Performing exercise: " << name << endl;
    cout << "Difficulty: " << difficulty << endl;
    cout << "Targeted body part: " << bodyPart << endl;
}

Exercise::~Exercise() {}


ExerciseGym::ExerciseGym(const std::string& name, const std::string& equipment, const std::string& bodyPart, const std::string& difficulty)
    : Exercise(name), equipment(equipment) {
    this->bodyPart = bodyPart;
    this->difficulty = difficulty;
}

void ExerciseGym::perform() const {
    cout << "Performing gym exercise: " << name << endl;
    cout << "Equipment used: " << equipment << endl;
    cout << "Difficulty: " << difficulty << endl;
    cout << "Targeted body part: " << bodyPart << endl;
}


ExerciseWithoutGym::ExerciseWithoutGym(const std::string& name,const std::string& location,const std::string bodyPart, const std::string& difficulty)
    : Exercise(name), location(location) {
    this->bodyPart = bodyPart;
    this->difficulty = difficulty;
}

void ExerciseWithoutGym::perform() const {
    cout << "Performing exercise without gym: " << name << endl;
    cout << "Location: " << location << endl;
    cout << "Difficulty: " << difficulty << endl;
    cout << "Targeted body part: " << bodyPart << endl;
}
