#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

static int numberOfStudents;

STU *allocStudentRecords(int number)
{
    STU *stu = NULL;
    int size = number * sizeof(stu);
    stu = malloc(size);
    if(stu == NULL)
    {
        perror("malloc");
        return NULL;
    }
    memset(stu, 0, size);
    numberOfStudents = number;
    return stu;
}
static void printStudent(STU *stu, int index)
{
    printf("Student's studyID\tName\t\tAge\n");
    printf("%8d\t%-32s\t\t%d\n", stu[index].studyID, stu[index].name, stu[index].age);
    printf("--------------------------------\n");
}

void listStudents(STU *stu)
{
    for(int i = 0; i < numberOfStudents; i++)
    {
        if(stu[i].useFlag)
            printStudent(stu, i);
    }
}

int addStudents(STU *stu, char *name, int age, int studyID)
{
    int index;
    for(int i = 0; i < numberOfStudents; i++)
    {
        if(stu[i].useFlag == 1 && studyID == stu[i].studyID)
        {
            fprintf(stderr,"Student <%d> is exit!\n",studyID);
            return -1;
        }
        if(stu[i].useFlag == 0)
            index = i;
    }
    strncpy(stu[index].name, name, NAMELEN-1);
    stu[index].age = age;
    stu[index].studyID = studyID;
    stu[index].useFlag = 1;

    printf("Added Successfully!");
    return 0;
}
int delStudents(STU *stu, int studyID)
{
    for(int i = 0; i < numberOfStudents; i++)
    {
        if(stu[i].studyID == studyID && stu[i].useFlag)
        {
            stu[i].useFlag = 0;
            printf("Deleted Successfully!");
            return 0;
        }
    }
    printf("Student is not Exit!\n");
    return -1;
}
int searchStudents(STU *stu, int studyID)
{
    for(int i = 0; i < numberOfStudents; i++)
    {
        if(stu[i].studyID == studyID && stu[i].useFlag)
        {
            printStudent(stu, i);
            printf("Searched Successfully!");
            return 0;
        }
    }
    printf("Student is not Exit!\n");
    return -1;
}
void deallocStudentRecords(STU *stu)
{
    free(stu);
}
