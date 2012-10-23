//
//  ConsoleSink.h
//  libloggingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_SINKS_CONSOLESINK_H_
#define INCLUDE_LOGGINGAPI_SINKS_CONSOLESINK_H_

#include <string>
#include "loggingapi/sinks/SinkInterface.h"

namespace loggingapi {
namespace sinks {

/**
 *  A sink to console
 */
class ConsoleSink : public sinks::SinkInterface {
 public:
     // Inherits from SinkInterface
    virtual void log(records::RecordInterface* r);
    virtual std::string getName();
    virtual void setName(std::string name);
    virtual void setFormatter(formatters::FormatterInterface* f);

    /**
     *  Destructor
     */
    virtual ~ConsoleSink();

    /**
     *  Constructor
     */
    ConsoleSink();

 private:
    /**
     Sink name*/
    std::string name_;
    /**
     * SInk record formatter
     */
    formatters::FormatterInterface* formatter_;
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_SINKS_CONSOLESINK_H_
