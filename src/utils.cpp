#include <utils.hpp>
#include <algorithm>

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

Camera* Utils::camera = nullptr;

void Utils::initCamera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat nearPlane, 
    GLfloat farPlane, glm::vec3 camPos, glm::vec3 camFront, glm::vec3 camUp) {
        camera = new Camera(FOV, width, height, nearPlane, farPlane, camPos, camFront, camUp);
    }

std::string Utils::getCWD() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}

std::string Utils::getPath(const std::string path) {
    auto cwd = Utils::getCWD();
    std::transform(cwd.begin(), cwd.end(), cwd.begin(), toupper);
    auto i = cwd.find("NICEOBJLOADER");
    return getCWD().substr(0,i+13) + path;
}