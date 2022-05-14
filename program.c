//
// Created by Shishtawy on 5/8/2022.
//
//all the functions
#include "program.h"

static struct student arr[20];
int arr_counter[20];

char *adminpass;


char *set_admin_password() {
    adminpass = (char *) malloc(strlen("1234") + 1);
    strcpy(adminpass, "1234");

}

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

int edit_admin_pass(char *newpass) {
    adminpass = (char *) realloc(adminpass, strlen(newpass) + 1);
    strcpy(adminpass, newpass);
    if (strcmp(adminpass, newpass) == 0)
        return 1;
    else
        return 0;
}

int edit_user_pass(int index, char *newpass) {
    arr[index].password = (char *) realloc(arr[index].password, strlen(newpass) + 1);
    strcpy(arr[index].password, newpass);
    if (strcmp(arr[index].password, newpass) == 0)
        return 1;
    else
        return 0;
}

int edit_name(int id, char *newname) {
    int index = get_index(id);
    if (index != -1) {
        arr[index].name = (char *) realloc(arr[index].name, strlen(newname) + 1);
        strcpy(arr[index].name, newname);
        return 1;
    } else
        return 0;
}

int edit_user_name(int index, char *newname) {

    if (index != -1) {
        arr[index].name = (char *) realloc(arr[index].name, strlen(newname) + 1);
        strcpy(arr[index].name, newname);
        return 1;
    } else
        return 0;
}

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


void view_all_records() {
    for (int i = 0; i < 20; i++) {
        if (arr_counter[i] == 1) {
            printf("Student NO.%d : \nname : %s \nID : %d \ndegree: %d \nage: %d \ngender: %c\n", i, arr[i].name,
                   arr[i].id, arr[i].degree, arr[i].age, arr[i].gender);

        }

    }
}


void remove_student(int id) {
    int temp_id = get_index(id);
    if (temp_id != -1) {
        arr_counter[temp_id]=0;
        free_dynamic(arr[temp_id].name);
        arr[temp_id].id = 0;
        arr[temp_id].degree = 0;
        arr[temp_id].age = 0;
        arr[temp_id].gender = 0;
        free_dynamic(arr[temp_id].password);
    } else {
        printf("There's no student with this ID registered in our system");
    }

}

void view_std_record(int id) {
    int index = get_index(id);
    if (index != -1) {
        printf("The Name : %s\n", arr[index].name);
        printf("The Password : %s\n", arr[index].password);
        printf("The Degree : %d\n", arr[index].degree);
        printf("The Id : %d\n", arr[index].id);
        printf("The Age : %d\n", arr[index].age);
        printf("The Gender : %c\n", arr[index].gender);
    } else
        printf("There's no student with this ID in our system");
}

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

void free_dynamic(void **ptr) {
    if (*ptr != NULL && ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }

}

/*int edit_student_pass (int id,char * newpass)
{  int index =get_index(id);
    if (index != -1)
    {
        arr[index].password = (char *)realloc(arr[index].password,strlen(newpass)+1);
        strcpy(arr[index].password,newpass);
        return 1;
    }
    else
        return 0;

}
*/


void show_user_record(int index) {

    printf("The Name : %s\n", arr[index].name);
    printf("The Password : %s\n", arr[index].password);
    printf("The Degree : %d\n", arr[index].degree);
    printf("The Id : %d\n", arr[index].id);
    printf("The Age : %d\n", arr[index].age);
    printf("The Gender : %c\n", arr[index].gender);
}

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