#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point &other) const { return x == other.x && y == other.y; }
};

struct PointHash {
    size_t operator()(const Point &p) const {
        return (uint64_t(uint32_t(p.x)) << 32) ^ uint32_t(p.y);
    }
};

struct SegmentKey {
    int x, y, id;
    bool operator==(const SegmentKey &other) const {
        return x == other.x && y == other.y && id == other.id;
    }
};

struct SegmentHash {
    size_t operator()(const SegmentKey &k) const {
        uint64_t h = k.x;
        h = (h << 21) ^ k.y;
        h = (h << 21) ^ k.id;
        return size_t(h);
    }
};

class GravitySimulator {
    int segmentCount;
    vector<array<int, 4>> segments;
    int startX, startY, energy;
    unordered_map<Point, vector<int>, PointHash> grid;
    unordered_map<SegmentKey, pair<int, int>, SegmentHash> nextStep;

public:
    GravitySimulator(const vector<long long>& input) {
        int idx = 0;
        segmentCount = (int)input[idx++];
        segments.resize(segmentCount);
        for (int i = 0; i < segmentCount; ++i) {
            segments[i][0] = (int)input[idx++];
            segments[i][1] = (int)input[idx++];
            segments[i][2] = (int)input[idx++];
            segments[i][3] = (int)input[idx++];
        }
        startX = (int)input[idx++];
        startY = (int)input[idx++];
        energy = (int)input[idx++];
        buildGrid();
    }

    void buildGrid() {
        for (int id = 0; id < segmentCount; ++id) {
            int x1 = segments[id][0], y1 = segments[id][1];
            int x2 = segments[id][2], y2 = segments[id][3];
            int dx = (x2 > x1) ? 1 : -1;
            int dy = (y2 > y1) ? 1 : -1;
            int length = abs(x2 - x1);

            if (dy == -1) {
                for (int k = 0; k < length; ++k) {
                    int x = x1 + dx * k;
                    int y = y1 - k;
                    grid[{x, y}].push_back(id);
                    nextStep[{x, y, id}] = {x + dx, y - 1};
                }
                grid[{x2, y2}].push_back(id);
            } else {
                for (int k = 0; k < length; ++k) {
                    int x = x2 - dx * k;
                    int y = y2 - k;
                    grid[{x, y}].push_back(id);
                    nextStep[{x, y, id}] = {x - dx, y - 1};
                }
                grid[{x1, y1}].push_back(id);
            }
        }
    }

    pair<int, int> simulateFall(int x, int y) {
        for (int yy = y - 1; yy >= 0; --yy) {
            auto it = grid.find({x, yy});
            if (it != grid.end()) return {x, yy};
        }
        return {x, 0};
    }

    pair<int, int> runSimulation() {
        int x = startX, y = startY;
        if (grid.find({x, y}) == grid.end()) {
            tie(x, y) = simulateFall(x, y);
        }

        while (true) {
            if (y == 0) break;
            auto it = grid.find({x, y});
            if (it == grid.end()) {
                tie(x, y) = simulateFall(x, y);
                continue;
            }

            auto& ids = it->second;
            if (ids.size() == 1) {
                int id = ids[0];
                auto it2 = nextStep.find({x, y, id});
                if (it2 == nextStep.end()) {
                    tie(x, y) = simulateFall(x, y);
                    continue;
                }
                if (energy == 0) break;
                energy--;
                x = it2->second.first;
                y = it2->second.second;
            } else {
                long long cost = 1LL * x * y;
                vector<pair<int, pair<int, int>>> candidates;
                for (int id : ids) {
                    auto it3 = nextStep.find({x, y, id});
                    if (it3 != nextStep.end()) {
                        candidates.push_back({id, it3->second});
                    }
                }

                if ((long long)energy <= cost) {
                    if (candidates.empty()) {
                        tie(x, y) = simulateFall(x, y);
                        continue;
                    }
                    break;
                }

                energy -= (int)cost;
                if (candidates.empty()) {
                    tie(x, y) = simulateFall(x, y);
                    continue;
                }

                int bestX = 0, bestY = -1;
                for (auto& c : candidates) {
                    int nx = c.second.first;
                    int ny = c.second.second;
                    if (ny > bestY) {
                        bestY = ny;
                        bestX = nx;
                    }
                }

                if (energy == 0) break;
                energy--;
                x = bestX;
                y = bestY;
            }
        }

        return {x, y};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> input;
    long long val;
    while (cin >> val) input.push_back(val);

    GravitySimulator simulator(input);
    auto [finalX, finalY] = simulator.runSimulation();
    cout << finalX << " " << finalY << "\n";
    return 0;
}
