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
IncludeDir["ImGui"] = "Engine/Libs/ImGui"
IncludeDir["glm"] = "Engine/Libs/glm"

group "Dependencies"
	include "Engine/Libs/glfw"
	include "Engine/Libs/glad"
	include "Engine/Libs/ImGui"
group ""

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"

	targetdir ("Bin/"  ..outputdir.. "/%{prj.name}")
	objdir ("Obj/"  ..outputdir.. "/%{prj.name}")

	pchheader "dpch.h"
	pchsource "%{prj.name}/Src/dpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Libs/glm/glm/**.hpp",
		"%{prj.name}/Libs/glm/glm/**.inl"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}//Libs/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{
		"glfw",
		"glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"DIV_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "DIV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DIV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DIV_DIST"
		runtime "Release"
		optimize "on"


project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "c++17"


	staticruntime "on"


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
		"%{IncludeDir.glm}"
	}

	links
	{
		"Engine"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			
		}

	filter "configurations:Debug"
		defines "DIV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DIV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DIV_DIST"
		runtime "Release"
		optimize "on"

