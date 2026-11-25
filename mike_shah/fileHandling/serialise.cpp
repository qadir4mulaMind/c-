#include <iostream>
#include <fstream>

struct GameObject {
    int field1;
    short field2;
    bool active;
    char padding[1];

    GameObject(int _field1, short _field2, bool _active) 
        : field1(_field1), field2(_field2), active(_active) {}

    void serialize(std::ostream& os) const {
        // Fixed typos (fiel1 -> field1, fiel2 -> field2)
        os.write(reinterpret_cast<const char*>(&field1), sizeof(field1));
        os.write(reinterpret_cast<const char*>(&field2), sizeof(field2));
        os.write(reinterpret_cast<const char*>(&active), sizeof(active));
        os.write(padding, sizeof(padding));
    }

    void deserialize(std::istream& is) {
        is.read(reinterpret_cast<char*>(&field1), sizeof(field1));
        is.read(reinterpret_cast<char*>(&field2), sizeof(field2));
        is.read(reinterpret_cast<char*>(&active), sizeof(active));
        is.read(padding, sizeof(padding));
    }
};

std::ostream& operator<<(std::ostream& os, const GameObject& go) {
    os << go.field1 << "," << go.field2 << "," << go.active;
    return os;
}

void test0() {
  {
    std::cout << "sizeof game object: " << sizeof(GameObject) << std::endl;
    GameObject go(50, 23, true);
    std::cout << go << std::endl;
    
    std::ofstream text_file("text.txt");
    text_file << go << std::endl;
    
    std::ofstream binary_file("text.bin", std::ios::binary);
    go.serialize(binary_file);
  }
  {
    GameObject go(0, 0, 0);
    std::ifstream input_binary_file("text.bin", std::ios::binary);
    go.deserialize(input_binary_file);
    std::cout << "Deserialized: " << go << std::endl; 
  }

}

int main() {
    test0();
    return 0;
}

