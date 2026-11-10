#include "log.hpp"
#include <format>
#include <iostream>

static constexpr std::string_view
SystemToString(Log::System sys)
{
  switch (sys) {
    case Log::System::Window:
      return "Window";
    case Log::System::Render:
      return "Render";
    case Log::System::Audio:
      return "Audio";
    case Log::System::Shader:
      return "Shader";
    case Log::System::Client:
      return "Client";
    default:
      return "Unknown";
  }
}

static void
PrintLog(std::string_view level,
         Log::System sys,
         std::string_view message,
         std::string_view color)
{
  constexpr std::string_view resetColor = "\033[0m";

  std::cout << std::format("{}{:<7} [{}] {}{}\n",
                           color,
                           level,
                           SystemToString(sys),
                           message,
                           resetColor);
}

void
Log::Info(System sys, std::string_view message)
{
  constexpr std::string_view greenColor = "\033[32m";
  PrintLog("INFO", sys, message, greenColor);
}

void
Log::Error(System sys, std::string_view message)
{
  constexpr std::string_view redColor = "\033[31m";
  PrintLog("[ERROR]", sys, message, redColor);
}