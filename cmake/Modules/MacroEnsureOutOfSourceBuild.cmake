MACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD _errorMessage)

   string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" _insource)
   if (_insource)
     message(SEND_ERROR "${_errorMessage}")
     message(FATAL_ERROR "Remove CMakeCache.txt and CMakeFiles/ in ${CMAKE_SOURCE_DIR} first.")
   endif (_insource)

ENDMACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD)
