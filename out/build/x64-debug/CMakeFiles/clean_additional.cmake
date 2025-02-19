# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "ticketer\\CMakeFiles\\iFixAndTicket_autogen.dir\\AutogenUsed.txt"
  "ticketer\\CMakeFiles\\iFixAndTicket_autogen.dir\\ParseCache.txt"
  "ticketer\\iFixAndTicket_autogen"
  )
endif()
