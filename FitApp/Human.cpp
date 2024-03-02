#include "Human.h"
#include <cmath>

Human::Human() : age(0), height(0), weight(0.0), activityLevel(0) {
    
}

Human::Human(const std::string& newFirstName, const std::string& newLastName,
    const std::string& newSex, int newAge,
    double newHeight, double newWeight, int newActivityLevel)
    : firstName(newFirstName), lastName(newLastName), sex(newSex),
    age(newAge), height(newHeight), weight(newWeight),
    activityLevel(newActivityLevel){}


void Human::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void Human::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Human::setSex(const std::string& newSex) {
    if (newSex == "Male" || newSex == "Female") {
        sex = newSex;
    }
    else {
        std::cerr << "Error: Invalid value for sex. Use 'Male' or 'Female'." << std::endl;
    }
}

void Human::setAge(int newAge) {
    if (newAge >= 0) {
        age = newAge;
    }
    else {
        std::cerr << "Error: Invalid value for age. Age must be non-negative." << std::endl;
    }
}

void Human::setHeight(double newHeight) {
    if (newHeight >= 0.0) {
        height = newHeight;
    }
    else {
        std::cerr << "Error: Invalid value for height. Height must be non-negative." << std::endl;
    }
}

void Human::setWeight(double newWeight) {
    if (newWeight >= 0.0) {
        weight = newWeight;
    }
    else {
        std::cerr << "Error: Invalid value for weight. Weight must be non-negative." << std::endl;
    }
}

void Human::setActivityLevel(int newActivityLevel) {
    if (newActivityLevel >= 1 && newActivityLevel <= 5) {
        activityLevel = newActivityLevel;
    }
    else {
        std::cerr << "Error: Invalid value for activity level. Use values 1, 2, 3, 4 or 5" << std::endl;
    }
}

string Human::getFirstName() const
{
    return firstName;
}

string Human::getLastName() const
{
    return lastName;
}

string Human::getSex() const
{
    return sex;
}

int Human::getAge() const
{
    return age;
}

double Human::getHeight() const
{
    return height;
}

double Human::getWeight() const
{
    return weight;
}

int Human::getActivityLevel() const
{
    return activityLevel;
}



double Human::countBmi() {
    return weight / ((height / 100) * (height / 100));
}

double Human::countCaloricDemand()
{
    double amr;
    double bmr = (10 * weight) + (6.25 * height) - (5 * age);
    double activityFactor=1;
    if (sex == "Male") {
        bmr += 5;
    }
    else {
        bmr -= 161;
    }
    switch (activityLevel)
    {
    case 1:
        activityFactor = 1.2;
        break;
    case 2:
        activityFactor = 1.375;
        break;
    case 3:
        activityFactor = 1.55;
        break;
    case 4:
        activityFactor = 1.725;
        break;
    case 5:
        activityFactor = 1.9;
        break;
    }

    amr = bmr * activityFactor;
    return amr;

}



 void Human::loadDataFromUser()
 {
     string newFirstName, newLastName, newSex;
     int newAge, newActivityLevel;
     double newHeight, newWeight;

     cout << "Enter first name: ";
     cin >> newFirstName;
     setFirstName(newFirstName);

     cout << "Enter last name: ";
     cin >> newLastName;
     setLastName(newLastName);

     
     while (true) {
         cout << "Enter sex: ";
         cin >> newSex;
         if (newSex == "Male" || newSex == "Female") {
             setSex(newSex);
             break;
         }
         else {
             std::cerr << "Error: Invalid value for sex. Use 'Male' or 'Female'." << std::endl;
         }
     }
     
     

     while (true) {
         cout << "Enter age: ";
         cin >> newAge;
         if (cin.fail() || newAge < 0) {
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cerr << "Error: Invalid value for age. Age must be a non-negative integer." << std::endl;
         }
         else {
             age = newAge;
             setAge(newAge);
             break;
         }
     }

     while (true) {
         cout << "Enter height: ";
         cin >> newHeight;
         if (cin.fail() || newHeight < 0) {
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cerr << "Error: Invalid value for age. Age must be a non-negative integer." << std::endl;
         }
         else {
             height = newHeight;
             setHeight(newHeight);
             break;
         }
     }

     while (true) {
         cout << "Enter weight: ";
         cin >> newWeight;
         if (cin.fail() || newWeight < 0) {
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cerr << "Error: Invalid value for age. Age must be a non-negative integer." << std::endl;
         }
         else {
             weight = newWeight;
             setWeight(newWeight);
             break;
         }
     }

     while (true) {
         cout << "What is your activity level:\n1 - Sedentary\n2 - Light exercise (1-3 workouts per week)\n3 - Moderate exercise (3-5 workouts per week)\n4 - Heavy exercise (6-7 workouts per week)\n5 - Very heavy exercise (6-7 intense workouts per week)\n";
         cin >> newActivityLevel;
         if (cin.fail() || (newActivityLevel < 1 && newActivityLevel > 5)) {
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cerr << "Error: Invalid value for age. Age must be a non-negative integer." << std::endl;
         }
         else {
             activityLevel = newActivityLevel;
             setActivityLevel(newActivityLevel);
             break;
         }
     }
 }

 std::ostream& operator<<(std::ostream& os, const Human& human)
 {
     os << "First Name: " << human.getFirstName() << "\n"
         << "Last Name: " << human.getLastName() << "\n"
         << "Sex: " << human.getSex() << "\n"
         << "Age: " << human.getAge() << " years\n"
         << "Height: " << human.getHeight() << " cm\n"
         << "Weight: " << human.getWeight() << " kg\n"
         << "Activity Level: " << human.getActivityLevel() << "\n";
     return os;
 }
