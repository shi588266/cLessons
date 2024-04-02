/**
 * 商业街排队问题
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "queue.h"
#define MIN_PER_HOUR 60

/*是否有新顾客到来*/
bool newcustomer(double x);

/*设置顾客参数*/
Item setCustomerItem(long when);


int main(void)
{
    Queue line;
    Item customer_temp; /*新顾客*/
    int total_hours;// 模拟的小时数
    int customers_perhour;// 每小时平均多少位顾客
    long cycle, cyclelimit;// 循环计数器、计数器的上限
    long turnaways = 0;// 因队列已满被拒的顾客数量
    long customers = 0;// 加入队列的顾客数量
    long served = 0;// 在模拟期间咨询过Sigmund的顾客数量
    long sum_line = 0;//累计的队列总长
    int wait_time = 0;// 从当前到Sigmund空闲所需的时间
    double min_per_cust;// 顾客到来的平均时间
    long line_wait = 0;// 队列累计的等待时间
    
    InitializeQueue(&line);
    
    srand((unsigned int)time(0)); // rand() 随机初始化
    puts("Case Study:SigmundLander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d",&total_hours);
    cyclelimit = MIN_PER_HOUR * total_hours;
    
    puts("Enter the average number of customers perhour:");
    scanf("%d", &customers_perhour);
    min_per_cust = MIN_PER_HOUR/customers_perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            // 如果队列已满, 新来的顾客直接离开
            if (QueueIsFull(&line)) {
                turnaways++;
            } 
            // 队列没有满, 新来的顾客进行排队
            else {
                customer_temp = setCustomerItem(cycle);
                EnQueue(customer_temp, &line);
                customers++;
            }
        }
        
        /*每分钟一个循环周期,都要检测 Sigmund 是否空闲*/
        if (wait_time <= 0) {
            //空闲的情况下, 让队首的人出队享受咨询服务
            if (!QueueIsEmpty(&line)) {
                DeQueue(&customer_temp, &line);
                wait_time = customer_temp.pocess_time;// Sigmund 又忙起来了, 重置 wait_time
                served++;//咨询数+1
                line_wait += cycle - customer_temp.arrive_time;
            }
        }
        
        /*如果当前 Sigmund 正在忙碌*/
        if (wait_time > 0) {
            wait_time--;
        }
        
        sum_line += QueueItemCount(&line);  /*记录本次循环时队列的长度*/
    }
    
    if (customers > 0) {
        printf("customers accepted:%ld\n", customers);
        printf("customers served:%ld\n", served);
        printf("turn aways:%ld\n", turnaways);
        printf("average queue size:%.2f\n", (double)(sum_line/cyclelimit));
        printf("average wait time:%.2f minutes\n", (double)(line_wait/served));
    } else {
        puts("NO data");
    }
    
    EmptyTheQueue(&line);
    puts("Bye!");
    return 0;
}
/*是否有新顾客到来*/
bool newcustomer(double x)
{
    /*
        x是顾客到来的平均时间(单位: 分钟)
        如果1分钟内有顾客到来，则返回true
    */
    return (rand() * x / RAND_MAX < 1);
}

/*设置顾客参数*/
Item setCustomerItem(long when)
{
    Item customer;
    customer.arrive_time = when;
    customer.pocess_time = rand() % 3 + 1;
    return customer;
}