//
//  RecordInterface.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_RECORDS_RECORDINTERFACE_H_
#define INCLUDE_LOGGINGAPI_RECORDS_RECORDINTERFACE_H_

#include <string>
#include <vector>

namespace loggingapi {
namespace attributes { class AttributeInterface; }
namespace records {

/**
 *  A log record
 */
class RecordInterface {
 public:
    /**
     *  Destructor
     */
    virtual ~RecordInterface() = 0;

    /**
     * Adds an attribute. Once successfully added, the caller does NOT own the pointer.
     * \param attr An attribute
     * \return True if attribute was successfully added. Attribute successfully added if and only if
     * record does NOT contain the attribute.
     */
    virtual bool addAttribute(attributes::AttributeInterface* attr) = 0;

    /**
     * Removes an attribute
     * \param name Attribute name
     * \return Attribute instance associated to name. NULL if no attribute found. Caller owns returned attribute.
     */
    virtual attributes::AttributeInterface* removeAttribute(const std::string& name) = 0;  // NOLINT(whitespace/line_length)

    /**
     * Gets an attribute
     * \param name Attribute name
     * \return Attribute for requested attribute name.
     */
    virtual attributes::AttributeInterface* getAttribute(const std::string& name) const = 0;  // NOLINT(whitespace/line_length)

    /**
     * Gets all attributes
     * \return Level.
     */
    virtual std::vector<attributes::AttributeInterface*> getAttributes() const = 0;  // NOLINT(whitespace/line_length)
};

inline RecordInterface::~RecordInterface() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_RECORDS_RECORDINTERFACE_H_
