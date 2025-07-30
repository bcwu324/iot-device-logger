#ifndef DEVICE_H //如果DEVICE_H尚未定義
#define DEVICE_H //定義DEVICE_H
#include <string>
#include <fstream>
#include <atomic>

//標頭內容，例如宣告類別
class Device {
  private:
    int deviceId;
    std::string logFilePath;
    std::ofstream logFile;
    std::atomic<bool> running;
    float generateTemperature();
    std::string getCurrentTime();

  public:
    Device(int id, const std::string& logFile);
    ~Device();

    void start();
    void stop();
    void run();
};


#endif
