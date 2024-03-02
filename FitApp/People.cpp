#include "People.h"


People::People() {}



void People::addPerson(const Human& person)
{
    people.push_back(person);
}

Human People::findPerson(const std::string& firstName, const std::string& lastName) const
{
    for (const auto& person : people)
    {
        if (person.getFirstName() == firstName && person.getLastName() == lastName)
        {
            return person;
        }
    }


    return Human();
}

std::vector<Human> People::getAllPeople() const
{
    return people;
}

void People::saveToFile() const
{
    ofstream outputFile("people_data.txt", ios::out | ios::app);

    if (outputFile.is_open())
    {
        for (const Human& person : people)
        {
            outputFile << person.getFirstName() << " "
                << person.getLastName() << " "
                << person.getSex() << " "
                << person.getAge() << " "
                << person.getHeight() << " "
                << person.getWeight() << " "
                << person.getActivityLevel() << "\n";
        }

        outputFile.close();
        cout << "Data saved to file successfully." << endl;
    }
    else
    {
        cerr << "Unable to open the file for saving." << endl;
    }
}

void People::loadFromFile()
{
    ifstream inputFile("people_data.txt");

    if (inputFile.is_open())
    {
        people.clear();  

        string firstName, lastName, sex;
        int age, activityLevel;
        double height, weight;

        while (inputFile >> firstName >> lastName >> sex >> age >> height >> weight >> activityLevel)
        {
            Human person(firstName, lastName, sex, age, height, weight, activityLevel);
            addPerson(person);
        }

        inputFile.close();
        cout << "Data loaded from file successfully." << endl;
    }
    else
    {
        cerr << "Unable to open the file for loading." << endl;
    }
}



void People::displayAllPeople()
{
    std::cout << "All People in the Database:" << std::endl;

    if (people.empty())
    {
        std::cout << "No people in the database." << std::endl;
        return;
    }

    for (const auto& person : people)
    {
        std::cout << person.getFirstName() << " " << person.getLastName() << std::endl;
    }
 
}

Human* People::findPerson(const std::string& firstName, const std::string& lastName)
{
    for (auto& person : people) {
        if (person.getFirstName() == firstName && person.getLastName() == lastName) {
            return &person;
        }
    }

    return nullptr;
}

Human People::selectPerson()
{
    do {
        std::cout << "Select a person from the list by entering their first and last name:" << std::endl;

        std::string firstName, lastName;
        std::cout << "First Name: ";
        std::cin >> firstName;
        std::cout << "Last Name: ";
        std::cin >> lastName;

        Human* selectedPersonPtr = findPerson(firstName, lastName);

        if (selectedPersonPtr != nullptr) {
            return *selectedPersonPtr;
        }
        else {
            std::cout << "Person not found. Please try again." << std::endl;
        }
    } while (true);  
}





