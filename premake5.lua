workspace "SalveDas"
   configurations { "Debug", "Release" }
   platforms {"x64"}

   filter "system:Windows"
      defines {"SD_WINDOWS"}

project "SalveDasEditor"
   kind "ConsoleApp"
   language "C++"
   location "SalveDasEditor/"
   files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" }
   targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"
   objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"

   includedirs {"%{wks.location}/SalveDas"}

   links {"SalveDas"}

   postbuildcommands {"{COPYFILE} %{wks.location}/bin/SalveDas/%{cfg.buildcfg}/%{cfg.platform}/SalveDas.dll %{wks.location}/bin/SalveDasEditor/%{cfg.buildcfg}/%{cfg.platform}/SalveDas.dll"}

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"

project "SalveDas"
   kind "SharedLib"
   language "C++"
   location "SalveDas/"
   files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" }
   targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"
   objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}/%{cfg.platform}/"

   defines {"SD_BUILD_DLL"}

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"