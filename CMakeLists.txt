cmake_minimum_required(VERSION 3.14)

project(test)

set(CMAKE_CXX_STANDARD 14)


######## libraries with mentioning .cpp files only #########
add_library(mylib                                  external_lib/subtract.cpp)

######## libraries with mentioning both .cpp and .hpp files #########
add_library(mathy      include/sum.hpp             src/sum.cpp)


# make cmake to search in include folder if it not found any include files
include_directories(include)

add_executable(test src/main.cpp)
target_link_libraries(test mathy)





add_executable(app src/app.cpp)

#options
	# option easy but not usually used
		# make cmake to search in external_lib folder for targer app only if it not found any include files
		# and add any missing .hpp files if needed from external_lib
		target_include_directories(app   PUBLIC    external_lib)

	# option that is recommended
		# make cmake to search in external_lib folder for all targets that link to the library
		# and add any missing .hpp files if needed from external_lib
		#target_include_directories (mylib INTERFACE external_lib)

target_link_libraries(app mylib)
target_link_libraries(app mathy)



#"PUBLIC"    applies include directories and compile options      to both the library and any targets that link to it
#"INTERFACE" applies include directories and compile options only to targets that link to the library.

