# 🏭 IoT Device Logger – 工廠設備模擬器與日誌分析系統

一個模擬智慧工廠內設備行為並進行日誌分析的專案，使用 C++ 撰寫模擬器，每台設備每秒產生一筆狀態資料，並寫入 log。分析模組每 10 秒統計設備狀況，輸出報告，可應用於智慧製造、設備監控與 DevOps 練習場景..

---

## 📦 專案模組

### 1️⃣ 模擬器模組（C++）
- 多台虛擬設備（使用 `std::thread`）
- 每秒產生一筆狀態資料（例如：`2025-07-29 14:00:00 | Device001 | TEMP=78.5 | STATUS=OK`）
- 資料寫入 log 檔案

### 2️⃣ 分析模組（C++ 或 Python）
- 每 10 秒讀取 log 資料
- 統計設備異常、負載分布
- 輸出 JSON / CSV 格式報告

---

## 🔧 使用技術

| 項目         | 技術                         |
|--------------|------------------------------|
| 多執行緒處理 | `std::thread`, `std::mutex`  |
| 檔案處理     | `fstream`, `chrono`          |
| 字串處理     | `stringstream`, `regex`      |
| JSON 輸出    | `nlohmann/json`              |
| 測試與 CI/CD | GitHub Actions, CMake        |
| 容器化       | Docker, docker-compose       |
| 可視化（進階）| Prometheus + Grafana        |

---

## 🚀 快速開始（模擬器）

```bash
cd simulator
mkdir build && cd build
cmake ..
make
./simulator

