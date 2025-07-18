class Date
{
private:
    int _year;
    int _month;
    int _day;
public:
     int GetMonthDay(int year,int month){
        static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 
            31};
             int day = days[month];
             if (month == 2 
            &&((year % 4 == 0 && year % 100 != 0) || (year%400 == 0)))
             {
             day += 1;
             }
             return day;
     }
};
