#include "../include/person.h"

Person* person_create(const char name[PERSON_NAME_MAX_LEN], int age, char gender, float height) {
    Person* new_person = (Person*) malloc(sizeof(Person));

    if(new_person == NULL) {
        free(new_person);
        return NULL;
    }

    strcpy(new_person->name, name);
    // new_person->name[PERSON_NAME_MAX_LEN-1] = '\0';
    new_person->age = age;

    if(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
        new_person->gender = 'N';
    } else {
        new_person->gender = gender;
    }

    new_person->height = height;

    return new_person;
}

void person_print(Person* person) {
    if(person == NULL) return;

    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: ");

    if(person->gender == 'M' || person->gender == 'm') {
        printf("Male");
    } else if(person->gender == 'F' || person->gender == 'f') {
        printf("Female");
    } else {
        printf("N/A");
    }
    printf("\n");

    printf("Height(in meters): %f\n", person->height);
}

void person_destroy(Person** person_ptr) {
    if(*person_ptr == NULL) return;

    free(*person_ptr);
    *person_ptr = NULL;
}