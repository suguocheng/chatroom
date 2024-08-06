#include "Home_UI.h"

// int main() {
//     Home_UI();
//     return 0;
// }

void home_UI(int connecting_sockfd, std::string UID) {
    int n;
    while (1) {
        system("clear");
        std::cout << "主页" << std::endl;
        std::cout << "1.消息" << std::endl; //这里加个通知
        std::cout << "2.通讯录" << std::endl; //这里加个通知
        std::cout << "3.个人中心" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            message_UI(connecting_sockfd, UID);
        } else if (n == 2) {
            contacts_UI(connecting_sockfd, UID);
        } else if (n == 3) {
            if (user_UI(connecting_sockfd, UID) == 1) {
                return;
            }
        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
    
}

void message_UI(int connecting_sockfd, std::string UID) {
    char n;
    while (1) {
        system("clear");
        std::cout << "消息" << std::endl;
        //按回复时间输出会话列表
        std::cout << "输入R返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 'r' || n == 'R') {
            return;
        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
}

void contacts_UI(int connecting_sockfd, std::string UID) {
    int n;
    while (1) {
        system("clear");
        std::cout << "通讯录" << std::endl;
        std::cout << "1.好友" << std::endl; 
        std::cout << "2.群聊" << std::endl; 
        std::cout << "3.添加好友/群" << std::endl;//这里加个通知
        std::cout << "4.创建群聊" << std::endl;
        std::cout << "5.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            friends_UI(connecting_sockfd, UID);

        } else if (n == 2) {
            groups_UI(connecting_sockfd, UID);

        } else if (n == 3) {
            add_friends_groups_UI(connecting_sockfd, UID);

        } else if (n == 4) {
            //创建群聊

        } else if (n == 5) {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
}

void friends_UI(int connecting_sockfd, std::string UID) {
    char n;
    while (1) {
        system("clear");
        std::cout << "好友" << std::endl;
        //按首字母排序输出好友列表
        std::cout << "输入R返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 'r' || n == 'R') {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
}

void friend_details(int connecting_sockfd, std::string UID) {
    char n;
    while (1) {
        system("clear");
        std::cout << "好友详情" << std::endl;
        std::cout << "1.好友用户名" << std::endl; 
        std::cout << "2.好友id" << std::endl; 
        std::cout << "3.好友在线状态" << std::endl;
        std::cout << "4.私聊好友" << std::endl;
        std::cout << "5.屏蔽好友" << std::endl;
        std::cout << "6.删除好友" << std::endl;
        std::cout << "7.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            

        } else if (n == 2) {
            

        } else if (n == 3) {
            

        } else if (n == 4) {
            

        } else if (n == 5) {
            

        } else if (n == 6) {
            

        } else if (n == 7) {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
}

void groups_UI(int connecting_sockfd, std::string UID) {
    char n;
    while (1) {
        system("clear");
        std::cout << "群聊" << std::endl;
        //按首字母排序输出群聊列表
        std::cout << "输入R返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 'r' || n == 'R') {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
}

void add_friends_groups_UI(int connecting_sockfd, std::string UID) {
    int n;
    while (1) {
        system("clear");
        std::cout << "添加好友/群" << std::endl;
        std::cout << "1.添加好友" << std::endl; 
        std::cout << "2.添加群聊" << std::endl;
        std::cout << "3.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            
        } else if (n == 2) {
            
        } else if (n == 3) {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();
        }
    }
}

void add_friend_UI(int connecting_sockfd, std::string UID) {
    system("clear");
    std::cout << "添加好友" << std::endl;

    json j;
    j["type"] = "add_friend";
    std::string search_UID;

    j["UID"] = UID;

    std::cout << "搜索(请输入用户UID)：";
    std::cin >> search_UID;
    j["search_UID"] = search_UID;

    send_json(connecting_sockfd, j);
    
    usleep(50000);
    waiting_for_input();
}

void add_group_UI() {

}

bool user_UI(int connecting_sockfd, std::string UID) {
    int n;
    while (1) {
        system("clear");
        std::cout << "个人中心" << std::endl;
        std::cout << "1.个人信息" << std::endl;
        std::cout << "2.更改密码" << std::endl;
        std::cout << "3.退出帐号" << std::endl;
        std::cout << "4.注销帐号" << std::endl;
        std::cout << "5.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            information_UI(connecting_sockfd, UID);

        } else if (n == 2) {
            change_password_UI(connecting_sockfd, UID);

        } else if (n == 3) {
            return 1;

        } else if (n == 4) {
            log_out_UI(connecting_sockfd, UID);
            return 1;
        } else if (n == 5) {
            return 0;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();

        }
    }
}

void information_UI(int connecting_sockfd, std::string UID) {
    int n;
    while (1) {
        system("clear");
        std::cout << "个人信息" << std::endl;
        std::cout << "1.用户名" << std::endl; 
        std::cout << "2.UID" <<  std::endl;
        std::cout << "3.密保问题" << std::endl;
        std::cout << "4.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            username_UI(connecting_sockfd, UID);

        } else if (n == 2) {
            system("clear");
            std::cout << UID << std::endl;
            waiting_for_input();

        } else if (n == 3) {
            security_question_UI(connecting_sockfd, UID);

        } else if (n == 4) {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();

        }
    }
}

void username_UI(int connecting_sockfd, std::string UID){
    int n;
    while (1) {
        system("clear");
        std::cout << "用户名" << std::endl;
        std::cout << "1.用户名：" << std::endl;
        std::cout << "2.更改用户名" << std::endl;
        std::cout << "3.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            system("clear");
            json j;
            j["type"] = "get_username";
            j["UID"] = UID;
            send_json(connecting_sockfd, j);
            usleep(50000);
            waiting_for_input();

        } else if (n == 2) {
            change_usename_UI(connecting_sockfd, UID);
            waiting_for_input();

        } else if (n == 3) {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();

        }
    }
}

void security_question_UI(int connecting_sockfd, std::string UID) {
    int n;

    while (1) {
        system("clear");
        std::cout << "密保问题" << std::endl;
        std::cout << "1.密保问题：" << std::endl;
        std::cout << "2.更改密保问题" << std::endl;
        std::cout << "3.返回" << std::endl;
        std::cout << "请输入：";
        std::cin >> n;
        if (n == 1) {
            system("clear");
            json j;
            j["type"] = "get_security_question";
            j["UID"] = UID;
            send_json(connecting_sockfd, j);
            usleep(50000);
            waiting_for_input();

        } else if (n == 2) {
            change_security_question_UI(connecting_sockfd, UID);

        } else if (n == 3) {
            return;

        } else {
            std::cout << "请正确输入选项！" << std::endl;
            waiting_for_input();

        }
    }
}

void waiting_for_input() {
    std::cout << "按回车键继续..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // 等待用户输入
}