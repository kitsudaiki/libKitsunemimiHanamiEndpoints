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
#include <endpoint_parsing/endpoint_parser_interface.h>

namespace Kitsunemimi
{
namespace Hanami
{

Endpoint* Endpoint::m_endpoints = nullptr;

/**
 * @brief Endpoint::Endpoint
 */
Endpoint::Endpoint() {}

/**
 * @brief Endpoint::~Endpoint
 */
Endpoint::~Endpoint() {}

/**
 * @brief get instance, which must be already initialized
 *
 * @return instance-object
 */
Endpoint*
Endpoint::getInstance()
{
    if(m_endpoints == nullptr) {
        m_endpoints = new Endpoint();
    }
    return m_endpoints;
}

/**
 * @brief parse endpoint-file content
 *
 * @param input input-string with endpoint-definition to parse
 * @param error reference for error-output
 *
 * @return true, if parsing was successfull, else false
 */
bool
Endpoint::parse(const std::string &input,
                ErrorContainer &error)
{
    if(input.size() == 0) {
        return false;
    }

    EndpointParserInterface* parser = EndpointParserInterface::getInstance();
    return parser->parse(&m_endpointRules, input, error);
}
/**
 * @brief Endpoint::checkUserAgainstEndpoint
 * @param id
 * @param type
 * @return
 */
bool
Endpoint::mapEndpoint(EndpointEntry &result,
                      const std::string &id,
                      const HttpRequestType type)
{
    std::map<std::string, std::map<HttpRequestType, EndpointEntry>>::const_iterator id_it;
    id_it = m_endpointRules.find(id);

    if(id_it != m_endpointRules.end())
    {
        std::map<HttpRequestType, EndpointEntry>::const_iterator type_it;
        type_it = id_it->second.find(type);

        if(type_it != id_it->second.end())
        {
            result.type = type_it->second.type;
            result.group = type_it->second.group;
            result.name = type_it->second.name;
            return true;
        }
    }

    return false;
}


}
}
