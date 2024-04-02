/*
1.在拨打长途电话时，电话公司所保存的信息会包括拨打电话的日期和时间。它还包括3个电话号码：使用的那个电话、呼叫的那个电话以及付账的那个电话。这些电话号码的每一个都由3个部分组成：区号、交换台和站号码。请为这些记账信息编写一个结构声明。
*/
#define MAX_LEN 125

struct PHONE_INFO {
    unsigned int area_no;
    unsigned int exchange;
    unsigned int station;
};
struct DIAL_INFO {
    short month;
    short day;
    short year;
    int times;
    struct PHONE_INFO dail_out;
    struct PHONE_INFO dail_to;
    struct PHONE_INFO payment;
};