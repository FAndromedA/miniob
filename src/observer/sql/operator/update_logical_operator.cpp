// added by zhuangjinghao on 2024/11/18

#include "sql/operator/update_logical_operator.h"

UpdateLogicalOperator::UpdateLogicalOperator(Table *table, Value *values)
    : table_(table), values_(values)
{}