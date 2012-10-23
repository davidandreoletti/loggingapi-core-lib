//
//  Formatter.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_FORMATTERS_FORMATTER_H_
#define INCLUDE_LOGGINGAPI_FORMATTERS_FORMATTER_H_

#include <string>
#include <vector>
#include "loggingapi/formatters/FormatterInterface.h"

namespace loggingapi {
namespace records { class RecordInterface; }
namespace attributes { class AttributeInterface; }
namespace formatters {

/**
 *  A formatter
 */
class Formatter : public FormatterInterface {
 public:
    // Inherited from FormatterInterface
    virtual ~Formatter();
    virtual std::string format(const records::RecordInterface* r) const;

 private:
     /**
      * Record's attributes
      */
     std::vector<attributes::AttributeInterface*> attrs_;
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_FORMATTERS_FORMATTER_H_
