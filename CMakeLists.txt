PROJECT(To_Do_List C)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# where to look for cmake modules, before ${CMAKE_ROOT}/Modules/ is checked
SET(CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/cmake/Modules/
)

# add definitions
INCLUDE(DefineCMakeDefaults)
INCLUDE(DefinePlatformDefaults)
INCLUDE(DefineCompilerFlags)
INCLUDE(DefineOptions.cmake)

# disallow in-source build
INCLUDE(MacroEnsureOutOfSourceBuild)
MACRO_ENSURE_OUT_OF_SOURCE_BUILD("${PROJECT_NAME} requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(doc)

# if UNIT_TESTING is ON in DefineOptions.cmake, add tests dir
if(UNIT_TESTING)
        ENABLE_TESTING()
        ADD_SUBDIRECTORY(tests)
endif()
