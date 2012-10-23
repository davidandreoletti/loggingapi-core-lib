//
//  FormatterInterface.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_FORMATTERS_FORMATTERINTERFACE_H_
#define INCLUDE_LOGGINGAPI_FORMATTERS_FORMATTERINTERFACE_H_

#include <string>

namespace loggingapi {
namespace records { class RecordInterface; }
namespace formatters {

/**
 *  A Formatter
 */
class FormatterInterface {
 public:
    /**
     *  Destructor
     */
    virtual ~FormatterInterface() = 0;

    /**
     * Formats a record
     * \param r A record. Caller owns the pointer.
     * \return Formatted record string
     */
    virtual std::string format(const records::RecordInterface* r) const = 0;
};

inline FormatterInterface::~FormatterInterface() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_FORMATTERS_FORMATTERINTERFACE_H_
