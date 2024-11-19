// added by zhuangjinghao on 2024/11/18

#include "sql/operator/update_logical_operator.h"

UpdateLogicalOperator::UpdateLogicalOperator(Table *table, Value *values, FieldMeta *field_meta)
    : table_(table), values_(values), field_meta_(field_meta)
{}