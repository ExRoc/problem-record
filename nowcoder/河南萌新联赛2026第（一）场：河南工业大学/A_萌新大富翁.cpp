#include <bits/stdc++.h>
using namespace std;

struct Player {
    long long c;
    int gridIdx;
    bool bankrupt, pause;
    vector<int> estates;
};

struct Grid {
    int type;
    int whos;
    long long price, toll;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Player> players(n);
    list<int> playersIdx;
    for (int i = 0; i < n; ++i) {
        cin >> players[i].c;
        players[i].gridIdx = 0;
        players[i].bankrupt = false;
        players[i].pause = false;
        playersIdx.push_back(i);
    }
    vector<Grid> grids(m);
    for (int i = 0; i < m; ++i) {
        cin >> grids[i].type;
        if (grids[i].type == 1) {
            grids[i].whos = -1;
            cin >> grids[i].price >> grids[i].toll;
        }
    }
    int k;
    cin >> k;
    list<int>::iterator playerIdx = playersIdx.begin();
    for (int i = 0; i < k; ++i) {
        if ((int)playersIdx.size() == 1) {
            break;
        }
        Player& player = players[*playerIdx];
        if (player.pause) {
            player.pause = false;
            --i;
            ++playerIdx;
            if (playerIdx == playersIdx.end()) {
                playerIdx = playersIdx.begin();
            }
            continue;
        }
        int d;
        cin >> d;
        player.gridIdx = (player.gridIdx + d) % m;
        Grid& grid = grids[player.gridIdx];
        switch (grid.type) {
            case 0:
                player.c += 200;
                break;
            case 1:
                if (grid.whos == -1 && player.c >= grid.price) {
                    player.c -= grid.price;
                    grid.whos = *playerIdx;
                    player.estates.push_back(player.gridIdx);
                } else if (grid.whos != -1 && grid.whos != *playerIdx) {
                    players[grid.whos].c += min(player.c, grid.toll);
                    player.c -= grid.toll;
                }
                break;
            case 2:
                player.c += 150;
                break;
            case 3:
                player.c -= 100;
                break;
            case 4:
                player.pause = true;
                break;
            default:
                break;
        }
        if (player.c >= 0) {
            ++playerIdx;
            if (playerIdx == playersIdx.end()) {
                playerIdx = playersIdx.begin();
            }
            continue;
        }
        player.bankrupt = true;
        for (int estate : player.estates) {
            grids[estate].whos = -1;
        }
        player.estates.clear();
        list<int>::iterator playerIdxTmp = playerIdx;
        ++playerIdxTmp;
        playersIdx.erase(playerIdx);
        playerIdx = playerIdxTmp;
        if (playerIdx == playersIdx.end()) {
            playerIdx = playersIdx.begin();
        }
    }
    for (int i = 0; i < n; ++i) {
        if (players[i].bankrupt) {
            cout << "bankrupt 0" << '\n';
        } else {
            cout << players[i].c << " " << players[i].estates.size() << '\n';
        }
    }

    return 0;
}