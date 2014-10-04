#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/student.h"

static int numberOfStudents;

STU *allocStudentRecords(int number)
{
    STU *stu = NULL;
    int size = number * sizeof(STU);
    stu = malloc(size);
    if (stu == NULL) {
        perror("malloc");
        return NULL;
    }

    memset(stu, 0, size);
    numberOfStudents = number;
    return stu;
}

static void printStudent(STU *stu, int index)
{
    printf("Student's Name is [%s]\n", stu[index].name);
    printf("Student's Age is [%d]\n", stu[index].age);
    printf("Student's StudyID is [%d]\n", stu[index].studyID);
    printf("====================================\n");
}

void printStudents(STU *stu)
{
    for (int i = 0; i < numberOfStudents; i++) {
        if (stu[i].useFlag) {
            printStudent(stu, i);
        }
    }
}

// 检查学生学号是否冲突，冲突返回－1，不冲突返回0
static int checkStudyID(STU *stu, int studyID)
{
    for (int i = 0; i < numberOfStudents; i++) {
        if (studyID == stu[i].studyID 
                && stu[i].useFlag == 1) {
            return -1;
        }
    }

    return 0;
}

// 获取空闲位置索引
static int getFreePosition(STU *stu)
{
    for (int i = 0; i < numberOfStudents; i++) {
       if (stu[i].useFlag == 0) {
            return i;  
       } 
    }
    return -1;
}

int addStudent(STU *stu, char *name, int age, int studyID)
{
    int index = -1;
    // 1. 检查学号是否冲突
    if (checkStudyID(stu, studyID) < 0) {
        fprintf(stderr, "Student <%d> Already Exsist!\n", studyID);
        return -1;
    } 
    
    // 2. 找到空闲位置索引
    index = getFreePosition(stu);
    if (index < 0) {
        fprintf(stderr, "No Free Position to Add New Student!\n");
        return -1;
    }

    // 3. 根据传入的数据，进行相应赋值
    strncpy(stu[index].name, name, NAMELEN-1);
    stu[index].age = age;
    stu[index].studyID = studyID;
    stu[index].useFlag = 1;

    printf("Added Successfully!\n");
    return 0;
}

delStudent()
{

}

searchStudent()
{

}

void deallocStudentRecords(STU *stu)
{
    free(stu);
}
