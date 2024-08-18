#include "../Header/menu.hpp"
#include "../Header/student.hpp"

void menu(StudentManager sv)
{
    while(1)
    {
        int option ;
        PRINT_MENU("Add student ","Update student's information ","Delete student","Find student",
        "Sort student","Display all the list of students","Save in file database_sv.csv","Back");
    
        cin>>option;

        HANDLE_OPTION(option,
            CASE_OPTION(1, sv.addStudent())
            CASE_OPTION(2, sv.updateStudent())
            CASE_OPTION(3, sv.deleteStudent())
            CASE_OPTION(4, sv.findstudent())
            CASE_OPTION(5, sv.sort())
            CASE_OPTION(6, sv.displayAllStudents())
            CASE_OPTION(7, sv.saveincsv())
            CASE_OPTION(0, exit(1))
        
        );
    }
}