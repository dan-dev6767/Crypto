cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Crypto")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


find_package(CLI11 CONFIG REQUIRED)
find_package(unofficial-sodium CONFIG REQUIRED)

# CRYPTO.DLL
add_library(Crypto SHARED "crypto/crypto.cpp")
set_target_properties(Crypto PROPERTIES 
	DEFINE_SYMBOL CRYPTO_EXPORTS
	CXX_VISIBILITY_PRESET hidden
	VISIBILITY_INLINES_HIDDEN ON
)
target_include_directories(Crypto PUBLIC ${CMAKE_SOURCE_DIR}/crypto)

target_link_libraries(Crypto PRIVATE
	unofficial-sodium::sodium
)

# Executable
add_executable (Encryptor "source/main.cpp")
target_link_libraries(Encryptor PRIVATE Crypto CLI11::CLI11)