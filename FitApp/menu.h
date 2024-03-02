/**
 * @file menu.h
 * @brief Header file for menu functionality.
 */

#pragma once
#include <vector>
#include "Exercise.h"
#include "Human.h"
#include "People.h"
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Generates a random exercise for a person based on availability in the gym and without the gym.
 *
 * This function takes two vectors of Exercise pointers - one for exercises available in the gym and
 * another for exercises that can be done without the gym. It then selects a random exercise and assigns
 * it to the person.
 *
 * @param gym Vector of Exercise pointers available in the gym.
 * @param withoutGym Vector of Exercise pointers available without the gym.
 */
void randomExercise(std::vector<Exercise*> gym, std::vector<Exercise*> withoutGym);

/**
 * @brief Displays a submenu for a specific person to choose exercises.
 *
 * This function takes a reference to a Human object and two vectors of Exercise pointers - one for
 * exercises available in the gym and another for exercises that can be done without the gym. It allows
 * the person to choose exercises from both categories and updates the person's exercise list accordingly.
 *
 * @param person Reference to the Human object representing a person.
 * @param gym Vector of Exercise pointers available in the gym.
 * @param withoutGym Vector of Exercise pointers available without the gym.
 */
void submenu(Human& person, std::vector<Exercise*>& gym, std::vector<Exercise*>& withoutGym);

/**
 * @brief Displays the main menu for managing exercises and people.
 *
 * This function takes a reference to a People object and two vectors of Exercise pointers - one for
 * exercises available in the gym and another for exercises that can be done without the gym. It provides
 * options for managing exercises and people, including adding people and exercises, displaying lists, and
 * assigning exercises to people.
 *
 * @param people Reference to the People object managing a list of people.
 * @param gym Vector of Exercise pointers available in the gym.
 * @param withoutGym Vector of Exercise pointers available without the gym.
 */
void menu(People& people, std::vector<Exercise*>& gym, std::vector<Exercise*>& withoutGym);