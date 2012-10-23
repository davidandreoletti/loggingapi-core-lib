//
//  SinkInterface.h
//  libloggingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_SINKS_SINKINTERFACE_H_
#define INCLUDE_LOGGINGAPI_SINKS_SINKINTERFACE_H_

#include <string>

namespace loggingapi {
namespace records { class RecordInterface; }
namespace formatters { class FormatterInterface; }
namespace sinks {

/**
 *  A Sink
 */
class SinkInterface {
 public:
    /**
     *  Destructor
     */
    virtual ~SinkInterface() = 0;

  /**
     * Logs a record to the sink
     * @param r A record. Callee does NOT own the pointer
     */
    virtual void log(records::RecordInterface* r) = 0;

  /**
     * Sets record formatter
     * @param f A formatter. Caller does NOT own the pointer.
     */
    virtual void setFormatter(formatters::FormatterInterface* f) = 0;

    /**
     * Gets name
     * @return Sink name
     */
    virtual std::string getName() = 0;

    /**
     * Sets sink name
     * @param name SInk name
     */
    virtual void setName(std::string name) = 0;

 private:
     /**
      * Sink name
      */
     std::string name_;
};

inline SinkInterface::~SinkInterface() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_SINKS_SINKINTERFACE_H_
