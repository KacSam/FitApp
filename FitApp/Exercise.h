/**
 * @file exercise.h
 * @brief Defines classes related to exercises for fitness.
 */

#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Exercise
 * @brief Base class representing a generic exercise.
 */
class Exercise {
public:
    /**
     * @brief Constructor for Exercise class.
     * @param name The name of the exercise.
     */
    Exercise(const std::string& name);

    /**
     * @brief Virtual function to perform the exercise.
     */
    virtual void perform() const;

    /**
     * @brief Virtual destructor for Exercise class.
     */
    virtual ~Exercise();

protected:
    string name;         ///< Name of the exercise.
    string difficulty;   ///< Difficulty level of the exercise.
    string bodyPart;     ///< Targeted body part for the exercise.
};

/**
 * @class ExerciseGym
 * @brief Derived class representing a gym-based exercise.
 */
class ExerciseGym : public Exercise {
public:
    /**
     * @brief Constructor for ExerciseGym class.
     * @param name The name of the exercise.
     * @param equipment The required equipment for the exercise.
     * @param bodyPart The targeted body part for the exercise.
     * @param difficulty The difficulty level of the exercise.
     */
    ExerciseGym(const std::string& name, const std::string& equipmentnt, const std::string& bodyPart, const std::string& difficulty);

    /**
     * @brief Override function to perform the gym-based exercise.
     */
    void perform() const override;

private:
    string equipment;   ///< Required equipment for the gym-based exercise.
};


/**
 * @class ExerciseWithoutGym
 * @brief Derived class representing a non-gym-based exercise.
 */
class ExerciseWithoutGym : public Exercise {
public:

    /**
     * @brief Constructor for ExerciseWithoutGym class.
     * @param name The name of the exercise.
     * @param location The location where the exercise can be performed.
     * @param bodyPart The targeted body part for the exercise.
     * @param difficulty The difficulty level of the exercise.
     */
    ExerciseWithoutGym(const std::string& name, const std::string& location, const std::string bodyPart, const std::string& difficulty);

    /**
     * @brief Override function to perform the non-gym-based exercise.
     */
    void perform() const override;

private:
    string location;    ///< Location where the non-gym-based exercise can be performed.
};

#endif 
