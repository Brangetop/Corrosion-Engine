#ifndef LOG_H
#define LOG_H

#include <string_view>

class Log
{
public:
  enum class System
  {
    Window,
    Render,
    Audio,
    Shader,
    Client
  };

  static void Info(System sys, std::string_view message);
  static void Error(System sys, std::string_view message);
};

static constexpr std::string_view
SystemToString(Log::System sys);

#endif