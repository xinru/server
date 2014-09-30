#include <stdio.h>

int main(void)
{
    // 

    while (1) {
        // 1. 提示用户输入命令
        fprintf(stderr, "Please Input Command Number:\n0 - List\t1 - Add \t2 - Delete\t3 - Search\t4 - Quit\n");

        // 2. 接收用户输入的命令(怀疑用户的输入,也就是对用户输入进行检查)
        
        // 3. 匹配用户输入的命令，执行相应的操作
        switch (command) {
            case kListStudents:
                printStudents();
                break;
            case kAddStudent:
                //
                addStudent();
                break;
            case kDelStudent:
                delStudent();
                break;
            case kSearchStudent:
                searchStudent();
                break;
            default:
                fprintf(stderr, "Unknown Command!\n");
                break;
        }

    }
    return 0;
}
