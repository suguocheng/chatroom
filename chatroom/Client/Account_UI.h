#pragma once

#include "SendJson.h"
#include "Home_UI.h"
#include <iostream>
#include <string>
#include <unistd.h> //文件操作
#include <nlohmann/json.hpp> //JSON库
#include <semaphore.h> //信号量库
#include <termios.h> //回显库
#include <csignal>
#include <cstring>

using json = nlohmann::json;

extern sem_t semaphore;//声明信号量

extern std::string current_UID;  // 声明全局变量

void main_menu_UI(int connecting_sockfd);
void log_in_UI(int connecting_sockfd);
void sign_up_UI(int connecting_sockfd);
void retrieve_password(int connecting_sockfd);
void change_usename_UI(int connecting_sockfd, std::string UID);
void change_password_UI(int connecting_sockfd, std::string UID);
void change_security_question_UI(int connecting_sockfd, std::string UID);
void log_out_UI(int connecting_sockfd, std::string UID);