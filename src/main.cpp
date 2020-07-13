// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

#include <utils.hpp>
#include <FirstPersonView.hpp>
#include <stb_image.h>
#include <model.h>
#include <mesh.h>
#include <shader.h>
#include <iostream>

int main( void )
{
	auto window = new FirstPersonView(800, 600, "Sample");

    // говорим stb_image.h чтобы он перевернул загруженные текстуры относительно y-оси (до загрузки модели).

	// Create and compile our GLSL program from the shaders
	Shader myShade (Utils::getPath("/assets/VertexShader.vs").c_str(), Utils::getPath("/assets/FragmentShader.fs" ).c_str());

	Model Cyborg(Utils::getPath("/assets/cyborg/cyborg.obj"));
	Model Table(Utils::getPath("/assets/table.obj"));
	Model Nanosuit(Utils::getPath("/assets/nanosuit/nanosuit.obj"));
    stbi_set_flip_vertically_on_load(true);
	Model Backpack(Utils::getPath("/assets/backpack/backpack.obj"));
	stbi_set_flip_vertically_on_load(false);
	do{

		window->runWindow(0.01f, [&]() {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// убеждаемся, что активировали шейдер прежде, чем настраивать uniform-переменные/объекты_рисования
			myShade.use();

			//преобразования Вида / Проекции
			myShade.setMat4("projection", Utils::getCamera()->getProjectionMatrix());
			myShade.setMat4("view", Utils::getCamera()->getViewMatrix());

			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(-3.0f, 0.0f, 0.0f)); // смещаем вниз чтобы быть в центре сцены
			model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));	// объект слишком большой для нашей сцены, поэтому немного уменьшим его
			model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
			myShade.setMat4("model", model);
			Nanosuit.Draw(myShade);

			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f)); // смещаем вниз чтобы быть в центре сцены
			model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// объект слишком большой для нашей сцены, поэтому немного уменьшим его
			model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, -1.0, 0.0));
			myShade.setMat4("model", model);
			Cyborg.Draw(myShade);
			
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(-0.5f, 2.9f, 0.0f)); // смещаем вниз чтобы быть в центре сцены
			model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));	// объект слишком большой для нашей сцены, поэтому немного уменьшим его
			myShade.setMat4("model", model);
			Backpack.Draw(myShade);

			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, -0.7f, -0.8f)); // смещаем вниз чтобы быть в центре сцены
			model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// объект слишком большой для нашей сцены, поэтому немного уменьшим его
			myShade.setMat4("model", model);
			Table.Draw(myShade);

			

		});


	} // Check if the ESC key was pressed or the window was closed
	while( glfwWindowShouldClose(window->getWindow()) == 0 );

	glfwTerminate();

	return 0;
}

