// Write a program to store student details like usn,name and mobile number (using structures )
#include <stdio.h>

 struct Student{
        char usn[10];
        char* name;
        char* mobile_no;
    } s1;

int main() {
   struct Student s1 = {"1BM23CS467", "raja", "9644525452"};
   struct Student s2 = {"1BM23CS247", "gaja", "9185527452"};
   
   printf("S1 \nUSN: %s \nName: %s \nMobile_no: %s \n", s1.usn, s1.name , s1.mobile_no);
   printf("s2 \nUSN: %s \nName: %s \nMobile_no: %s \n", s2.usn, s2.name , s2.mobile_no);
    return 0;
}
