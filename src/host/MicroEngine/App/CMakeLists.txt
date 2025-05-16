add_executable(App
    main.cpp
    Application.cpp
    Application.h
)

target_link_libraries(App PRIVATE Engine)

target_include_directories(App PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)


add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Engine>
        $<TARGET_FILE_DIR:App>
)

add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${DOTNET_DLL}"
        $<TARGET_FILE_DIR:App>
)