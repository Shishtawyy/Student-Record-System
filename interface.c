

/**/
/* Author        : Mohamed Shishtawy                         */
/* File          : Interface.c                               */
/* Date          : 5/8/2022                                  */
/* Version       : V01                                       */
/* GitHub        : https://github.com/Shishtawyy             */
/**/


//interface of the program with all the choices & navigation
//
//there will be 2 functions (admin_mode) & ( user_mode  ) which will have the functions called inside them
//

#include "interface.h"
#include "program.h"

/* This function initializes the system & allows the User to choose between modes */

void system_init() {
    set_admin_password();
    int mode_choice = 0;
    printf("Welcome to Ravenclw's School System.\n");
    while (1) {
        printf("Please enter the number of the mode you want to sign in with:\n");
        printf("1 - Admin Mode.\n2 - User Mode.\n3 - Exit\n");
        scanf("%d", &mode_choice);
        if (mode_choice == 1) {
            char entered_pass[30];
            printf("Please enter the password to enter the Admin's mode:");
            scanf("%s", entered_pass);
            char *admin__pass = (char *) malloc(strlen(entered_pass) + 1);
            strcpy(admin__pass, entered_pass);
            if (admin_login(admin__pass)) {
                printf("Welcome to the Admin Mode.\n");
                admin_mode();
            } else {
                exit(1);
            }
        } else if (mode_choice == 2) {
            int user_entered_id;
            char entered_pass[30];
            printf("Please enter your ID:");
            scanf("%d", &user_entered_id);
            printf("Please enter your password:");
            scanf("%s", &entered_pass);
            char *user__pass = (char *) malloc(strlen(entered_pass) + 1);
            strcpy(user__pass, entered_pass);
            int temp = user_login(user_entered_id, user__pass);
            if (temp != -1) {
                printf("Welcome to the User Mode.\n");
                user_mode(temp);
            } else {
                exit(1);
            }
        } else if (mode_choice == 3) {
            printf("Thanks for using the system,Goodbye.\n");
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
}

/* This Function gets the user into the system as an admin*/

void admin_mode() {
    while (1) {
        int option_choice = 0;
        printf("--------------------------------------------------------------------\n");
        printf("1 - Add a student to the system.\n");
        printf("2 - Remove a student from the system.\n");
        printf("3 - Edit the grade of a student.\n");
        printf("4 - Show the records of all students on the system.\n");
        printf("5 - Show the record of a specific student on the system.\n");
        printf("6 - Edit the name of the student on the system.\n");
        printf("7 - Edit the password of the admin.\n");
        printf("8 - Return to mode selection.\n");
        printf("9 - Exit\n");
        printf("--------------------------------------------------------------------\n");
        printf("Please enter the number of what you want to do:\n");
        scanf("%d", &option_choice);

        if (option_choice == 1) {
            if (check_availability() != -1) {
                char name[30];
                char password[30];

                int degree = 0, id = 0, age = 0, gender = 0;
                printf("Please enter the student's name :\n");
                scanf("%s", name);
                printf("Please enter the student's password :\n");
                scanf("%s", password);
                printf("Please enter the student's degree out of 100 :\n");
                scanf("%d", &degree);
                printf("Please enter the student's ID :\n");
                scanf("%d", &id);
                printf("Please enter the student's age :\n");
                scanf("%d", &age);
                printf("Please enter 1 if the student is a MALE or enter 2 if the student is a FEMALE:\n");
                scanf("%d", &gender);
                add_student(name, password, degree, id, age, gender);

            } else {
                printf("Sorry , There's no room for a new student in our system.\n");
            }
        } else if (option_choice == 2) {
            int entered_id;
            printf("Please enter the id of the student you wish to remove his data from the system:\n");
            scanf("%d", &entered_id);
            remove_student(entered_id);
            printf("Student removed successfully\n");
        } else if (option_choice == 3) {
            int entered_id, entered_degree;
            printf("Please enter the id of the student you want to Edit his grades:\n");
            scanf("%d", &entered_id);
            printf("Please enter the new degree of the student :\n");
            scanf("%d", &entered_degree);
            if (edit_grade(entered_degree, entered_id)) {
                printf("Degree modified successfully\n");
            } else {
                printf("Sorry an error has occurred\n");
            }
        } else if (option_choice == 4) {
            printf("--------------------------------------------------------------------------------\n");
            printf("---------------------------Students record Table--------------------------------\n");
            printf("--------------------------------------------------------------------------------\n");
            if (view_all_records()) {

            } else {
                printf("There are no students in the system.\n\n");
            }
        } else if (option_choice == 5) {
            int entered_id;
            printf("Please enter the id of the student you wish to show his records:\n");
            scanf("%d", &entered_id);
            printf("--------------------------------------------------------------------------------\n");
            printf("----------------------------Student record Table--------------------------------\n");
            printf("--------------------------------------------------------------------------------\n\n");
            view_std_record(entered_id);
        } else if (option_choice == 6) {
            int entered_id;
            char new_name[30];
            printf("Please enter the id of the student you wish to edit his name:\n");
            scanf("%d", &entered_id);
            printf("Please enter the new name of the student you wish to edit his name:\n");
            scanf("%s", new_name);
            edit_name(entered_id, new_name);
            printf("Name changed successfully\n");
        } else if (option_choice == 7) {
            char new_pass[30];
            printf("Please enter the new password of the admin:\n");
            scanf("%s", new_pass);
            if (edit_admin_pass(new_pass)) {
                printf("New password has been set successfully\n");
            } else {
                printf("Sorry, an error has occurred\n");
            }
        } else if (option_choice == 8) {
            break;
        } else if (option_choice == 9) {
            exit(0);
        } else {
            printf("Invalid Option.");
        }
    }
}

/* This Function gets the user into the system as an User*/

void user_mode(int index) {
    while (1) {
        int option_choice = 0;

        printf("--------------------------------------------------------------------\n");
        printf("1 - Show your record.\n");
        printf("2 - Edit your name.\n");
        printf("3 - Edit your password.\n");
        printf("4 - Return to mode selection.\n");
        printf("5 - Exit.\n");
        printf("--------------------------------------------------------------------\n");
        printf("Please enter the number of what you want to do:\n");
        scanf("%d", &option_choice);

        if (option_choice == 1) {
            show_user_record(index);
        } else if (option_choice == 2) {
            char new_name[30];
            printf("Please enter your new name:\n");
            scanf("%s", new_name);
            edit_user_name(index, new_name);
            printf("Name changed successfully\n");
        } else if (option_choice == 3) {
            char new_pass[30];
            printf("Please enter your new password:\n");
            scanf("%s", new_pass);
            edit_user_pass(index, new_pass);
            printf("Password changed successfully\n");
        } else if (option_choice == 4) {
            break;
        } else if (option_choice == 5) {
            exit(0);
        } else {
            printf("Invalid Option.");
        }


    }
}