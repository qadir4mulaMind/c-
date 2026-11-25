#include <iostream>
#include <vector>
#include <numeric>   
#include <string>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    // 1. Default Sum
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Sum: " << sum << std::endl; 

    // 2. Product
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << std::endl; 

    // 3. String Concatenation (Fixed)
    std::vector<std::string> words{"C++", "is", "awesome"};
    
    // Range ab words.begin() + 1 se words.end() tak hai
    std::string sentence = std::accumulate(words.begin() + 1, words.end(), words[0], [](const std::string& a, const std::string& b) {
        return a + " " + b;
    });
    
    std::cout << "Sentence: " << sentence << std::endl; 

    return 0;
}

