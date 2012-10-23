//
//  AttributeInterface.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEINTERFACE_H_
#define INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEINTERFACE_H_

#include <string>
#include "loggingapi/attributes/AttributeValueInterface.h"

namespace loggingapi {
namespace attributes {

/**
 *  An attribute interface
 */
class AttributeInterface {
 public:
    /**
     *  Destructor
     */
    virtual ~AttributeInterface() = 0;

    /**
     *  Gets key
     */
    virtual std::string getKey() const = 0;

    /**
     *  Sets key
     */
    virtual void setKey(std::string k) = 0;

    /**
     *  Gets value
     */
    virtual AttributeValueInterface* getValue() const = 0;

    /**
     *  Sets value
     *  \param v Attribute value
     */
    virtual void setValue(AttributeValueInterface* v) = 0;

    /**
     * Compare an attribute to another
     * \param a Attribute to compare to
     * \return True IF and ONLY IF:
     *         - getKey().compare(a.getKey()) == 0
     *         - getValue().compare(a.getValue()) == AttributeValueInterface::COMPARE_RESULT_EQUAL
     */
    virtual bool equals(const AttributeInterface& a) const = 0;
};

inline AttributeInterface::~AttributeInterface() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTEINTERFACE_H_
