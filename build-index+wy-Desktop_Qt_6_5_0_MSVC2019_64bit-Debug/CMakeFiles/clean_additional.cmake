# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\index_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\index_autogen.dir\\ParseCache.txt"
  "index_autogen"
  )
endif()
