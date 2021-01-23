#include <iostream>
#include <glm/vec3.hpp>

int main(int argc, char **argv)
{
    auto vector3 = glm::vec3(3.0, 3.0, 3.0);
    std::cout << "{"
              << " x: " << vector3.x
              << " y: " << vector3.y
              << " z: " << vector3.z
              << "}\n";
    return 0;
}