cmake_minimum_required(VERSION 3.4)

set(dedupfs_SOURCES "dedupfs.cc" PARENT_SCOPE)
find_package(OpenSSL REQUIRED)
set(dedupfs_INCLUDE_PATHS "${OPENSSL_INCLUDE_DIR}" PARENT_SCOPE)
set(dedupfs_LIBS ${OPENSSL_CRYPTO_LIBRARY} PARENT_SCOPE)

if(MSVC)
  set(dedupfs_CMAKE_SHARED_LINKER_FLAGS "/EXPORT:dedupfs_reg" PARENT_SCOPE)
  set(dedupfs_CMAKE_EXE_LINKER_FLAGS "/INCLUDE:dedupfs_reg" PARENT_SCOPE)
else()
  set(dedupfs_CMAKE_EXE_LINKER_FLAGS "-u dedupfs_reg" PARENT_SCOPE)
endif()
