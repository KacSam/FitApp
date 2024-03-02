/**
 * @file People.h
 * @brief Declaration of the People class.
 */

#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "Human.h"
using namespace std;

/**
 * @class People
 * @brief Represents a collection of Human objects.
 *
 * The People class manages a collection of Human objects and provides
 * methods for adding, finding, and displaying information about people.
 */
class People
{
public:
    /**
     * @brief Default constructor for the People class.
     */
    People();

    /**
     * @brief Adds a new person to the collection.
     * @param person The Human object to be added.
     */
    void addPerson(const Human& person);

    /**
     * @brief Finds a person with the given first and last name.
     * @param firstName The first name of the person to find.
     * @param lastName The last name of the person to find.
     * @return The Human object if found, otherwise throws std::runtime_error.
     */
    Human findPerson(const std::string& firstName, const std::string& lastName) const;

    /**
     * @brief Retrieves a vector containing all people in the collection.
     * @return A vector of Human objects.
     */
    std::vector<Human> getAllPeople() const;

    /**
     * @brief Saves the collection to a file.
     */
    void saveToFile() const;

    /**
     * @brief Loads the collection from a file.
     */
    void loadFromFile();

    /**
     * @brief Displays information about all people in the collection.
     */
    void displayAllPeople();

    /**
     * @brief Finds a person with the given first and last name.
     * @param firstName The first name of the person to find.
     * @param lastName The last name of the person to find.
     * @return A pointer to the Human object if found, nullptr otherwise.
     */
    Human* findPerson(const std::string& firstName, const std::string& lastName);

    /**
     * @brief Allows the user to select a person from the collection.
     * @return The selected Human object.
     */
    Human selectPerson();
    

private:
    std::vector<Human> people;  /**< The vector containing all Human objects. */
};

#endif // PEOPLE_H
