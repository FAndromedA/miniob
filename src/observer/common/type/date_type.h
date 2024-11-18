// added by zhuangjinghao in 2024/11/18

#pragma once

#include "common/type/data_type.h"  

class Date_t 
{
public:
    Date_t(int date_int) : date_int(date_int) {}
    
    Date_t(const string &date_str) {
        int year, month, day;
        sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day);
        date_int = year * 10000 + month * 100 + day;
    }

    bool check_date() const {
        int year = date_int / 10000;
        int month = date_int / 100 % 100;
        int day = date_int % 100;
        int max_day = days_in_month[month];
        if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            max_day = 29;
        }
        if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > max_day) {
            return false;
        }
        return true;
    }

    int get_date_int() const {
        return date_int;
    }
    int get_year() const {
        return date_int / 10000;
    }
    int get_month() const {
        return date_int / 100 % 100;
    }
    int get_day() const {
        return date_int % 100;
    }

    bool operator==(const Date_t &rhs) const {
        return date_int == rhs.date_int;
    }

    bool operator<(const Date_t &rhs) const {
        return date_int < rhs.date_int;
    }
private:
    int date_int;
    constexpr static int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

/**
 * @brief 日期型数据类型
 * @ingroup DataType
 */
class DateType : public DataType 
{
public:
    DateType() : DataType(AttrType::DATES) {}
    virtual ~DateType() = default;
    
    int compare(const Value &left, const Value &right) const override;
    
    RC set_value_from_str(Value &val, const string &data) const override;
    
    RC to_string(const Value &val, string &result) const override;
};