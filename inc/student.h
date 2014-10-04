#ifndef QY_STUDENT_H
#define QY_STUDENT_H

#define NAMELEN     32
#define MINAGE      4
#define MAXAGE      100
#define MINSTUDYID  20140001
#define MAXSTUDYID  20149999

typedef struct student {
    char name[NAMELEN];
    int age;
    int studyID;
    int useFlag; /*0:unuse 1:using*/
} STU;

enum command {
    kListStudents,
    kAddStudent,
    kDelStudent,
    kSearchStudent,
    kQuitCMD,
};

extern STU *allocStudentRecords(int number);
extern void printStudents(STU *stu);
extern int addStudent(STU *stu, char *name, int age, int studyID);
extern delStudent();
extern searchStudent();
extern void deallocStudentRecords(STU *);

#endif
