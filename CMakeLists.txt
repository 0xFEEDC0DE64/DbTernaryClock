project(DbTernaryClock)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

set(HEADERS
)

set(SOURCES
    main.cpp
)

add_executable(ternaryclock ${HEADERS} ${SOURCES})

target_link_libraries(ternaryclock stdc++ Qt5::Core Qt5::Gui Qt5::Widgets dbguilib)
