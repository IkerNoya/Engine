workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir	= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	

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
		"%{prj.name}//Libs/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"DIV_BUILD_DLL"	
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Bin/" .. outputdir .. "/Game")
		}

	filter "configurations:Debug"
		defines "DIV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DIV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIV_DIST"
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
		"Engine/src"
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
		symbols "On"

	filter "configurations:Release"
		defines "DIV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIV_DIST"
		optimize "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"
		optimize "On"