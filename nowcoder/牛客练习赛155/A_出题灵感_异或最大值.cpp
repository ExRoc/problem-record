#include <bits/stdc++.h>
using namespace std;

struct Node {
    int year, month, day;

    Node() {}

    Node(int year, int month, int day) : year(year), month(month), day(day) {}

    bool operator<(const Node& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    Node to = Node(2026, 1, 9);
    while (T--) {
        Node from;
        cin >> from.year >> from.month >> from.day;
        if (!(from < to) && !(to < from)) {
            cout << from.year << " " << from.month << " " << from.day << '\n';
        } else {
            cout << "2026 1 8" << '\n';
        }
    }

    return 0;
}