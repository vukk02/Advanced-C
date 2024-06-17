#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char* error_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x,err)  {error_code = #err; longjmp(buf, (x));}


double divide(int a, int b) {
    if (b == 0) {
        THROW(1,"Loi: Phep chia cho 0!"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    THROW(2, "Loi: Nhung loi khac!");
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 5;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
       printf("%s\n", error_code);
    }CATCH(2) {
       printf("%s\n", error_code);
}


    // Các xử lý khác của chương trình
    return 0;
}
