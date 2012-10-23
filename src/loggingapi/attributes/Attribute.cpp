//
//  Attribute.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include "loggingapi/attributes/Attribute.h"
#include "loggingapi/attributes/AttributeValueInterface.h"

namespace loggingapi {
namespace attributes {

Attribute::Attribute() {
    this->key_ = "";
    this->value_ = NULL;
}

Attribute::~Attribute() {
    delete this->value_;
}

std::string Attribute::getKey() const {
    return this->key_;
}

void Attribute::setKey(std::string k) {
    this->key_ = k;
}

AttributeValueInterface* Attribute::getValue() const {
    return this->value_;
}

void Attribute::setValue(AttributeValueInterface* v) {
    this->value_ = v;
}

bool Attribute::equals(const AttributeInterface& a) const {
    return (this->key_.compare(a.getKey()) == 0
            &&
            this->value_->compare(*(a.getValue())) ==
            AttributeValueInterface::COMPARE_RESULT_EQUAL);
}

}}  // namespaces
