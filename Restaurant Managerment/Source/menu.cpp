


#include "../Header/menu.hpp"

void menu( manager ma, staff st)
{   
    cout<<"   Restaurant managerment\n\n";
    while(1)
    {
        int option ;
        int table;
        again:
        PRINT_MENU("Manager","Staff","exit");
        cin>>option;
        HANDLE_OPTION(option,
            CASE_OPTION(1, goto manager)
            CASE_OPTION(2, goto staff)
            CASE_OPTION(0, exit(1))
        );
        manager:
        cout<<"   Manager\n\n";
        PRINT_MENU("Set up table","Add dish","Update dish","Delete dish","List of dishes", "Back");
        cin>>option;
        HANDLE_OPTION(option,
            CASE_OPTION(1, ma.settable(); st.resizeTables(ma.gettable()))
            CASE_OPTION(2, ma.adddish())
            CASE_OPTION(3, ma.updatedish())
            CASE_OPTION(4, ma.deletedish())
            CASE_OPTION(5, ma.list_dish())
            CASE_OPTION(0, goto again)
        );
        goto manager;
        staff:
        st.setmenu(ma.getMenu());
        cout<<"   Staff\n\n";
        cout<<"Num_table\t";
        for (int i = 1; i <= ma.gettable(); ++i)
        (
            cout<<i<<"\t"
        );
        cout<<endl;
        cout<<"Status   \t";
        for (int i = 1; i <= ma.gettable(); ++i)
        (
            cout<<st.getstatus(i-1)<<"\t"
        );
        cout<<endl;
        cout<<"x: in service\n";
        cout<<"o: empty\n";
        cout<<"---------------"<<endl;
        cout<<"Select table: ";cin>>table;
        st.setnumtable(table-1);
        PRINT_MENU("Order","Cancle","List of ordered","Checkout", "Back");
        cin>>option;
        HANDLE_OPTION(option,
            CASE_OPTION(1, st.order())
            CASE_OPTION(2, st.cancle())
            CASE_OPTION(3, st.list_ordered())
            CASE_OPTION(4, st.checkout())
            CASE_OPTION(0, goto again)
        );
        goto staff;

        


    }
}