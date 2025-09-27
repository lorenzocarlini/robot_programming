find_package(Eigen3 REQUIRED)

# Add needed source files
add_library(core_library SHARED

    # utils/*.cpp
    utils/blob.cpp
    utils/deserializer.cpp
    utils/id_context.cpp
    utils/identifiable.cpp
    utils/id_placeholder.cpp
    utils/object_data.cpp
    utils/property_container.cpp
    utils/property_container_manager.cpp
    utils/property.cpp
    utils/property_eigen.cpp
    utils/property_identifiable.cpp
    utils/serializable.cpp
    utils/serialization_context.cpp
    utils/serializer.cpp

    # messages/*.cpp
    messages/base_sensor_message.cpp
    messages/odometry_message.cpp
    messages/pose_message.cpp


)

# Let's make sure any target linked against core_library will inherit those included paths
target_include_directories(core_library
    PUBLIC
        ${EIGEN3_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR})

