// added by zhuangjinghao in 2024/11/18

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/date_type.h"
#include "values.h"
#include "common/lang/limits.h"
#include "common/value.h"

int DateType::compare(const Value &left, const Value &right) const
{
    ASSERT(left.attr_type() == AttrType::DATES, "left type is not date");
    ASSERT(right.attr_type() == AttrType::DATES, "right type is not date");
    int left_value = left.get_date().get_date_int();
    int right_value = right.get_date().get_date_int();
    return common::compare_int((void *)&left_value, (void *)&right_value);
}

RC DateType::set_value_from_str(Value &val, const string &data) const
{
    Date_t tmp_test = Date_t(data);
    if (!tmp_test.check_date())
    {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
    val.set_date(Date_t(data));
    return RC::SUCCESS;
}

RC DateType::to_string(const Value &val, string &result) const
{
    char *buf = new char[16];
    sprintf(buf, "%04d-%02d-%02d", val.get_date().get_year(), val.get_date().get_month(), val.get_date().get_day());
    result = buf;
    return RC::SUCCESS;
}