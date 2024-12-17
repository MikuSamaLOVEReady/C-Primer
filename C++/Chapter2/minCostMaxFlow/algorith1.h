//
// Created by ����� on 2024/9/19.
//

#ifndef CHAPTER7_ALGORITH1_H
#define CHAPTER7_ALGORITH1_H


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_NODES = 1000;

// ͼ����������
int capacity[MAX_NODES][MAX_NODES];

// Edmonds-Karp ʵ�ֵ����������
int bfs(int source, int sink, vector<int>& parent, int nodes) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = source;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 0; next < nodes; ++next) {
            if (parent[next] == -1 && capacity[cur][next] > 0) { // �ҵ�δ���ʵĽڵ㣬�Ҵ���ʣ������
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == sink)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int Karp(int source, int sink, int nodes) {
    int flow = 0;
    vector<int> parent(nodes);

    int new_flow;

    while (new_flow = bfs(source, sink, parent, nodes)) {
        flow += new_flow;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow; // ��������ߵ�����
            capacity[cur][prev] += new_flow; // ���·���ߵ�����
            cur = prev;
        }
    }

    return flow;
}

int main_mintset() {
    int nodes = 6; // �ڵ���
    memset(capacity, 0, sizeof(capacity));

    // ��ʼ�����磬��ӱ��Լ����ǵ�����
    // ͼ�Ľṹ����:
    // source --(10)--> 1 --(5)--> 2 --(10)--> sink
    //  source --(10)--> 3 --(15)--> 2
    //  1 --(10)--> 3 --(10)--> sink

    capacity[0][1] = 10;  // source -> 1
    capacity[0][3] = 10;  // source -> 3
    capacity[1][2] = 5;   // 1 -> 2
    capacity[1][3] = 10;  // 1 -> 3
    capacity[3][2] = 15;  // 3 -> 2
    capacity[2][5] = 10;  // 2 -> sink
    capacity[3][5] = 10;  // 3 -> sink

    int source = 0, sink = 5; // ����Դ��ͻ��

    cout << "The maximum possible flow is " << Karp(source, sink, nodes) << endl;

    return 0;
}



#endif //CHAPTER7_ALGORITH1_H
