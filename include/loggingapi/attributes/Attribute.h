//
//  \file Attribute.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTE_H_
#define INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTE_H_

#include <string>
#include "loggingapi/attributes/AttributeInterface.h"
#include "loggingapi/attributes/AttributeValueInterface.h"

namespace loggingapi {
namespace attributes {

/**
 *  An atribute
 */
class Attribute : public AttributeInterface {
 public:
    // Inherited from AttributeInterface
    virtual std::string getKey() const;
    virtual void setKey(std::string k);
    virtual AttributeValueInterface* getValue() const;
    virtual void setValue(AttributeValueInterface* v);
    virtual bool equals(const AttributeInterface& a) const;

    /**
     *  Destructor
     */
    virtual ~Attribute();

    /**
     *  Constructor
     */
    Attribute();

 private:
    std::string key_;
    AttributeValueInterface* value_;
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTE_H_
