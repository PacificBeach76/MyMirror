#ifndef SHADER_H
#define SHADER_H

/* include glad to get all the required OpenGL headers */
#include <glad/glad.h> 
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/* Shader Class */
class Shader
{
public:
    /* Shader program ID */
    unsigned int ID;

    /* Constructor reads and builds the shader */
    Shader(const char* vertexPath, const char* fragmentPath);

    /* Destructor */
    ~Shader();

    /* Activate and use the shader */
    void use();
    
    /* utility uniform functions */
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setVec2(const std::string& name, float x, float y) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setVec3(const std::string& name, float x, float y, float z) const;
    void setVec4(const std::string& name, const glm::vec4& value) const;
    void setVec4(const std::string& name, float x, float y, float z, float w) const;
    void setMat2(const std::string& name, const glm::mat2& mat) const;
    void setMat3(const std::string& name, const glm::mat3& mat) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

    bool loadTextureImage(const char* filename, unsigned char** data, int* width, int* height, int* nrChannels) const;
    unsigned int createTexture2D(const char* filename, unsigned int pixel_format, unsigned int pixel_size) const;

private:
    /* utility to check compilation errors */
    void checkCompileErrors(unsigned int shader, std::string type) const;
};

#endif