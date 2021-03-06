/*
 * Copyright (C) 2020 Deranged Senators
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Logger.h"
#include <fstream>
#include <chrono>
#include <ctime>
namespace PlayerLink{namespace Core{
    Logger::Logger() {}
    Logger::~Logger() {}

    Logger* Logger::getLogger() {
        std::lock_guard<std::mutex> lock(mMutex);
        if (mInstance == nullptr) {
            mInstance = new Logger();
        }
        return mInstance;
    }
    void Logger::log(LogSeverity severity, std::string message)
    {
   
        //timing
        using Clock = std::chrono::steady_clock;
        auto tick = Clock::now;

        std::string logSev = (severity,message);
        
        //files the logger
        std::ofstream logFile;
        logFile.open("LOG FILE.txt");
        logFile << tick, logSev;
        logFile << "/n";
        logFile.close();



    }
}}

