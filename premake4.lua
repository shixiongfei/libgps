-- A solution contains projects, and defines the available configurations
solution ( "gps" )
	configurations { "Release", "Debug" }

	if _ACTION == "clean" then
		os.rmdir("bin")
	end

	-- A project defines one build target
	project ( "gps" )
		kind ( "StaticLib" )
		--kind ( "ConsoleApp" )
		language ( "C" )
		files { "**.h", "**.c" }
		excludes { "test.c" }
		flags { "StaticRuntime" }

		configuration ( "Release" )
			targetdir ( "bin" )
			objdir ( "obj/rlz" )
			defines { "NDEBUG", "_NDEBUG" }
			flags { "Optimize" }

		configuration ( "Debug" )
			targetdir ( "bin" )
			objdir ( "obj/dbg" )
			defines { "DEBUG", "_DEBUG" }
			flags { "Symbols" }
			targetsuffix ( "d" )
		
		configuration ( "vs*" )
			defines { "WIN32", "_WIN32", "_WINDOWS", "_CRT_SECURE_NO_WARNINGS", "_CRT_SECURE_NO_DEPRECATE", "_CRT_NONSTDC_NO_DEPRECATE" }

		configuration ( "gmake" )
			defines { "LINUX_OR_MACOSX" }

		configuration { "gmake", "macosx" }
			defines { "__APPLE__", "__MACH__", "__MRC__", "macintosh", }

		configuration { "gmake", "linux" }
			defines { "__linux__" }

