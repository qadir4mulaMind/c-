#include <iostream>
#include <vector>
#include <algorithm>

struct Goblin {
    int health;
    Goblin(int h) : health(h) {}

    bool operator<(const Goblin& rhs) const {
        return this->health < rhs.health;
    }
};

int main() {
    std::vector<Goblin> goblin{Goblin(5), Goblin(3), Goblin(100)};
    
    std::sort(std::begin(goblin), std::end(goblin));
    
    for (auto g : goblin) {
        std::cout << g.health << std::endl;
    }
    
    return 0;
}

