workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir	= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	

-- Include directories relative to root folder solution directory)
IncludeDir = {}
IncludeDir["glfw"] = "Engine/Libs/glfw/include"
IncludeDir["glad"] = "Engine/Libs/glad/include"

include "Engine/Libs/glfw"
include "Engine/Libs/glad"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("Bin/"  ..outputdir.. "/%{prj.name}")
	objdir ("Obj/"  ..outputdir.. "/%{prj.name}")

	pchheader "dpch.h"
	pchsource "Engine/Src/dpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}//Libs/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{prj.name}//Libs/GLM/glm"
	}

	links 
	{
		"glfw",
		"glad",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"DIV_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Bin/" .. outputdir .. "/Game")
		}

	filter "configurations:Debug"
		defines "DIV_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DIV_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DIV_DIST"
		buildoptions "/MD"
		optimize "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"
		optimize "On"

project "Game"
	location "Game"
	kind "ConsoleApp"

	language = "C++"

	targetdir ("Bin/"  ..outputdir.. "/%{prj.name}")
	objdir ("Obj/"  ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Engine/Libs/spdlog/include",
		"Engine/src",
		"Engine/Libs/GLM/glm"
	}

	links
	{
		"Engine"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			
		}

	filter "configurations:Debug"
		defines "DIV_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DIV_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DIV_DIST"
		buildoptions "/MD"
		optimize "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"
		optimize "On"