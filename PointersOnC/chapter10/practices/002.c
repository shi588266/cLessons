/*
2.为一个信息系统编写一个声明，用于记录每个汽车零售商的销售情况。每份销售记录必须包括下列数据。字符串值的最大长度不包括其结尾的NUL字节。

*/

#define CUST_NAME_MAX_LEN 21
#define CUST_ADDR_MAX_LEN 21
#define MODEL_MAX_LEN 21
#define BANK_NAME_MAX_LEN 21

struct FULL_CASH {
    float manuf_sugg_price;     //生产厂家建议零售价
    float actual_selling_price; //实际售出价格
    float sales_tax;            //营业税
    float licensing_fee;            //许可费用
};

struct RENT {
    float manuf_sugg_price;     //生产厂家建议零售价
    float actual_selling_price;     //实际售出价格
    float down_payment;     //预付定金
    float security_deposit;     //安全抵押
    float monthly_payment;     //月付金额
    int lease_term;     //租赁期限
};

struct LOAN {
    float manuf_sugg_price;         //生产厂家建议零售价(manufacturer’s suggested retail price) 
    float actual_selling_price;         //实际售出价格(actual selling price) 
    float sales_tax;         //营业税(sales tax) 
    float licensing_fee;            //许可费用
    float down_payment;            //预付定金(doun payment) float
    int loan_duration;            //贷款期限(loan duration) int
    float interest_rate;            //贷款利率(interest rate) float
    float monthly_payment;            //月付金额(interest rate) float
    char bank_name[BANK_NAME_MAX_LEN];            //银行名称(name of bank) string(20)
};

struct AUTO_SALSE_INFO {
    char cust_name[CUST_NAME_MAX_LEN];      //顾客名字
    char cust_addr[CUST_ADDR_MAX_LEN];      //顾客地址
    char model[MODEL_MAX_LEN];              //模型
    enum {FULL_CASH,RENT,LOAN} sales_type;  //销售时可能出现3种不同类型的交易：全额现金销售、贷款销售和租赁
    union {
        struct FULL_CASH *full_cash_info;
        struct RENT *rent_info;
        struct LOAN *loan_info;
    } record;
};