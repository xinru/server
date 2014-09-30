#ifndef QY_STUDENT_H
#define QY_STUDENT_H

enum command {
    kListStudents,
    kAddStudent,
    kDelStudent,
    kSearchStudent
};

extern printStudents();
extern addStudent();
extern delStudent();
extern searchStudent();

#endif
