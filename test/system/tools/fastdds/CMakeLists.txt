# Copyright 2020 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

###########################################################################
# Create tests                                                            #
###########################################################################

find_package(PythonInterp 3 REQUIRED)

if(PYTHONINTERP_FOUND)

    set(TESTS
        test_fastdds_installed
        test_fastdds_discovery
        test_ros_discovery
        test_fastdds_shm
        test_fastdds_xml_validate
    )

    foreach(TEST IN LISTS TESTS)
        add_test(
                NAME system.tools.fastdds.${TEST}
                COMMAND ${PYTHON_EXECUTABLE}
                ${CMAKE_CURRENT_SOURCE_DIR}/tests.py
                ${CMAKE_INSTALL_PREFIX}
                ${TEST}
            )

        # Set test properties
        set_property(
            TEST system.tools.fastdds.${TEST}
            PROPERTY LABELS "NoMemoryCheck"
        )

    endforeach()

endif()

###############################################################################
# XML validation
###############################################################################
message(STATUS "Configuring CLI xml validation...")

# Copy the neccessary files over to the build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileAll.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileAll.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileDataReader.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileDataReader.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileDataWriter.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileDataWriter.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileDomainParticipant.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileDomainParticipant.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileTransportDescriptor.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileTransportDescriptor.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileLog.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileLog.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/profileTypes.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileTypes.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../xmlvalidation/XMLTesterExample.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/XMLTesterExample.xml COPYONLY)


# Check XML profile validation against schema

if (MSVC)

    # WINDOWS
    add_test(NAME xml.validate COMMAND fastdds.bat xml validate xmldocuments)

else()

    # POSIX
    add_test(NAME xml.validate COMMAND fastdds xml validate xmldocuments)

endif()
