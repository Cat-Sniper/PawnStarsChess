# Install script for directory: F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/out/install/x64-Debug (default)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/out/build/x64-Debug (default)/code/assimp-vc142-mtd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/out/build/x64-Debug (default)/code/assimp-vc142-mtd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/anim.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/aabb.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/ai_assert.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/camera.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/color4.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/color4.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/out/build/x64-Debug (default)/code/../include/assimp/config.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/defs.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Defines.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/cfileio.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/light.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/material.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/material.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/matrix3x3.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/matrix3x3.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/matrix4x4.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/matrix4x4.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/mesh.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/pbrmaterial.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/postprocess.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/quaternion.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/quaternion.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/scene.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/metadata.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/texture.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/types.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/vector2.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/vector2.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/vector3.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/vector3.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/version.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/cimport.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/importerdesc.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Importer.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/DefaultLogger.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/ProgressHandler.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/IOStream.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/IOSystem.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Logger.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/LogStream.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/NullLogger.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/cexport.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Exporter.hpp"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/DefaultIOStream.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/DefaultIOSystem.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/ZipArchiveIOSystem.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/SceneCombiner.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/fast_atof.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/qnan.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/BaseImporter.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Hash.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/MemoryIOWrapper.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/ParsingUtils.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/StreamReader.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/StreamWriter.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/StringComparison.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/StringUtils.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/SGSpatialSort.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/GenericProperty.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/SpatialSort.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/SkeletonMeshBuilder.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/SmoothingGroups.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/SmoothingGroups.inl"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/StandardShapes.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/RemoveComments.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Subdivision.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Vertex.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/LineSplitter.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/TinyFormatter.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Profiler.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/LogAux.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Bitmap.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/XMLTools.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/IOStreamBuffer.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/CreateAnimMesh.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/irrXMLWrapper.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/BlobIOSystem.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/MathFunctions.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Macros.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Exceptional.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Compiler/pushpack1.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Compiler/poppack1.h"
    "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/out/build/x64-Debug (default)/code/assimp-vc142-mtd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "F:/Repos/PawnStars/PawnStarsChess/Chess Game/Dependencies/assimp-5.0.1/assimp-5.0.1/out/build/x64-Debug (default)/code/assimp-vc142-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

