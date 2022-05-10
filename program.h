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

void remove_student(int index);



//Aya
int add_student(char* name,char* password,int degree,int id,int age,char gender);

void edit_grade(int index,int degree);

void view_std_record(int index);



//Raghad
int check_availability();

void edit_pass(int index);

void edit_name(int index);


