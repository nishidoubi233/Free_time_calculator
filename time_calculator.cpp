#include <iostream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    //得到当前系统时间
    auto now = chrono::system_clock::now();
    time_t start_time = chrono::system_clock::to_time_t(now);
    tm* start_tm = localtime(&start_time);
    
    cout << "当前时间: " << put_time(start_tm, "%Y-%m-%d %H:%M:%S") << endl;
    
    //得到结束时间的输入
    tm end_tm = *start_tm; 
    
    cout << "请输入目标结束时间：" << endl;
    cout << "年: ";
    cin >> end_tm.tm_year;
    end_tm.tm_year -= 1900; // tm_year的范围起始于1900年
    
    cout << "月 (1-12): ";
    int month;
    cin >> month;
    end_tm.tm_mon = month - 1; // tm_mon 的数值是0-11
    
    // 设置日期默认为1号。
    end_tm.tm_mday = 1;
    
    double study_hours, eating_hours, sleeping_hours, other_hours;
    
    cout << "平均每天学习时间 (小时): ";
    cin >> study_hours;
    
    cout << "平均每天吃饭时间 (小时): ";
    cin >> eating_hours;
    
    cout << "平均每天睡觉时间 (小时): ";
    cin >> sleeping_hours;
    
    cout << "平均每天洗漱等其他事情时间 (小时): ";
    cin >> other_hours;
    
    //计算总天数和总小时数
    time_t end_time = mktime(&end_tm);
    double diff_seconds = difftime(end_time, start_time);
    double total_days = diff_seconds / (60 * 60 * 24);
    double total_hours = diff_seconds / (60 * 60);
    
    //计算每天的不可用时间 
    double unavailable_hours_per_day = eating_hours + sleeping_hours + other_hours;
    
    //计算可用时间
    double available_hours = total_hours - (total_days * unavailable_hours_per_day);
    
    cout << fixed << setprecision(1);
    cout << "从现在到目标时间总共有 " << total_days << " 天 (" << total_hours << " 小时)" << endl;
    cout << "考虑每天的必要活动后，可用的自由安排时间为 " << available_hours << " 小时" << endl;
    
    return 0;
}
