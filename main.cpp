#include <iostream>
#include <cstring>
#include <cstdlib>

#include "list.h"

using namespace std;

void showMenu();

int main() {
    List stu;
    LinkList L = nullptr;
    int menu = 1, num;     //菜单选项
    int flag = 0;   //通讯录是否建立

    while (menu != 0) {
        showMenu();
        cout << "请选择功能：";
        cin >> menu;
        switch (menu) {
            case 1: {
                L = stu.CreatIncreLink();
                cout << "建立通讯录：";
                stu.PrintList(L);
                flag = 1;
                break;
            }
            case 2: {
                if (flag == 1) {
                    int number, telenum;
                    char name[20];
                    cout << "请输入通讯者的学号，姓名和电话号码：" << endl;
                    cout << "请输入学号：";
                    cin >> number;
                    cout << "请输入姓名：";
                    cin >> name;
                    cout << "请输入电话号码：";
                    cin >> telenum;;
                    LinkList p = new LNode;
                    p->number = number;
                    strcpy(p->name, name);
                    p->telenum = telenum;
                    stu.InsertYouXu(L, p);
                    cout << "插入后：";
                    stu.PrintList(L);
                } else
                    cout << "\nERROR: 通讯录还没有建立，请先建立通讯录" << endl;
                cout << "如需继续插入，请输入1，否则返回主菜单：";
                cin >> num;
                if (num == 1)
                    continue;
                else
                    break;
            }
            case 3: {
                int way, n, s;     //查找方式
                if (L != NULL) {
                    if (flag)   //通讯录已建立
                    {
                        cout << "选择查找方式：" << endl;
                        cout << "           1.按学号  2.按姓名" << endl;
                        cout << "查找方式：";
                        cin >> way;
                        if (way == 1) {
                            cout << "\n请输入学号：";
                            cin >> n;
                            s = stu.Search(L, n);  //查找通讯录成员
                            if (s == 0)
                                cout << "无此通讯者，查找失败！" << endl;
                        } else if (way == 2) {
                            char na[20];
                            cout << "\n请输入姓名：";
                            cin >> na;
                            s = stu.Search(L, na);
                            if (s == 0)
                                cout << "无此通讯者，查找失败！" << endl;
                        } else
                            cout << "通讯录中无记录！" << endl;
                    }
                    //break;
                    cout << "如需继续查询，请输入1，否则返回主菜单：";
                    cin >> num;
                    if (num == 1)
                        continue;
                    else
                        break;
                } else
                    cout << "通讯录中无记录！" << endl;
                //break;
                cout << "如需继续查找，请输入1，否则返回主菜单：";
                cin >> num;
                if (num == 1)
                    continue;
                else
                    break;
            }
            case 4: {
                int way;      //删除方式
                cout << "选择删除方式：1.按序号  2.按学号  3.按姓名" << endl;
                cin >> way;
                if (way == 1) {
                    int n;
                    cout << "请输入通讯录序号：";
                    cin >> n;
                    cout << "删除后：" << endl;
                    stu.DeleteELem(L, n);
                    stu.PrintList(L);
                } else if (way == 2) {
                    int n, f;
                    cout << "\n请输入学号：";
                    cin >> n;
                    f = stu.DelMsg(L, n);
                    if (f != 0) {
                        cout << "删除后：" << endl;
                        stu.PrintList(L);
                    } else
                        cout << "无该学号，删除失败！" << endl;
                } else if (way == 3) {
                    char na[20];
                    int f;
                    cout << "请输入姓名：";
                    cin >> na;
                    f = stu.DelMsg(L, na);
                    if (f != 0) {
                        cout << "删除后：" << endl;;
                        stu.PrintList(L);
                    } else
                        cout << "无该姓名，删除失败！" << endl;
                } else
                    cout << "ERROR!!" << endl;

                cout << "如需继续删除，请输入1，否则返回主菜单：";
                cin >> num;
                if (num == 1)
                    continue;
                else
                    break;
            }
            case 5: {
                cout << "当前通讯录内容如下：" << endl;
                stu.PrintList(L);       //打印通讯录
                break;
            }
            case 0:
                exit(0);
            default:
                cout << "\n没有此功能，重新输入\n";
        }
        cout << "选择功能：";
        cin >> menu;
    }
}

void showMenu() {
    cout << "\n         *********** 欢迎使用通讯录系统******************\n";
    cout << "         *              1 通讯录的建立                      *\n";
    cout << "         *              2 插入通讯记录                      *\n";
    cout << "         *              3 查询通讯记录                      *\n";
    cout << "         *              4 删除通讯记录                      *\n";
    cout << "         *              5 显示通讯录信息                    *\n";
    cout << "         *              0 退出管理系统                      *\n";
    cout << "         *  **********************************************  *\n";

}
