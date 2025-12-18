cmake_minimum_required(VERSION 3.24)
project(JX11 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# JUCE
set(JUCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/JUCE")

if(NOT EXISTS "${JUCE_PATH}/CMakeLists.txt")
    message(FATAL_ERROR "JUCE not found at: ${JUCE_PATH}. Please clone JUCE: git clone https://github.com/juce-framework/JUCE.git")
endif()
add_subdirectory("${JUCE_PATH}" "${CMAKE_BINARY_DIR}/JUCE_build")

# Plugin target
juce_add_plugin(JX11
    COMPANY_NAME "naanpowered"
    PLUGIN_MANUFACTURER_CODE "naan"
    PLUGIN_CODE "JXJX"
    FORMATS VST3 Standalone
    PRODUCT_NAME "JX11"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
)

juce_generate_juce_header(JX11)

target_sources(JX11 PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_include_directories(JX11 PRIVATE Source)

target_compile_definitions(JX11 PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_link_libraries(JX11 PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_plugin_client
    juce::juce_audio_processors
    juce::juce_audio_basics
    juce::juce_gui_basics
    juce::juce_dsp
)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
endif()

message(STATUS "✅ Building JX11")

juce_enable_copy_plugin_step(JX11)
