/**
 * @file        policy.h
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

#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <string>
#include <map>
#include <libKitsunemimiHanamiCommon/enums.h>

namespace Kitsunemimi
{
class DataMap;
namespace Hanami
{
class Endpoint_Test;

struct EndpointEntry
{
    ObjectType type = BLOSSOM_TYPE;
    std::string path = "";
};

class Endpoint
{
public:
    Endpoint();
    ~Endpoint();

    bool parse(const std::string &input, std::string &errorMessage);

    bool checkUserAgainstEndpoint(const std::string &component,
                                  const std::string &endpoint,
                                  const std::string &group);

private:
    std::map<std::string, std::map<uint8_t, EndpointEntry>> m_endpointRules;

    friend Endpoint_Test;
};

}
}

#endif // ENDPOINT_H
