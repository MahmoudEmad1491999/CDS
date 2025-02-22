# CMakeLists.txt for ArrayList Component
# This file defines the build configuration for the ArrayList library and its dependencies.

# Include the directory containing header files.
# This ensures that the compiler can find the header files during the build.
include_directories(${CMAKE_CURRENT_LIST_DIR}/inc/)

# Create an OBJECT library for ArrayList_Callout.
# OBJECT libraries are used to compile source files into object files without linking them into a full library.
# This is useful for reusing object files in multiple targets.
add_library(ArrayList_Callout OBJECT ${CMAKE_CURRENT_LIST_DIR}/src/ArrayList_Callout.c)


# Create a STATIC library for ArrayList.
# STATIC libraries are compiled into a single archive file (.a or .lib) that can be linked into other targets.
add_library(ArrayList STATIC ${CMAKE_CURRENT_LIST_DIR}/src/ArrayList.c)

# Add Include dir as a forced included file to the list of included dirs when using ArrayList Target.
target_include_directories(ArrayList PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc/)

# Link the ArrayList_Callout OBJECT library to the ArrayList STATIC library.
# This ensures that the object files from ArrayList_Callout are included in the final ArrayList library.
target_link_libraries(ArrayList ArrayList_Callout)

# Set compile options for the ArrayList library.
# Enable common warnings and treat them as errors to ensure high code quality.
target_compile_options(ArrayList PRIVATE -Wall -Wextra -Werror)

# Set C standard to C11 for the ArrayList library.
# This ensures that the code is compiled using the C11 standard.
set_property(TARGET ArrayList PROPERTY C_STANDARD 11)

# Add installation rules for the ArrayList library and headers.
# This allows the library to be installed system-wide or in a custom directory.
install(TARGETS ArrayList
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/inc/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")