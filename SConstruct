# Experimental Scons "makefile" for experimental ellipse-fitting programs

cflags_list = ["-Wall", "-g", "-std=c++11"]
include_path = ["/usr/local/include"]
# Note that we can probably do without FFTW3 if we convert xxx to standard malloc/free
lib_list = ["m", "cfitsio", "fftw3", "fftw3_threads"]
lib_path = ["/usr/local/lib"]

source_list_profile_analyze = ["test_profile_analysis_main.cpp", "read_profile.cpp", "utilities.cpp"]

source_list_profile_generate = ["test_profile_generation_main.cpp", "commandline_parser.cpp", 
"image_io.cpp", "utilities.cpp"]

Program( target="profile_analyze", source=source_list_profile_analyze,
		CC="gcc", CCFLAGS=cflags_list, CPPPATH=include_path,
		LIBS=lib_list, LIBPATH=lib_path )

Program( target="profile_generate", source=source_list_profile_generate,
		CC="gcc", CCFLAGS=cflags_list, CPPPATH=include_path,
		LIBS=lib_list, LIBPATH=lib_path )
