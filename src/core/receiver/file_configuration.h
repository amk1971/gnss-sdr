/*!
 * \file file_configuration.h
 * \brief A ConfigurationInterface that reads the configuration from a file.
 * \author Carlos Aviles, 2010. carlos.avilesr(at)googlemail.com
 *
 * This implementation has a text file as the source for the values of the parameters.
 * The file is in the INI format, containing sections and pairs of names and values.
 * For more information about the INI format, see https://en.wikipedia.org/wiki/INI_file
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * -------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_FILE_CONFIGURATION_H
#define GNSS_SDR_FILE_CONFIGURATION_H

#include "configuration_interface.h"
#include <cstdint>
#include <memory>
#include <string>

class INIReader;
class StringConverter;
class InMemoryConfiguration;

/*!
 * \brief This class is an implementation of the interface ConfigurationInterface
 *
 * Derived from ConfigurationInterface, this class implements an interface
 * to a configuration file. This implementation has a text file as the source
 * for the values of the parameters.
 * The file is in the INI format, containing sections and pairs of names and values.
 * For more information about the INI format, see https://en.wikipedia.org/wiki/INI_file
 */
class FileConfiguration : public ConfigurationInterface
{
public:
    explicit FileConfiguration(std::string filename);
    FileConfiguration();
    ~FileConfiguration() = default;
    std::string property(std::string property_name, std::string default_value);
    bool property(std::string property_name, bool default_value);
    int64_t property(std::string property_name, int64_t default_value);
    uint64_t property(std::string property_name, uint64_t default_value);
    int32_t property(std::string property_name, int32_t default_value);
    uint32_t property(std::string property_name, uint32_t default_value);
    int16_t property(std::string property_name, int16_t default_value);
    uint16_t property(std::string property_name, uint16_t default_value);
    float property(std::string property_name, float default_value);
    double property(std::string property_name, double default_value);
    void set_property(std::string property_name, std::string value);

private:
    void init();
    std::string filename_;
    std::shared_ptr<INIReader> ini_reader_;
    std::shared_ptr<InMemoryConfiguration> overrided_;
    std::shared_ptr<StringConverter> converter_;
    int error_{};
};

#endif  // GNSS_SDR_FILE_CONFIGURATION_H
