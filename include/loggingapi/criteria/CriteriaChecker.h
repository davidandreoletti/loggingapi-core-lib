//
//  CriteriaChecker.h
//  libloggingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_CRITERIA_CRITERIACHECKER_H_
#define INCLUDE_LOGGINGAPI_CRITERIA_CRITERIACHECKER_H_
#include <vector>

namespace loggingapi {
namespace attributes { class AttributeInterface; }

namespace criteria {

/**
 *  A basic criteria checker
 */
class CriteriaChecker {
 public:
    /**
     *  Check if record's values pass are equal or higher than expected values
     *  \param expectedFilters Filters containing expected values
     *  \param recordFilters Record filters
     *  \return True if for each filter key 
     *          (defined as loggingapi::attributes::AttributeInterface::getKey()) 
     *          in expectedFilters there is a matching filter key in 
     *          recordFilters AND expected filter value is lower or equal to 
     *          the record filter value (defined as loggingapi::attributes::
     *          AttributeValue::compare(const AttributeValueInterface &a) const)
     *          Also true IF there is no expected filters.
     */
    bool pass(const std::vector<attributes::AttributeInterface*>& expectedFilters,  // NOLINT(whitespace/line_length)
                            const std::vector<attributes::AttributeInterface*>& recordFilters);    // NOLINT(whitespace/line_length)
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_CRITERIA_CRITERIACHECKER_H_
