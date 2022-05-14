
/**/
/* Author        : Mohamed Shishtawy                         */
/* File          : Program.c                                 */
/* Date          : 5/8/2022                                  */
/* Version       : V01                                       */
/* GitHub        : https://github.com/Shishtawyy             */
/**/


//all the functions
#include "program.h"

/*This is an array of structs that we store the info of the students in*/
static struct student arr[20];

/*This is an array to keep an eye on every index if it's available or not */
int arr_counter[20];

/* This Function Sets the initial password for the admin mode.This function runs only once */
char *adminpass;

char *set_admin_password() {
    adminpass = (char *) malloc(strlen("1234") + 1);
    strcpy(adminpass, "1234");

}

/* This function takes the id of the student & a degree as an input & changes the degree of that student to the new one */

int edit_grade(int degree, int id) {
    int state = 0;
    int index = get_index(id);
    if (index == -1) {
        state = 0;
    } else {
        arr[index].degree = degree;
        state = 1;
    }
    return state;
}


/*
   This function adds a new student to the system as soon as there's a room for that student.
   It takes all the data about the student as an input.
*/
int add_student(char *name, char *password, int degree, int id, int age, int gender) {
    for (int i = 0; i < 20; i++) {
        if (arr[i].id == id) {
            printf("This Id is already used.Please try again\n");
            return 0;
        }
    }
    int index = check_availability();
    if (gender == 1) {
        arr[index].gender = 'M';
    } else if (gender == 2) {
        arr[index].gender = 'F';
    } else {
        printf("You entered a wrong character for the gender.Please try again.\n");
        return 0;
    }
    arr[index].name = (char *) malloc(strlen(name) + 1);
    strcpy(arr[index].name, name);
    arr[index].password = (char *) malloc(strlen(password) + 1);
    strcpy(arr[index].password, password);
    arr[index].degree = degree;
    arr[index].id = id;
    arr[index].age = age;
    arr_counter[index] = 1;
    printf("Student added to the system successfully\n");

}


/* this function takes a new password as an input and it sets it as the default admin Pass */
int edit_admin_pass(char *newpass) {
    adminpass = (char *) realloc(adminpass, strlen(newpass) + 1);
    strcpy(adminpass, newpass);
    if (strcmp(adminpass, newpass) == 0)
        return 1;
    else
        return 0;
}

/* this function takes a new password and the id of the student as an input and it sets this pass as the default pass for that student */
int edit_user_pass(int index, char *newpass) {
    arr[index].password = (char *) realloc(arr[index].password, strlen(newpass) + 1);
    strcpy(arr[index].password, newpass);
    if (strcmp(arr[index].password, newpass) == 0)
        return 1;
    else
        return 0;
}

/* this function is for admin mode that takes a new name and the id of the student as an input and it sets this name as the default name for that student */
int edit_name(int id, char *newname) {
    int index = get_index(id);
    if (index != -1) {
        arr[index].name = (char *) realloc(arr[index].name, strlen(newname) + 1);
        strcpy(arr[index].name, newname);
        return 1;
    } else
        return 0;
}

/* this function is for User mode that takes a new name and the index of that student as an input and it sets this name as the default name for him */
int edit_user_name(int index, char *newname) {

    if (index != -1) {
        arr[index].name = (char *) realloc(arr[index].name, strlen(newname) + 1);
        strcpy(arr[index].name, newname);
        return 1;
    } else
        return 0;
}


/* this function Checks the password entered to enter admin mode.it takes only the entered password as an input */
int admin_login(char *entered_pass) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {

        if (strcmp(entered_pass, adminpass) == 0) {
            counter = 0;
            return 1;
        } else {
            if (counter == 2) {
                printf("No more tries.");
                return 0;
            }
            printf("Wrong Password.Please try again:");
            counter++;
            scanf("%s", entered_pass);
            char *admin__pass = (char *) malloc(strlen(entered_pass) + 1);
            strcpy(admin__pass, entered_pass);
        }

    }
}


/* this function takes the id as an input & it returns the index of the student with that id if found */
int get_index(int id) {
    int index;
    for (int i = 0; i < 20; i++) {

        if (arr[i].id == id) {
            index = i;
            break;
        } else
            index = -1;
    }
    return index;

}

/* this function shows the records of all students on the system if there are any */
int view_all_records() {
    int flag = 0;

    for (int i = 0; i < 20; i++) {
        if (arr_counter[i] == 1) {
            printf("Student NO.%d : \nname : %s \nID : %d \ndegree: %d \nage: %d \ngender: %c\n\n", i, arr[i].name,
                   arr[i].id, arr[i].degree, arr[i].age, arr[i].gender);
            flag++;
        }

    }
    return flag;
}

/* this function takes the id of the student as an input & it removes the data of that student from the system */
void remove_student(int id) {
    int temp_id = get_index(id);
    if (temp_id != -1) {
        arr_counter[temp_id] = 0;
        free(arr[temp_id].name);
        arr[temp_id].name = NULL;
        arr[temp_id].id = 0;
        arr[temp_id].degree = 0;
        arr[temp_id].age = 0;
        arr[temp_id].gender = 0;
        free(arr[temp_id].password);
        arr[temp_id].password = NULL;
    } else {
        printf("There's no student with this ID registered in our system");
    }

}


/* this function is for admin mode only.it takes the id of a student as an input and it shows the records that student on the system if id matches */
void view_std_record(int id) {
    int index = get_index(id);
    if (index != -1) {
        printf("The Name : %s\n", arr[index].name);
        printf("The Password : %s\n", arr[index].password);
        printf("The Degree : %d\n", arr[index].degree);
        printf("The Id : %d\n", arr[index].id);
        printf("The Age : %d\n", arr[index].age);
        printf("The Gender : %c\n\n", arr[index].gender);
    } else
        printf("There's no student with this ID in our system.\n\n");
}


/* this function Checks the id & password entered to enter User mode.it takes the entered id & password as an input */
int user_login(int id, char *pass) {
    char entered_pass[30];
    int counter = 0, index = get_index(id);
    if (index != -1) {
        for (int i = 0; i < 3; i++) {
            if (strcmp(arr[index].password, pass) == 0) {
                return index;
            } else {
                if (counter == 2) {
                    printf("No more tries.");
                    return -1;
                }
                printf("Wrong Password.Please try again:");
                counter++;
                scanf("%s", entered_pass);
                *pass = (char *) malloc(strlen(entered_pass) + 1);
                strcpy(pass, entered_pass);
            }
        }
    }

}


/* this function is for user mode only .it takes the index of the user as an input and it shows his records */
void show_user_record(int index) {

    printf("The Name : %s\n", arr[index].name);
    printf("The Password : %s\n", arr[index].password);
    printf("The Degree : %d\n", arr[index].degree);
    printf("The Id : %d\n", arr[index].id);
    printf("The Age : %d\n", arr[index].age);
    printf("The Gender : %c\n", arr[index].gender);
}

/* This function checks if there's a room for another student on the system */
int check_availability() {
    int i;
    for (i = 0; i < 20; i++) {
        if (arr_counter[i] == 1)
            continue;
        else {
            return i;
        }
    }
    if (i == 20) {
        return -1;
    }

}