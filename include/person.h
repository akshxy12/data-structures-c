#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#define PERSON_NAME_MAX_LEN 20


/* ----------------------------- Data Structures ---------------------------- */

/**
 *  Defining person object
 *  @var    name    Person's name
 *  @var    age     Person's age
 *  @var    gender  Person's gender(M/F)
 *  @var    height  Person's height
 */
typedef struct _person {
    char name[PERSON_NAME_MAX_LEN];
    int age;
    char gender;
    float height;
} Person;

/* -------------------------- Function Declarations ------------------------- */

/**
 *  Create a person object
 *  @param  name        Person's name
 *  @param  age         Person's age
 *  @param  gender      Person's gender(M/F)
 *  @param  height      Person's height
 *  @return new_person  New person object created
 */
Person* person_create(const char name[PERSON_NAME_MAX_LEN], int age, char gender, float height);

/**
 *  Print a person object
 *  @param  person  Person object
 */
void person_print(Person* person);

/**
 *  Destroy a person object
 *  @param  person_ptr  Pointer to a person object
 */
void person_destroy(Person** person_ptr);

#endif