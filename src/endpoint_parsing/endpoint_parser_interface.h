/**
 * @file        endpoint_parser_interface.h
 *
 * @author      Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 * @copyright   Apache License Version 2.0
 *
 *      Copyright 2021 Tobias Anker
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#ifndef POLICY_PARSER_INTERFACE_H
#define POLICY_PARSER_INTERFACE_H

#include <iostream>
#include <mutex>
#include <stdint.h>
#include <map>

namespace Kitsunemimi
{
namespace Hanami
{
class location;
struct EndpointEntry;

class EndpointParserInterface
{

public:
    static EndpointParserInterface* getInstance();
    ~EndpointParserInterface();

    // connection the the scanner and parser
    void scan_begin(const std::string &inputString);
    void scan_end();
    bool parse(std::map<std::string, std::map<uint8_t, EndpointEntry>>* result,
               const std::string &inputString,
               std::string &errorMessage);
    const std::string removeQuotes(const std::string &input);

    std::map<std::string, std::map<uint8_t, EndpointEntry>>* m_result = nullptr;
    std::map<uint8_t, EndpointEntry> tempEndpoint;

    // Error handling.
    void error(const location &location,
               const std::string& message);

private:
    EndpointParserInterface(const bool traceParsing = false);

    static EndpointParserInterface* m_instance;

    std::string m_errorMessage = "";
    std::string m_inputString = "";
    std::mutex m_lock;

    bool m_traceParsing = false;
};

}  // namespace Endpoint
}  // namespace Kitsunemimi

#endif // POLICY_PARSER_INTERFACE_H
