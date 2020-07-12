#ifndef UTILS_HPP
#define UTILS_HPP

#include <Camera.hpp>
#include <string>

class Utils {
    private:
        static Camera* camera;
    public:
        static std::string getCWD();
        static std::string getPath(const std::string path);
        static void initCamera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat nearPlane,
            GLfloat farPlane, glm::vec3 camPos, glm::vec3 camFront, glm::vec3 camUp);
        static Camera* getCamera() noexcept {return camera;}
};

#endif