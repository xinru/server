#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include "student.h"

#define BUFSIZE    32
#define STUNUM     32

static long getInput(void)
{
    int result = -1;
    char buf[BUFSIZE] = {0};
    fgets(buf, BUFSIZE, stdin);
    result = strtol(buf, NULL, 0);
    if((result == 0 && errno == EINVAL) || errno == ERANGE)
    {
        result = -1;
        errno = 0;
    }
    return result;
}

static int getStudyID(void)
{
    int studyID = -1;
_InputStudyID:
    fprintf(stdout,"Please Input Student's studyID:\n");
    studyID = (int)getInput();
    if(studyID < MINSTUDYID || studyID > MAXSTUDYID)
    {
        fprintf(stderr,"Invaild Input!(StudyID Must in [2014000 - 2014999])");
        goto _InputStudyID;
    }
    return studyID;
}

int main(void)
{
    int cmd = -1;
    char stuName[NAMELEN] = {0};
    int age = -1;
    int studyID = -1;
    STU *stu = NULL;
    
    stu = allocStudentRecords(STUNUM);
    if(stu == NULL){
        exit(1);
    }

    while(1)
    {
        fprintf(stdout,"Please Input Command Number:\n0 - List\t1 - Add\t 2 - Delete\t3 - Search\t4 - Quit\n");
        cmd = getInput();
        if(cmd < 0 || cmd > 4)
        {
            fprintf(stderr,"Invalid Command!\n");
            continue;
        }      
        switch(cmd)
        {
            case 0:
                listStudents(stu);
                break;
            case 1:
                printf("Please Input student's Name:\n");
                fgets(stuName, NAMELEN, stdin);
                stuName[NAMELEN -1] = '\0';

_InputAge:
                printf("Please Input student's Age:\n");
                age = (int)getInput();
                if(age < MINAGE || age > MAXAGE)
                {
                    fprintf(stderr,"Invaild Input!(Age Must in [4 - 100])");
                    goto _InputAge;
                }

                studyID = getStudyID();
                addStudents(stu, stuName, age, studyID);
                break;
            case 2:
                studyID = getStudyID();
                delStudents(stu, studyID);
                break;
            case 3:
                studyID = getStudyID();
                searchStudents(stu, studyID);
                break;
            case 4:
                exit(1);
                break;
        } 
    }
    deallocStudentRecords(stu);
    return 0;
}
