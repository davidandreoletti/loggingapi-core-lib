//
//  Record.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_RECORDS_RECORD_H_
#define INCLUDE_LOGGINGAPI_RECORDS_RECORD_H_

#include <string>
#include <vector>
#include "loggingapi/records/RecordInterface.h"

namespace loggingapi {
namespace attributes { class AttributeInterface; }
namespace records {

/**
 *  A record
 */
class Record : public RecordInterface {
 public:
    // Inherited from RecordInterface
    virtual ~Record();
    virtual bool addAttribute(attributes::AttributeInterface* attr);
    virtual attributes::AttributeInterface* removeAttribute(const std::string& name);  // NOLINT(whitespace/line_length)
    virtual attributes::AttributeInterface* getAttribute(const std::string& name) const;  // NOLINT(whitespace/line_length)
    virtual std::vector<attributes::AttributeInterface*> getAttributes() const;  // NOLINT(whitespace/line_length)

 private:
     /**
      * Record's attributes
      */
     std::vector<attributes::AttributeInterface*> attrs_;
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_RECORDS_RECORD_H_
