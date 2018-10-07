project(DbTernaryClock)

set(HEADERS
)

set(SOURCES
    main.cpp
)

add_executable(ternaryclock ${HEADERS} ${SOURCES})

target_link_libraries(ternaryclock Qt5::Core Qt5::Gui Qt5::Widgets dbguilib)
