#include "Device.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

Device::Device(int id, const string& logFilePath)
    : deviceId(id), logFilePath(logFilePath), running(false)
{
    logFile.open(logFilePath, ios::app);
    if (!logFile.is_open()) {
        cerr << "❌ Failed to open log file: " << logFilePath << endl;
    } else {
        cout << "✅ Device " << deviceId << " logging to " << logFilePath << endl;
    }
}

Device::~Device() {
    stop();  // 確保停止執行緒
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Device::start() {
    running = true;
    thread(&Device::run, this).detach();  // 啟動模擬執行緒
}

void Device::stop() {
    running = false;
}

void Device::run() {
    while (running) {
        string timestamp = getCurrentTime();
        float temp = generateTemperature();
        string status = "OK";

        if (logFile.is_open()) {
            logFile << timestamp << " | Device"
                    << setw(3) << setfill('0') << deviceId
                    << " | TEMP=" << temp
                    << " | STATUS=" << status << endl;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
}

float Device::generateTemperature() {
    static default_random_engine generator(random_device{}());
    uniform_real_distribution<float> distribution(60.0f, 100.0f);
    return distribution(generator);
}

string Device::getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* timeinfo = localtime(&now_c);

    ostringstream oss;
    oss << put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

