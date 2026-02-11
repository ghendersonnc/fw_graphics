#include "fw_graphics/shader.h"

#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <fw_utility/file_loaders.h>


namespace Fw::Graphics
{
    Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath) {
        _shaderPaths = {std::move(vertexShaderPath), std::move(fragmentShaderPath)};
        const std::string vertexShaderString = Utility::loadTextFileToString(_shaderPaths.first);
        const std::string fragmentShaderString = Utility::loadTextFileToString(_shaderPaths.second);

        std::vector<GLuint> shaders;
        shaders.reserve(2);
        shaders.push_back(compileShader(GL_VERTEX_SHADER, vertexShaderString));
        shaders.push_back(compileShader(GL_FRAGMENT_SHADER, fragmentShaderString));

        _shaderId = glCreateProgram();
        for (const unsigned int& shader : shaders)
        {
            glAttachShader(_shaderId, shader);
        }

        glLinkProgram(_shaderId);

        for (const unsigned int& shader : shaders)
        {
            glDeleteShader(shader);
        }

    }

    Shader::~Shader() {
        destroy();
    }

    void Shader::use() const {
        glUseProgram(_shaderId);
    }

    void Shader::destroy() const {
        glDeleteProgram(_shaderId);
    }

    void Shader::setUniform4F(const std::string& name, glm::vec4 vector) const {
        const int uniformLocation = glGetUniformLocation(_shaderId, name.data());
        glUniform4fv(uniformLocation, 1, glm::value_ptr(vector));
    }

    void Shader::setUniform4I(const std::string& name, glm::ivec4 vector) const {
        const int uniformLocation = glGetUniformLocation(_shaderId, name.data());
        glUniform4iv(uniformLocation, 1, glm::value_ptr(vector));
    }

    void Shader::setUniformMat4F(const std::string& name, glm::mat4 matrix) const {
        const int uniformLocation = glGetUniformLocation(_shaderId, name.data());
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void Shader::setFloat(const std::string& name, float value) const {
        const int uniformLocation = glGetUniformLocation(_shaderId, name.data());
        glUniform1f(uniformLocation, value);
    }

    unsigned int Shader::compileShader(const int shaderType, const std::string& shaderString) {
        const unsigned int shader = glCreateShader(shaderType);
        const char* shaderData = shaderString.data();
        const int length = static_cast<int>(shaderString.size());

        glShaderSource(shader, 1, &shaderData, &length);
        glCompileShader(shader);
        compileErrors(shader);
        return shader;
    }

    void Shader::compileErrors(const unsigned int& shader) {
        int isCompiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

        if (isCompiled == GL_FALSE)
        {
            int logLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            std::vector<char> errorLog(logLength);
            glGetShaderInfoLog(shader, logLength, &logLength, errorLog.data());

            std::cerr << errorLog.data() << '\n';
        }
    }
}
