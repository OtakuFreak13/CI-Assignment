workspace "CI-Assignment"
    architecture "x86"
    configurations { "Debug", "Release" }
    startproject "CI-Assignment"
    systemversion "latest"
    targetdir ("bin/%{prj.name}/%{cfg.longname}")
	objdir ("obj/%{prj.name}/%{cfg.longname}")

project "CI-Assignment"
    location "CI-Assignment"
    kind "ConsoleApp"
    staticruntime "On"
    language "c++"
    files  { "%{prj.location}/src/**.cpp", "%{prj.location}/src/**.h" }

project "Tests"
    location "Tests"
    kind "ConsoleApp"
    language "c++"
    files  { "%{prj.location}/src/**.cpp", "%{prj.location}/src/**.h" }
    links {
        "CI-Assignment", "GoogleTest"
    }
    includedirs {
        "googletest/googletest/include", "CI-Assignment" 
    }

project "GoogleTest"
    kind "staticLib"
    files "googletest/googletest/src/gtest-all.cc"
    includedirs {
        "googletest/googletest/include", "googletest/googletest/"
    }
