# BÀI 1: COMPILER - MACRO
## 1. COMPILER
![1](https://github.com/vukk02/Advanced-C/assets/126554839/690852f7-b754-41d6-8df1-b4d1fa31ee2c)
1. Giai đoạn tiền xử lý – Preprocessor
Giai đoạn này sẽ thực hiện:

Nhận mã nguồn
Xóa bỏ tất cả chú thích, comments của chương trình
Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.

2. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly

Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

3. Công đoạn dịch Assembly

Dich chương trình => Sang mã máy 0 và 1
Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

4. Giai đoạn Linker

Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
Tạo ra file .exe

## 2. MACRO
Macro là từ dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý ( Preprocessor). Chia làm 3 nhóm chính:

#include

#define, #undef

#if, #elif, #else, #ifdef, #ifndef

1. Chỉ thị tiền xử lý #include: dùng để chèn nội dung của một file vào mã nguồn chương trình.
   
2. Chỉ thị tiền xử lý #define

```c

#include <stdio.h>

// Macro để tính bình phương của một số
#define SQUARE(x) ((x) * (x))

int main() {

    
    // Sử dụng macro để tính bình phương của num
    int result = SQUARE(5);

    printf("Result is: %d\n", result);

    return 0;
}

```

```c

#include <stdio.h>

#define DISPLAY_SUM(a,b)	\
printf("This is macro to sum 2 number\n");	\
printf("Result is: %d", a+b);

int main() {
    
    DISPLAY_SUM(5,6)

    return 0;
}

```

Chỉ thị tiền xử lý #undef: dùng để hủy định nghĩa của một macro đã được định nghĩa trước đó bằng #define

```c
#include <stdio.h>

// Định nghĩa SENSOR_DATA 
#define SENSOR_DATA 42

int main() {
    printf("Value of MY_MACRO: %d\n", MY_MACRO);

    // Hủy định nghĩa SENSOR_DATA 
    #undef SENSOR_DATA 
    // Định nghĩa SENSOR_DATA 
    #define SENSOR_DATA 50

    printf("Value of MY_MACRO: %d\n", MY_MACRO);

    return 0;
}

```

3.Chỉ thị tiền xử lý #if, #elif, #else
- #if sử dụng để bắt đầu một điều kiện tiền xử lý.
- Nếu điều kiện trong #if là đúng, các dòng mã nguồn sau #if sẽ được biên dịch
- Nếu sai, các dòng mã nguồn sẽ bị bỏ qua đến khi gặp #endif
- #elif dùng để thêm một điều kiện mới khi điều kiện trước đó trong #if hoặc #elif là sai
- #else dùng khi không có điều kiện nào ở trên đúng.

```c
#include <stdio.h>

typedef enum
{
    GPIOA,
    GPIOB,
    GPIOC
} Ports;

typedef enum
{
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} Pins;

typedef enum
{
    HIGH,
    LOW
} Status;

#define STM32 0
#define ATMEGA 1
#define PIC 2

#define MCU STM32

#if MCU == STM32
void daoTrangThaiDen(Ports port, Pins pin, Status status)
{
    if (status == HIGH)
    {
        HAL_GPIO_WritePin(port, pin, LOW);
    }
    else
    {
        HAL_GPIO_WritePin(port, pin, HIGH);
    }  
}
#elif MCU == ATMEGA
void daoTrangThaiDen(Pins pin, Status status)
{
    if (status == HIGH)
    {
        digitalWrite(pin, LOW);
    }
    else
    {
        digitalWrite(pin, HIGH);
    }  
}

#endif

void delay(int ms)
{

}


int main()
{
    while(1)
    {
        daoTrangThaiDen(GPIOA,13,HIGH);
        delay(1000);
    }

    return 0;
```
Chỉ thị tiền xử lý #ifdef, #ifndef

- #ifdef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
- #ifndef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch

```c
#ifndef __ABC_H
#define __ABC_H

int a = 10;

#endif
```
# Bài 2: STDARG - ASSERT
## STDARG
Header file có tên stdarg.h trong Thư viện C định nghĩa một kiểu biến va_list và 3 macro mà có thể được sử dụng để lấy các tham số trong một hàm khi số tham số là chưa được biết (ví dụ như số tham số là có thể biến đổi).

- va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
- va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
- va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

![stdarg](https://github.com/vukk02/Advanced-C/assets/126554839/89cfef93-b138-48c1-a9b9-279b7d17d3a5)

input

```c
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TURN_ON,
    TURN_OFF,
    SET_LEVEL,
    SEND_MESSAGE
} CommandType;

void sendCommand(CommandType command, ...) {
    va_list args;
    va_start(args, command);

    switch (command) {
        case TURN_ON:
        case TURN_OFF: {
            int deviceID = va_arg(args, int);
            printf("Command: %s Device ID: %d\n", command == TURN_ON ? "Turn On" : "Turn Off", deviceID);
            break;
        }
        case SET_LEVEL: {
            int deviceID = va_arg(args, int);
            int level = va_arg(args, int);
            printf("Set Level of Device ID %d to %d\n", deviceID, level);
            break;
        }
        case SEND_MESSAGE: {
            char* message = va_arg(args, char*);
            printf("Send Message: %s\n", message);
            break;
        }
    }

    va_end(args);
}

int main() {
    sendCommand(TURN_ON, 1);
    sendCommand(TURN_OFF, 2);
    sendCommand(SET_LEVEL, 3, 75);
    sendCommand(SEND_MESSAGE, "Hello World");
    return 0;
}
```
output
```c
Command: Turn On Device ID: 1
Command: Turn Off Device ID: 2
Set Level of Device ID 3 to 75
Send Message: Hello World
```
## ASSERT
- Cung cấp macro assert. 
- Macro này được sử dụng để kiểm tra một điều kiện. 
- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
- Dùng trong debug, dùng #define NDEBUG để tắt debug

![assert](https://github.com/vukk02/Advanced-C/assets/126554839/d43c6613-1a59-40ad-ba4e-1bd8a582e71f)
```c
// Macro dùng để debug
#define LOG(condition, cmd) assert(condition && #cmd)
```

# Bài 3: Pointer
con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác

Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch.

## Void Pointer
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

```c
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}


```
```c
value is: 5
value is: 15.700000
value is: A
sum: 11
value: 5
value: e
```

## Function Pointer
Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.

Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

```c
#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```
```c
Hello!
Bonjour!
```
```c
#include <stdio.h>

void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
}

void calculator(void (*ptr)(int, int), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}


int main()
{
    calculator(sum,5,2);
    calculator(subtract,5,2);
    calculator(multiple,5,2);
    calculator(divide,5,2);

    //void (*ptr[])(int, int) = {sum, divide, multiple};
    //ptr[0](5,6);

    return 0;
}
```

```c
Program calculate: 
Sum of 5 and 2 is: 7
Program calculate:
Subtract of 5 by 2 is: 3
Program calculate:
Multiple of 5 and 2 is: 10
Program calculate:
5 divided by 2 is: 2.500000
```
## Pointer to Constant
Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

Cú pháp:
```c
int const *ptr_const; 
const int *ptr_const;
```
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int value = 5;
    int test = 8;
    int const *ptr_const = &value;

    //*ptr_const = 7; // wrong
    //ptr_const = &test; // right
    
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);

    return 0;
```
```c
value: 5
value: 9
```
## Constant Pointer
Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.

Cú pháp:
```c
int *const const_ptr = &value;

```
## Pointer to Pointer
Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.

```c
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);

    printf("dereference ptr2 second time: %d\n", **ptr2);

    return 0;
}
```
```c
address of value: 0000001cdefff744
value of ptr1: 0000001cdefff744
address of ptr1: 0000001cdefff738
value of ptr2: 0000001cdefff738
dereference ptr2 first time: 0000001cdefff744
dereference ptr2 second time: 42
```
## NULL Pointer
Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.

```c
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
    

    return 0;
}

```
```c
Pointer is NULL
```







   

