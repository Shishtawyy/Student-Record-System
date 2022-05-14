
/**/
/* Author        : Mohamed Shishtawy                         */
/* File          : Program.h                                 */
/* Date          : 5/8/2022                                  */
/* Version       : V01                                       */
/* GitHub        : https://github.com/Shishtawyy             */
/**/


#ifndef STUDENT_RECORD_SYSTEM_PROGRAM_H
#define STUDENT_RECORD_SYSTEM_PROGRAM_H

#endif //STUDENT_RECORD_SYSTEM_PROGRAM_H

#include "data.h"

char *set_admin_password();

int admin_login(char *entered_pass);

int user_login(int id, char *pass);

int edit_admin_pass(char *newpass);

void show_user_record(int id);

int edit_user_name(int index, char *newname);

int edit_user_pass(int index, char *newpass);

int get_index(int id);

int view_all_records();

void remove_student(int id);

int add_student(char *name, char *password, int degree, int id, int age, int gender);

int edit_grade(int degree, int id);

void view_std_record(int id);

int check_availability();

int edit_name(int id, char *newname);

