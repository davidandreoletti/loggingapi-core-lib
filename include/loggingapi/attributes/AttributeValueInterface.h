//
//  AttributeValueInterface.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEVALUEINTERFACE_H_
#define INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEVALUEINTERFACE_H_

#include <string>

namespace loggingapi {
namespace attributes {

/**
 *  An attribute value
 */
class AttributeValueInterface {
 public:
     /**
      * Compare Results
      */
    enum CompareResult {
        COMPARE_RESULT_BIGGER,    /** Is bigger */
        COMPARE_RESULT_LESSER,    /** Is lesser */
        COMPARE_RESULT_EQUAL      /** Is equal */
    };

    /**
     *  Destructor
     */
    virtual ~AttributeValueInterface() = 0;

    /**
     *  Get string representation of the attribute value
     */
    virtual std::string getValueAsString() = 0;

    /**
     * Compare an attribute value to another
     * \param a Attribute value to compare to
     * \return COMPARE_RESULT_LESSER IF this attribute value is strictly smaller than the one in parameter
     *         COMPARE_RESULT_EQUAL IF both attribute value are equals.
     *         COMPARE_RESULT_BIGGER IF this attribute value is strictly greater than the one in parameter
     */
    virtual CompareResult compare(const ::loggingapi::attributes::AttributeValueInterface& a) const = 0;  // NOLINT(whitespace/line_length)
};

inline AttributeValueInterface::~AttributeValueInterface() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEVALUEINTERFACE_H_
