workspace "SalveDas"
   configurations { "Debug", "Release" }
   platforms {"x64"}

project "SalveDas"
   kind "ConsoleApp"
   language "C++"
   location "SalveDas/"
   files { "**.h", "**.cpp" }
   targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.architecture}/%{cfg.platform}/"
   objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.architecture}/%{cfg.platform}/"

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"