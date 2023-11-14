workspace "Divbox2D"
    startproject "Sandbox"
    architecture "x64"
    configurations { "Debug", "Release" }

    flags
	{
		"MultiProcessorCompile"
	}

group "Dependencies"
    include "vendor/GLFW"
	include "vendor/Glad"

group ""

project "Divbox2D"
    location "../Divbox2D"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("bin" .. "/%{prj.name}")
    objdir("bin-int" .. "/%{prj.name}")

    pchheader "Utils.h"
    pchsource "Divbox2D/Utils.cpp"


    files {
        "../Divbox2D/Divbox2D/**.cpp",
        "../Divbox2D/Divbox2D/**.h"
    }


    includedirs
    {
        "%{wks.location}/Divbox2D/",
        "%{wks.location}/vendor/Glad/include",
        "%{wks.location}/vendor/GLFW/include",
        "%{wks.location}/vendor/glm/include",
        "%{wks.location}/vendor/stb/include",
    }



    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }



	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "Divbox2D_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "Divbox2D_DEBUG_RELEASE"
		runtime "Release"
		optimize "on"


project "Sandbox"
    location "../Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("bin" .. "/%{prj.name}")
    objdir("bin-int" .. "/%{prj.name}")

    files {
        "../Divbox2D/Sandbox/**.cpp",
        "../Divbox2D/Sandbox/**.h"
    }

    includedirs
    {
        "%{wks.location}/Divbox2D/",
        "%{wks.location}/vendor/Glad/include",
        "%{wks.location}/vendor/GLFW/include",
        "%{wks.location}/vendor/glm/include",
        "%{wks.location}/vendor/stb/include"
    }

    links
    {
        "Divbox2D"
    }

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "Divbox2D_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "Divbox2D_RELEASE"
		runtime "Release"
		optimize "on"
