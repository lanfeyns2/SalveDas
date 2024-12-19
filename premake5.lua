workspace "SalveDas"
   configurations { "Debug", "Release" }
   platforms {"x64"}

   filter "system:Windows"
      defines {"SD_WINDOWS"}

      
   buildoptions {"/utf-8"}

project "SalveDasEditor"
   kind "ConsoleApp"
   language "C++"
   location "SalveDasEditor/"
   files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" }
   targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"
   objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"

   includedirs {"%{wks.location}/SalveDas","%{wks.location}/glfw/","%{wks.location}/vendor/universal/include"}
   libdirs {"%{wks.location}/vendor/universal/lib"}

   links {"SalveDas"}

   postbuildcommands {"{COPYFILE} %{wks.location}/bin/SalveDas/%{cfg.buildcfg}/%{cfg.platform}/SalveDas.dll %{wks.location}/bin/SalveDasEditor/%{cfg.buildcfg}/%{cfg.platform}/SalveDas.dll","{COPYFILE} %{wks.location}/bin/glfw/%{cfg.buildcfg}/%{cfg.platform}/glfw.dll %{wks.location}/bin/SalveDasEditor/%{cfg.buildcfg}/%{cfg.platform}/glfw.dll"}

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"
   filter { "system:Windows" }
      includedirs {"%{wks.location}/vendor/windows/include"}
      libdirs {"%{wks.location}/vendor/windows/lib"}
      links {"glfw3.lib"}

project "SalveDas"
   kind "SharedLib"
   language "C++"
   location "SalveDas/"
   files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" }
   targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"
   objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"

   defines {"SD_BUILD_DLL"}

   includedirs {"%{wks.location}/glfw/","%{wks.location}/vendor/universal/include"}
   libdirs {"%{wks.location}/vendor/universal/lib"}
   links {"glfw"}

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"
   filter { "system:Windows" }
      includedirs {"%{wks.location}/vendor/windows/include"}
      libdirs {"%{wks.location}/vendor/windows/lib"}

project "glfw"
   kind "SharedLib"
   language "C++"
   location "glfw/"
   files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" }
   targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"
   objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"

   defines {"SD_GL_BUILD_DLL"}

   includedirs {"%{wks.location}/vendor/universal/include"}
   libdirs {"%{wks.location}/vendor/universal/lib"}

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"
   filter { "system:Windows" }
      includedirs {"%{wks.location}/vendor/windows/include"}
      libdirs {"%{wks.location}/vendor/windows/lib"}
      links {"glfw3.lib","opengl32.lib"}