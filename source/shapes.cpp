//#include <application.hpp>
//#include <shader.hpp>
//
//
//class Phase1 : public A2::Application {
//
//    A2::ShaderProgram program;
//    GLuint vertex_array = 0;
//
//    glm::vec2 scale = glm::vec2(1.5,1);
//    glm::vec2 translation = glm::vec2(0.5,0.5);
//    A2::Mouse& mouse = getMouse();
//    Keyboard& keyboard=getKeyboard();
//    const glm::vec2& mousePos=mouse.getMousePosition();
//    glm::vec3 color = glm::vec3(1, 0, 0);
//    bool vibrate = false, flicker = false;
//
//    A2::WindowConfiguration getWindowConfiguration() override {
//        return { "Uniforms", {1280, 720}, false };
//    }
//
//    void onInitialize() override {
//
//        program.create();
//        program.attach("../assets/shaders/vertexshader.vert", GL_VERTEX_SHADER);
//        program.attach("../assets/shaders/black.frag", GL_FRAGMENT_SHADER);
//        program.link();
//
//        glGenVertexArrays(1, &vertex_array);
//
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    }
//
//    void onDraw(double deltaTime) override {
//
//        if(keyboard.justPressed(GLFW_KEY_1)){
//            program.create();
//            program.attach("../assets/shaders/vertexshader.vert", GL_VERTEX_SHADER);
//            program.attach("../assets/shaders/smiley.frag", GL_FRAGMENT_SHADER);
//            program.link();
//        }
//        else if(keyboard.justPressed(GLFW_KEY_2)){
//            program.create();
//            program.attach("../assets/shaders/vertexshader.vert", GL_VERTEX_SHADER);   // read the vertex shader and attach it to the program.
//            program.attach("../assets/shaders/heart.frag", GL_FRAGMENT_SHADER);
//            program.link();
//        }
//        else if(keyboard.justPressed(GLFW_KEY_3)){
//            program.create();
//            program.attach("../assets/shaders/vertexshader.vert", GL_VERTEX_SHADER);   // read the vertex shader and attach it to the program.
//            program.attach("../assets/shaders/pacman.frag", GL_FRAGMENT_SHADER);
//            program.link();
//        }
//
//        glClear(GL_COLOR_BUFFER_BIT);
//        glUseProgram(program);
//
//        GLuint scale_uniform_location = glGetUniformLocation(program, "scale");
//        glUniform2f(scale_uniform_location, scale.x, scale.y);
//        GLuint translation_uniform_location = glGetUniformLocation(program, "translation");
//        glUniform2f(translation_uniform_location, (mousePos.x)/640, (mousePos.y)/360);
//        GLuint color_uniform_location = glGetUniformLocation(program, "color");
//        glUniform3f(color_uniform_location, color.r, color.g, color.b);
//
//        GLuint time_uniform_location = glGetUniformLocation(program, "time");
//        glUniform1f(time_uniform_location, glfwGetTime());
//        GLuint vibrate_uniform_location = glGetUniformLocation(program, "vibrate");
//        glUniform1i(vibrate_uniform_location, vibrate);
//        GLuint flicker_uniform_location = glGetUniformLocation(program, "flicker");
//        glUniform1i(flicker_uniform_location, flicker);
//
//
//        glBindVertexArray(vertex_array);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        glBindVertexArray(0);
//    }
//
//    void onDestroy() override {
//        program.destroy();
//        glDeleteVertexArrays(1, &vertex_array);
//    }
//
//    void onImmediateGui(ImGuiIO &io) override {
//        ImGui::Begin("Controls");
//        ImGui::SliderFloat2("Scale", glm::value_ptr(scale), 0, 1);
//        ImGui::SliderFloat2("Translation", glm::value_ptr(translation), -2, 2);
//        ImGui::ColorEdit3("Color", glm::value_ptr(color));
//        ImGui::Checkbox("Vibrate", &vibrate);
//        ImGui::Checkbox("Flicker", &flicker);
//        ImGui::Value("Time: ", (float)glfwGetTime());
//        ImGui::End();
//    }
//
//};
//
//int main(int argc, char** argv) {
//    return Phase1().run();
//}