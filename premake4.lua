-- Create Solution

solution "CDKEngineLib"

configurations{"Debug","Release"}
location("debug")
targetdir("debug/bin")
debugdir("data")


project "CDKEngineLib"
	kind "ConsoleApp"
	language "C++"
	defines {"_GLFW_WIN32","_GLFW_WGL","_GLFW_USE_OPENGL","GLEW_STATIC"}
	links{"opengl32","cdk"}
	includedirs{"include"}
	libdirs{"lib"}
	files{"include/**.h","src/**.cc","src/**.c","src/**.cpp"}


