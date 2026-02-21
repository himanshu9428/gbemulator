include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
#include_directories("/usr/local/include")
include_directories("/opt/homebrew/include")
link_directories(${CHECK_LIBRARY_DIRS})

message(STATUS "The value of CHECK_INCLUDE_DIRS is: ${MY_CHECK_INCLUDE_DIRS}")
message(STATUS "The value of CHECK_LIBRARIES is: ${CHECK_LIBRARIES}")
message(STATUS "The value of CHECK_LIBRARY_DIRS is: ${CHECK_LIBRARY_DIRS}")

set(TEST_SOURCES
  check_gbe.c
)

add_executable(check_gbe ${TEST_SOURCES})
target_link_libraries(check_gbe emu ${CHECK_LIBRARIES})
target_include_directories(check_gbe PRIVATE ${PROJECT_SOURCE_DIR}/include )


find_program(DEBIAN "dpkg")
if(DEBIAN)
    target_link_libraries(check_gbe check m rt pthread subunit)
endif()

if (WIN32)
target_include_directories(emu PUBLIC ${PROJECT_SOURCE_DIR}/../windows_deps/check )
endif()
