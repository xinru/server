#ifndef QY_STUDENT_H
#define QY_STUDENT_H

#define NAMELEN    32
#define MINAGE     4
#define MAXAGE     100
#define MINSTUDYID 2014000
#define MAXSTUDYID 2014999

typedef struct student{
    char name[NAMELEN];
    int age;
    int studyID;
    int useFlag;
}STU;

extern STU *allocStudentRecords(int number);
extern void listStudents(STU *);
extern int addStudents(STU *stu, char *name, int age, int studyID);
extern int delStudents(STU *stu, int studyID);
extern int searchStudents(STU *stu, int studyID);
extern void deallocStudentRecords(STU *);

#endif
