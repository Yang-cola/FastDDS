// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file LoanableHelloWorld.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "LoanableHelloWorld.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

LoanableHelloWorld::LoanableHelloWorld()
{
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2b552920
    m_index = 0;
    // m_message com.eprosima.idl.parser.typecode.ArrayTypeCode@1f36e637
    memset(&m_message, 0, (256) * 1);

}

LoanableHelloWorld::~LoanableHelloWorld()
{


}

LoanableHelloWorld::LoanableHelloWorld(
        const LoanableHelloWorld& x)
{
    m_index = x.m_index;
    m_message = x.m_message;
}

LoanableHelloWorld::LoanableHelloWorld(
        LoanableHelloWorld&& x)
{
    m_index = x.m_index;
    m_message = std::move(x.m_message);
}

LoanableHelloWorld& LoanableHelloWorld::operator =(
        const LoanableHelloWorld& x)
{

    m_index = x.m_index;
    m_message = x.m_message;

    return *this;
}

LoanableHelloWorld& LoanableHelloWorld::operator =(
        LoanableHelloWorld&& x)
{

    m_index = x.m_index;
    m_message = std::move(x.m_message);

    return *this;
}

bool LoanableHelloWorld::operator ==(
        const LoanableHelloWorld& x) const
{

    return (m_index == x.m_index && m_message == x.m_message);
}

bool LoanableHelloWorld::operator !=(
        const LoanableHelloWorld& x) const
{
    return !(*this == x);
}

size_t LoanableHelloWorld::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((256) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t LoanableHelloWorld::getCdrSerializedSize(
        const LoanableHelloWorld& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((256) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    return current_alignment - initial_alignment;
}

void LoanableHelloWorld::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_index;
    scdr << m_message;


}

void LoanableHelloWorld::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_index;
    dcdr >> m_message;

}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void LoanableHelloWorld::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t LoanableHelloWorld::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& LoanableHelloWorld::index()
{
    return m_index;
}

/*!
 * @brief This function copies the value in member message
 * @param _message New value to be copied in member message
 */
void LoanableHelloWorld::message(
        const std::array<char, 256>& _message)
{
    m_message = _message;
}

/*!
 * @brief This function moves the value in member message
 * @param _message New value to be moved in member message
 */
void LoanableHelloWorld::message(
        std::array<char, 256>&& _message)
{
    m_message = std::move(_message);
}

/*!
 * @brief This function returns a constant reference to member message
 * @return Constant reference to member message
 */
const std::array<char, 256>& LoanableHelloWorld::message() const
{
    return m_message;
}

/*!
 * @brief This function returns a reference to member message
 * @return Reference to member message
 */
std::array<char, 256>& LoanableHelloWorld::message()
{
    return m_message;
}

size_t LoanableHelloWorld::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;





    return current_align;
}

bool LoanableHelloWorld::isKeyDefined()
{
    return false;
}

void LoanableHelloWorld::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
      
}
