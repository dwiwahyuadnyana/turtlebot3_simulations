################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 3.0.2)
project(turtlebot3_gazebo)
cmake_policy(SET CMP0054 NEW)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

################################################################################
# Find catkin packages and libraries for catkin and system dependencies
################################################################################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
  tf
  gazebo_ros
)

find_package(gazebo REQUIRED)

################################################################################
# Setup for python modules and scripts
################################################################################

################################################################################
# Declare ROS messages, services and actions
################################################################################

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs sensor_msgs geometry_msgs nav_msgs tf gazebo_ros
  DEPENDS GAZEBO
)

################################################################################
# Build
################################################################################
link_directories(${GAZEBO_LIBRARY_DIRS})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
)

add_executable(turtlebot3_drive src/turtlebot3_drive.cpp)
add_dependencies(turtlebot3_drive ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(turtlebot3_drive ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

################################################################################
# Install
################################################################################
install(TARGETS turtlebot3_drive
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

install(DIRECTORY launch models rviz worlds 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

################################################################################
# Test
################################################################################

add_executable(controller1 src/controller1.cpp)
add_dependencies(controller1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(controller1 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(posmonitor src/posmonitor.cpp)
add_dependencies(posmonitor ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(posmonitor ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrusters0 src/thrusters0.cpp)
add_dependencies(thrusters0 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrusters0 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrusters1 src/thrusters1.cpp)
add_dependencies(thrusters1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrusters1 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrusters2 src/thrusters2.cpp)
add_dependencies(thrusters2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrusters2 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrusters3 src/thrusters3.cpp)
add_dependencies(thrusters3 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrusters3 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrusters4 src/thrusters4.cpp)
add_dependencies(thrusters4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrusters4 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrusters5 src/thrusters5.cpp)
add_dependencies(thrusters5 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrusters5 ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(square src/square.cpp)
add_dependencies(square ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(square ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_executable(thrustmonitor src/thrustmonitor.cpp)
add_dependencies(thrustmonitor ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(thrustmonitor ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
