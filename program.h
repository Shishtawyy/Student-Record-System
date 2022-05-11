//
// Created by Shishtawy on 5/8/2022.
//

#ifndef STUDENT_RECORD_SYSTEM_PROGRAM_H
#define STUDENT_RECORD_SYSTEM_PROGRAM_H

#endif //STUDENT_RECORD_SYSTEM_PROGRAM_H

int user_login(int id,char* pass);

int admin_login(int pass);





//Shishtawy
int get_index(int id);

void view_all_records();

void remove_student(int id);



//Aya
int add_student(char* name,char* password,int degree,int id,int age,char gender);

void edit_grade(int id,int degree);

void view_std_record(int id);



//Raghad
int check_availability();

void edit_pass(int id);

void edit_name(int id);


