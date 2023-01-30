# experimental Scons "makefile" for fft programs

cflags_list = ["-Wall", "-g"]
include_path = ["/usr/local/include"]
lib_list = ["m"]
lib_path = ["/usr/local/lib"]

source_list = ["test_main.cpp", "read_profile.cpp", "utilities.cpp"]

Program( target="test", source=source_list,
		CC="gcc", CCFLAGS=cflags_list, CPPPATH=include_path,
		LIBS=lib_list, LIBPATH=lib_path )
