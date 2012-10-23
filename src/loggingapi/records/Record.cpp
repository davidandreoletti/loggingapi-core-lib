//
//  Record.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include "loggingapi/records/Record.h"
#include "loggingapi/attributes/Attribute.h"
#include "loggingapi/attributes/AttributeInterface.h"

namespace loggingapi {
namespace records {

Record::~Record() {
    // Delete attributes
    int attrsCount = attrs_.size();
    for (int i = 0; i < attrsCount ; i++) {
        delete attrs_[i];
    }
}

typedef ::loggingapi::attributes::AttributeInterface AttrI;

/**
 * Function object to get an attribute by name
 */
struct GetAttributeByName : public std::binary_function<AttrI*, std::string, bool> {  // NOLINT(whitespace/line_length)
    /**
 * Gets an attribute by name
 * @param a Attribute
 * @param name Requested name
 * @return True if attribute has requested name
 */
    bool operator()(AttrI* a, const std::string name) const {
        return name.compare(a->getKey()) == 0;
    }
};

bool Record::addAttribute(attributes::AttributeInterface* attr) {
    if (attr == NULL) {return false;}
    if (this->getAttribute(attr->getKey()) != NULL) {return false;}
    this->attrs_.push_back(attr);
    return true;
}

attributes::AttributeInterface* Record::removeAttribute(const std::string& name) {  // NOLINT(whitespace/line_length)
    std::vector<AttrI*>::iterator it;
    // Search for attribute with requested name
    it = std::find_if(this->attrs_.begin(),
                      this->attrs_.end(),
                      std::bind2nd(GetAttributeByName(), name));
    if (it != this->attrs_.end()) {
        // Attribute found, remove it from attributes
        this->attrs_.erase(it);
        return *it;
    }
    return NULL;
}

attributes::AttributeInterface* Record::getAttribute(const std::string& name) const {  // NOLINT(whitespace/line_length)
    std::vector<AttrI*>::const_iterator it;
    it = std::find_if(this->attrs_.begin(),
                      this->attrs_.end(),
                      std::bind2nd(GetAttributeByName(), name));
    return (it != this->attrs_.end()) ? *it : NULL;
}
std::vector<attributes::AttributeInterface*> Record::getAttributes() const {
    return std::vector<attributes::AttributeInterface*>();
}

}}  // namespaces
