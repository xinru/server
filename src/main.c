#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../inc/student.h"

#define BUFSIZE         32
#define STUNUM          32

/*
 * 将用户的输入转换成long类型，并返回转换结果
 * 返回 －1 代表转换失败
 */
static long getInput(void)
{
    char buf[BUFSIZE] = {0};
    long result = -1;

    fgets(buf, BUFSIZE, stdin);
    result = strtol(buf, NULL, 0);
    if ((result == 0 && errno == EINVAL)
            || (errno == ERANGE)) {
        result = -1;
        errno = 0;
    }

    return result;
}

static int getStudyID(void)
{
    int studyID = -1;
_InputStudyID:
    fprintf(stdout, "Please Input Student's Study ID:\n");
    studyID = (int)getInput();
    if (studyID < MINSTUDYID || studyID > MAXSTUDYID) {
        fprintf(stderr, "Invalid Input!(Study ID Must in [20140001-20149999])\n"); 
            goto _InputStudyID;
    }
    return studyID;
}

int main(void)
{
    long cmd = -1;
    char stuName[NAMELEN] = {0};
    int stuAge = -1;
    int studyID = -1;
    STU *stu = NULL;

    // 为学生记录申请内存并初始化
    stu = allocStudentRecords(STUNUM);
    if (NULL == stu) {
        goto _Fail;    
    }

    while (1) {
        // 1. 提示用户输入命令
        fprintf(stdout, "Please Input Command Number:\n0 - List\t1 - Add \t2 - Delete\t3 - Search\t4 - Quit\n");

        // 2. 接收用户输入的命令:(怀疑用户的输入,也就是对用户输入进行检查)
        cmd = getInput();
        fpurge(stdin);
        if (cmd == -1 || cmd > kQuitCMD || cmd < kListStudents) {
            fprintf(stderr, "Invalid Command!\n");
            continue;
        }        
        
        // 3. 匹配用户输入的命令，执行相应的操作
        switch (cmd) {
            case kListStudents:
                printStudents(stu);
                break;
            case kAddStudent:
                fprintf(stdout, "Please Input Student's Name:\n");
                fgets(stuName, NAMELEN, stdin);
                stuName[strlen(stuName)-1] = '\0';

_InputAge:
                fprintf(stdout, "Please Input Student's Age:\n");
                stuAge = (int)getInput();
                if (stuAge < MINAGE || stuAge > MAXAGE) {
                    fprintf(stderr, "Invalid Input!(Age Must in [4-100])\n"); 
                    goto _InputAge;
                }

                studyID = getStudyID(); 
                addStudent(stu, stuName, stuAge, studyID);
                break;
            case kDelStudent:
                studyID = getStudyID();
                delStudent(stu, studyID);
                break;
            case kSearchStudent:
                studyID = getStudyID();
                searchStudent(stu, studyID);
                break;
            case kQuitCMD:
                goto _Exit;
                break;
            default:
                fprintf(stderr, "Can't go here! Unknown Command!\n");
                break;
        }

    }

_Fail:
    exit(1);
_Exit:
    deallocStudentRecords(stu);
    return 0;
}
