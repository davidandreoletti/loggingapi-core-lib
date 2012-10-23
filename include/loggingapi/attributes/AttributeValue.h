//
//  AttributeInterface.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEVALUE_H_
#define INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEVALUE_H_

#include <string>
#include <sstream>
#include "loggingapi/attributes/AttributeValueInterface.h"

namespace loggingapi {
namespace attributes {

/**
 *  An attribute value
 */
template <class valueT>
class AttributeValue: public AttributeValueInterface {
 public:
    // Inherited from AttributeValueInterface<valueT>
    virtual std::string getValueAsString() {
        std::ostringstream s;
        s << value_;
        return s.str();
    }

    /**
     * Gets the value
     * @return Value
     */
    valueT get() const {
        return value_;
    }

    /**
     * Constructor
     * @param v Value to hold
     */
    explicit AttributeValue(valueT v) : value_(v) {}

    virtual CompareResult compare(const ::loggingapi::attributes::AttributeValueInterface& a) const {  // NOLINT(whitespace/line_length)
        const ::loggingapi::attributes::AttributeValue<valueT>& a2 = static_cast<const ::loggingapi::attributes::AttributeValue<valueT>& >(a);  // NOLINT(whitespace/line_length)
        if (this->value_ > a2.get()) {return COMPARE_RESULT_BIGGER;}
        if (this->value_ < a2.get()) {return COMPARE_RESULT_LESSER;}
        return COMPARE_RESULT_EQUAL;
    }

    ~AttributeValue();

  private:
  	/**
  	 * Concrete value (eg: int)
  	 */
    valueT value_;
};

template <class valueT>
inline AttributeValue<valueT>::~AttributeValue() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEVALUE_H_
