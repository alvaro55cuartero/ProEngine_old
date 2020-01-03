-- premake5.lua
workspace "PorEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ProEngine"
   location "ProEngine"
   kind "SharedLib"
   language "C++"
   
   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
   
   files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

   includedirs {
      "%{prj.name}/src",
      "%{prj.name}/vendor/spdlog/include"
   }

   filter "system:windows"
      cppdialect "c++17"
      staticruntime "on"
      systemversion "latest"

      defines {"PRO_PLATFORM_WINDOWS", "PRO_BUILD_DLL"}

      postbuildcommands {
         ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
      }

   filter "configurations:Debug"
      defines { "PRO_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "PRO_RELEASE" }
      optimize "On"

   filter "configurations:Dist"
      defines { "PRO_DIST" }
      optimize "On"


project "SandBox"
   location "SandBox"
   kind "consoleApp"
   language "C++"
   
   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
   
   files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

   includedirs {
      "ProEngine/vendor/spdlog/include",
      "ProEngine/src"
   }

   links {"ProEngine"}

   filter "system:windows"
      cppdialect "c++17"
      staticruntime "on"
      systemversion "latest"

      defines {"PRO_PLATFORM_WINDOWS"}

   filter "configurations:Debug"
      defines { "PRO_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "PRO_RELEASE" }
      optimize "On"

   filter "configurations:Dist"
      defines { "PRO_DIST" }
      optimize "On"