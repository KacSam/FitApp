/**
 * @file Human.h
 * @brief Header file for the Human class.
 */

#ifndef HUMAN_H
#define HUMAN_H

#include<iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "Human.h"
using namespace std;

/**
 * @class Human
 * @brief Represents a human with basic information.
 */
class Human
{
public:
    /**
     * @brief Default constructor for the Human class.
     */
    Human();


    /**
     * @brief Parameterized constructor for the Human class.
     * @param newFirstName The first name of the human.
     * @param newLastName The last name of the human.
     * @param newSex The gender of the human.
     * @param newAge The age of the human.
     * @param newHeight The height of the human.
     * @param newWeight The weight of the human.
     * @param newActivityLevel The activity level of the human.
     */
    Human(const std::string& newFirstName, const std::string& newLastName,
        const std::string& newSex, int newAge,
        double newHeight, double newWeight, int newActivityLevel);

    /**
     * @brief Set the first name of the human.
     * @param newFirstName The new first name.
     */
    void setFirstName(string newFirstName);

    /**
     * @brief Set the last name of the human.
     * @param newLastName The new last name.
     */
    void setLastName(string newLastName);

    /**
     * @brief Set the gender of the human.
     * @param newSex The new gender.
     */
    void setSex(const std::string& newSex);

    /**
    * @brief Set the age of the human.
    * @param newAge The new age.
    */
    void setAge(int newAge);

    /**
     * @brief Set the height of the human.
     * @param newHeight The new height.
     */
    void setHeight(double newHeight);

    /**
     * @brief Set the weight of the human.
     * @param newWeight The new weight.
     */
    void setWeight(double newWeight);

    /**
     * @brief Set the activity level of the human.
     * @param newActivityLevel The new activity level.
     */
    void setActivityLevel(int newActivityLevel);

    /**
     * @brief Get the first name of the human.
     * @return The first name of the human.
     */
    string getFirstName() const;

    /**
     * @brief Get the last name of the human.
     * @return The last name of the human.
     */
    string getLastName() const;

    /**
     * @brief Get the gender of the human.
     * @return The gender of the human.
     */
    string getSex() const;

    /**
     * @brief Get the age of the human.
     * @return The age of the human.
     */
    int getAge() const;

    /**
     * @brief Get the height of the human.
     * @return The height of the human.
     */
    double getHeight() const;

    /**
     * @brief Get the weight of the human.
     * @return The weight of the human.
     */
    double getWeight() const;

    /**
     * @brief Get the activity level of the human.
     * @return The activity level of the human.
     */
    int getActivityLevel() const;

    /**
     * @brief Calculate the Body Mass Index (BMI) of the human.
     * @return The calculated BMI.
     */
    double countBmi();

    /**
     * @brief Calculate the caloric demand of the human.
     * @return The calculated caloric demand.
     */
    double countCaloricDemand();

    /**
     * @brief Load data for the human from user input.
     */
    void loadDataFromUser();

    /**
     * @brief Overloaded stream insertion operator to print human information.
     * @param os The output stream.
     * @param human The human object to be printed.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Human& human);

    /**
     * @brief Template function to get data of any type from the human.
     * @tparam T The type of data to be retrieved.
     * @param attribute The attribute to be retrieved.
     * @return The retrieved data.
     */
    template <typename T>
    T getData(const T& attribute) const {
        return attribute;
    }



private:
    string firstName;      /**< The first name of the human. */
    string lastName;       /**< The last name of the human. */
    string sex;            /**< The gender of the human. */
    int age;               /**< The age of the human. */
    double height;         /**< The height of the human. */
    double weight;         /**< The weight of the human. */
    int activityLevel;     /**< The activity level of the human. */
};

#endif // HUMAN_H

