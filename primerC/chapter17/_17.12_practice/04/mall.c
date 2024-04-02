/**
 * 商业街排队问题, 用两个队列模拟两个摊位
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "queue.h"
#define MALLSIZE 2/*模拟摊位数量*/
#define MIN_PER_HOUR 60/*每小时多少分钟*/

/*使用结构定义摊位---全局变量*/
static struct {
    Queue line; /*为摊位指定一个排队队列*/
    int total_hours,cust_perhour;// 模拟的小时数, 每小时平均多少位顾客
    long cycle,cycleimit;// 循环计数器、计数器的上限
    /*
    turnaways:因队列已满被拒的顾客数量
    all_cust:加入队列的顾客数量
    served_cust:在模拟期间咨询过Sigmund的顾客数量
    sum_line:累计的队列总长
    line_wait:队列累计的等待时间
    */
    long turnaways,all_cust,served_cust,sum_line,line_wait;
    //turnaways = (all_cust = (served_cust = (sum_line = (line_wait = 0))));
    int wait_time;// 从当前到Sigmund空闲所需的时间
    double min_per_cust;// 顾客到来的平均时间
} malls[2];

/*是否有新顾客到来*/
bool newcustomer(double x);

/*设置顾客参数*/
Item setCustomerItem(long when);

int main(void)
{
    Item customer_temp; /*新顾客*/
    srand((unsigned int)time(0)); // rand() 随机初始化
    puts("Case Study:SigmundLander's Advice Booth");
    
    puts("Enter the number of simulation hours for the first mall:");
    scanf("%d",&malls[0].total_hours);//第一个摊位模拟总时长
    malls[0].cycleimit = MIN_PER_HOUR * malls[0].total_hours;//第一个摊位总的计数次数
    puts("Enter the average number of customers perhour for the first mall:");//第一个摊位每小时顾客流量
    scanf("%d", &malls[0].cust_perhour);
    malls[0].min_per_cust = MIN_PER_HOUR/malls[0].cust_perhour;//平均多久到来一个顾客
    
    puts("Enter the number of simulation hours for the second mall:");
    scanf("%d",&malls[1].total_hours);//第一个摊位模拟总时长
    malls[1].cycleimit = MIN_PER_HOUR * malls[1].total_hours;//第二个摊位总的计数次数
    puts("Enter the average number of customers perhour for the second mall:");//第二个摊位每小时顾客流量
    scanf("%d", &malls[1].cust_perhour);
    malls[1].min_per_cust = MIN_PER_HOUR/malls[1].cust_perhour;//平均多久到来一个顾客

    /*每个摊位每分钟循环一次*/
    for (int i = 0; i < 2; i++) {
        for (malls[i].cycle = 0; malls[i].cycle < malls[i].cycleimit; malls[i].cycle++) {
            if (newcustomer(malls[i].min_per_cust)) {
                // 如果队列已满, 新来的顾客直接离开
                if (QueueIsFull(&malls[i].line)) {
                    malls[i].turnaways++;
                }
                // 队列没有满, 新来的顾客进行排队
                else {
                    customer_temp = setCustomerItem(malls[i].cycle);
                    EnQueue(customer_temp, &malls[i].line);
                    malls[i].all_cust++;
                }
            }
            
            /*每分钟一个循环周期,都要检测 Sigmund 是否空闲*/
            if (malls[i].wait_time <= 0) {
                //空闲的情况下, 让队首的人出队享受咨询服务
                if (!QueueIsEmpty(&malls[i].line)) {
                    DeQueue(&customer_temp, &malls[i].line);
                    malls[i].wait_time = customer_temp.pocess_time;// Sigmund 又忙起来了, 重置 wait_time
                    malls[i].served_cust++;//咨询数+1
                    /*此处的customer_temp是从队列头部出队享受咨询服务的顾客*/
                    malls[i].line_wait += malls[i].cycle - customer_temp.arrive_time;
                }
            }
            /*如果当前 Sigmund 正在忙碌*/
            else if (malls[i].wait_time > 0) {
                malls[i].wait_time--;
            }
            
            malls[i].sum_line += QueueItemCount(&malls[i].line);  /*记录本次循环时队列的长度*/
        }
        
        /*单个摊位汇总统计*/
        if (malls[i].all_cust > 0) {
            printf("customers accepted:%ld\n", malls[i].all_cust);
            printf("customers served:%ld\n", malls[i].served_cust);
            printf("turn aways:%ld\n",  malls[i].turnaways);
            printf("average queue size:%.2f\n", (double)(malls[i].sum_line / malls[i].cycleimit));
            printf("average wait time:%.2f minutes\n", (double)( malls[i].line_wait / malls[i].served_cust));
        } else {
            printf("NO data for the %d mall.\n\n", i);
        }
        
        EmptyTheQueue(&malls[i].line);
    }
    
    
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
    customer.pocess_time = rand() % 3 + 1;/*每个顾客咨询时间1,2,3分钟时间不等*/
    return customer;
}