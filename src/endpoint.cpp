/**
 * @file        endpoint.cpp
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

#include <libKitsunemimiHanamiEndpoints/endpoint.h>

#include <libKitsunemimiCommon/common_items/data_items.h>
#include <endpoint_parsing/endpoint_parser_interface.h>

namespace Kitsunemimi
{
namespace Hanami
{

/**
 * @brief Endpoint::Endpoint
 */
Endpoint::Endpoint() {}

/**
 * @brief Endpoint::~Endpoint
 */
Endpoint::~Endpoint() {}

/**
 * @brief parse endpoint-file content
 *
 * @param input input-string with endpoint-definition to parse
 * @param errorMessage reference for the output of the error-message
 *
 * @return true, if parsing was successfull, else false
 */
bool
Endpoint::parse(const std::string &input,
              std::string &errorMessage)
{
    EndpointParserInterface* parser = EndpointParserInterface::getInstance();

    // parse ini-template into a json-tree
    if(input.size() > 0) {
        parser->parse(&m_endpointRules, input, errorMessage);
    } else {
        return false;
    }

    return true;
}

/**
 * @brief check if request is allowed by endpoint
 *
 * @param component name of the requested component
 * @param endpoint requested endpoint of the component
 * @param group group which has to be checked
 *
 * @return true, if check was successfully, else false
 */
bool
Endpoint::checkUserAgainstEndpoint(const std::string &component,
                                   const std::string &endpoint,
                                   const std::string &group)
{
    DataItem* item = nullptr;

    return false;
}


}
}
