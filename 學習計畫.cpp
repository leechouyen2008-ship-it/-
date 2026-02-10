#include <iostream>
using namespace std;

const int WIDTH = 5;
const int HEIGHT = 5;

// 玩家位置
int playerX = 0, playerY = 4;
// 綠豆湯店位置
int storeX = 3, storeY = 3;

// 障礙物位置
int wallX[5] = {1, 1, 2, 3, 4};
int wallY[5] = {1, 3, 2, 0, 4};  // 這裡我們設定了 5 個障礙物

// 顯示地圖
void showMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            bool isWall = false;
            for (int k = 0; k < 5; k++) {
                if (i == wallY[k] && j == wallX[k]) {
                    cout << "[牆]";  // 如果是障礙物，顯示為 [牆]
                    isWall = true;
                    break;
                }
            }
            if (!isWall) {
                if (i == playerY && j == playerX) {
                    cout << "[人]";  // 玩家
                } else if (i == storeY && j == storeX) {
                    cout << "[店]";  // 綠豆湯店
                } else {
                    cout << "[路]";  // 路徑
                }
            }
        }
        cout << endl;
    }
}

// 移動玩家
void movePlayer() {
    char move;
    cout << "你可以移動：w 上，s 下，a 左，d 右，q 退出: ";
    cin >> move;

    int newPlayerX = playerX;
    int newPlayerY = playerY;

    if (move == 'w') newPlayerY--;
    else if (move == 's') newPlayerY++;
    else if (move == 'a') newPlayerX--;
    else if (move == 'd') newPlayerX++;
    else if (move == 'q') {
        cout << "退出遊戲。\n";
        exit(0);
    }

    // 檢查是否超出邊界或撞到牆壁
    bool canMove = true;
    if (newPlayerX < 0 || newPlayerX >= WIDTH || newPlayerY < 0 || newPlayerY >= HEIGHT) {
        canMove = false;  // 超出邊界
    }

    for (int i = 0; i < 5; i++) {
        if (newPlayerX == wallX[i] && newPlayerY == wallY[i]) {
            canMove = false;  // 撞到牆壁
            break;
        }
    }

    if (canMove) {
        playerX = newPlayerX;
        playerY = newPlayerY;
    } else {
        cout << "無法移動，請選擇其他位置。\n";
    }
}

int main() {
    int y, n;
    cout << "有錢嗎(1/2): ";
    cout << "1為yes，2為no";
    cin >> y;

    if (y == 1) {
        cout << "可以前往綠豆湯店了" << endl;

        // 玩家必須成功到達綠豆湯店
        while (playerX != storeX || playerY != storeY) {
            showMap();  // 顯示地圖
            movePlayer();  // 移動玩家
        }

        cout << "成功抵達了你綠豆湯店!" << endl;

        cout << "還有沒有綠豆湯(1/2): ";
        cin >> n;

        if (n == 1) {
            cout << "可以買到綠豆湯了! 你要買幾杯: ";
            cin >> n;
            if (n == 1)
                cout << "老闆: 買那麼少來幹嘛??去死" << endl;
            else if (n >= 2)
                cout << "老闆: 太好了，看在你買那麼多的份上，算你買 " << n << " 送二吧" << endl;
        }
        else if (n == 2) {
            cout << "老闆說只剩下紅豆湯了，還要買嘛(1/2)? ";
            cin >> n;
            if (n == 1)
                cout << "成功喝到紅豆湯了，水啦！" << endl;
            else if (n == 2)
                cout << "什麼都沒喝到..." << endl;
            else
                cout << "工三小。" << endl;
        }
    }
    else if (y == 2) {
        cout << "跟同學借錢試試吧？同學願意借錢給你嗎(1/2)? ";
        cin >> n;

        if (n == 1) {
            cout << "真是善良的同學，可以去買綠豆湯了" << endl;
            cout << "有順利到達綠豆湯店嗎(1/2)? ";
            cin >> n;
            if (n == 1)
                cout << "太好了，也算是喝上綠豆湯了" << endl;
            else if (n == 2)
                cout << "完了，過馬路的時候被車撞死了，搶救無效，得年17" << endl;
        }
        else {  // 這裡的 else 改正了重複的 y == 2 判斷
            cout << "看來要運動一下了，開始打架" << endl;
            cout << "打贏了嗎(1/2)? ";
            cin >> n;
            if (n == 1)
                cout << "費了不少力也算是打贏了，讓輸的同學去跑腿吧" << endl;
            else if (n == 2)
                cout << "直接被同學打死了" << endl;
        }
    }
    else {
        cout << "想怎樣啦，都不要喝阿。" << endl;
    }

    return 0;
}
