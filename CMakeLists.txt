cmake_minimum_required(VERSION 3.16)
project(id3lib CXX)




list(APPEND library_source
   _interface_readers.cpp
    #src/c_wrapper.cpp
   src/field.cpp
   src/field_binary.cpp
   src/field_def.h
   src/field_impl.h
   src/field_integer.cpp
   src/field_string_ascii.cpp
   src/field_string_unicode.cpp
   src/flags.h
   src/frame.cpp
   src/frame_def.h
   src/frame_impl.cpp
   src/frame_impl.h
   src/frame_parse.cpp
   src/frame_render.cpp
   src/globals.cpp
   src/header.cpp
   src/header.h
   src/header_frame.cpp
   src/header_frame.h
   src/header_tag.cpp
   src/header_tag.h
   src/helpers.cpp
   src/io.cpp
   src/io_decorators.cpp
   src/io_helpers.cpp
   src/misc_support.cpp
   src/mp3_header.h
   src/mp3_parse.cpp
   src/readers.cpp
   src/spec.cpp
   src/spec.h
   src/tag.cpp
   src/tag_file.cpp
   src/tag_find.cpp
   src/tag_impl.cpp
   src/tag_impl.h
   src/tag_parse.cpp
   src/tag_parse_lyrics3.cpp
   src/tag_parse_musicmatch.cpp
   src/tag_parse_v1.cpp
   src/tag_render.cpp
   src/utils.cpp
   #src/writers.cpp


   )


if(WIN32)

    #list(APPEND audio_source
       #id3lib/windows/tts_speaker.cpp
       #id3lib/windows/tts_speaker.h
     #  )

endif()


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


#target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
#target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)
target_compile_definitions(static_${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32 winmm shlwapi)
elseif(${LINUX} OR ${FREEBSD} OR ${OPENBSD} OR ${NETBSD})


    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    #target_link_options(id3lib PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(${PROJECT_NAME} PRIVATE z)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)


endif()




list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/include)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${PLATFORM_NAME}/configuration/${PROJECT_NAME})



target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_projeeeeect)



