#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char* error_code;

enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };


#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x,err)  {error_code = #err; longjmp(buf, (x));}

void readFile() {
    printf("Read file...\n");
    THROW(FILE_ERROR, "Warning: file error ");
}

void networkOperation() {
    printf("network...\n");
    THROW(NETWORK_ERROR, "Warning : network error");
}

void calculateData() {
   printf("calculatedata...\n");
   THROW(CALCULATION_ERROR,"Warning: calculate error");
}

int main() {
    
     TRY {
        readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR) {
        printf("%s\n", error_code);} // Bổ sung thêm nhiều CATCH
    CATCH(NETWORK_ERROR){
        printf("%s\n", error_code);
    }
    CATCH(CALCULATION_ERROR){
        printf("%s\n", error_code);
    }
    // Các xử lý khác của chương trình
    return 0;
}
