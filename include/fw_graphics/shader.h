#pragma once
#include <string>
#include <utility>
#include <glm/glm.hpp>

namespace Fw::Graphics
{
    class Shader
    {
    public:
        Shader() = default;
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
        ~Shader();

        void use() const;
        void destroy() const;

        void setUniform4F(const std::string& name, glm::vec4 vector) const;
        void setUniform4I(const std::string& name, glm::ivec4 vector) const;

        void setUniformMat4F(const std::string& name, glm::mat4 matrix) const;

        void setFloat(const std::string& name, float value) const;

    private:
        unsigned int _shaderId;
        std::pair<std::string, std::string> _shaderPaths;
        static unsigned int compileShader(int shaderType, const std::string& shaderString);
        static void compileErrors(const unsigned int& shader);

    };
}