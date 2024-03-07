# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TCCreator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TCCreator_autogen.dir/ParseCache.txt"
  "TCCreator_autogen"
  )
endif()
