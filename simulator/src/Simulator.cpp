#include "Device.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <memory>

using namespace std;

int main() {
    vector<unique_ptr<Device>> devices;

    devices.emplace_back(make_unique<Device>(1, "log_device_001.txt"));
    devices.emplace_back(make_unique<Device>(2, "log_device_002.txt"));

    for (auto& d : devices) {
        d->start();
    }

    cout << "⌛ 模擬進行中（5 秒）..." << endl;
    this_thread::sleep_for(chrono::seconds(5));

    for (auto& d : devices) {
        d->stop();
    }

    this_thread::sleep_for(chrono::seconds(1));
    cout << "✅ 模擬完成" << endl;

    return 0;
}

