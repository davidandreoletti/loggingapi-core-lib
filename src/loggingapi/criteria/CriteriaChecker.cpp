//
//  CriteriaChecker.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "./loggingapi/loggers/Logger.h"
#include "./loggingapi/attributes/AttributeInterface.h"
#include "./loggingapi/sinks/SinkInterface.h"
#include "./loggingapi/records/RecordInterface.h"

namespace loggingapi {
namespace criteria {

typedef attributes::AttributeInterface AttrI;
typedef attributes::AttributeValueInterface AttrVI;

/**
 * Function object to check if first attribute is bigger than the second one
 */
struct PassFilters : public std::binary_function<AttrI*, AttrI*, bool> {
    /**
 * Checks if first attribute is bigger than the second one
 * @param a First attribute
 * @param b Second attribute
 * @return True if first attribute is bigger than the second one
 */
    bool operator()(AttrI* a, AttrI* b) const {
        return a->getKey().compare(b->getKey()) == 0 &&
        a->getValue()->compare(*(b->getValue())) == AttrVI::COMPARE_RESULT_BIGGER;  // NOLINT(whitespace/line_length)
    }
};

bool CriteriaChecker::pass(const std::vector<AttrI*>& expectedFilters,
                         const std::vector<AttrI*>& recordFilters) {
    if (expectedFilters.size() == 0) {
        // No filtering
        return true;
    }

    typedef std::vector<AttrI*> VectorFilters;
    VectorFilters::const_iterator eit = expectedFilters.begin();
    bool filterPassed = false;
    do {
        VectorFilters::const_iterator rit;
        rit = std::find_if(recordFilters.begin(),
                           recordFilters.end(),
                           std::bind2nd(PassFilters(), *eit));
        filterPassed = (rit != recordFilters.end());
        ++eit;
    } while (filterPassed && eit != expectedFilters.end());
    return filterPassed;
}

}}  // namespaces
