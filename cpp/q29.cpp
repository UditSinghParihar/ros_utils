#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

int main() {
  // Create an unordered_map of strings to ints
  std::unordered_map<std::string, int> unordered = {
    {"a", 1},
    {"b", 2},
    {"c", 3},
    {"d", 4}
  };

  // Define a custom comparator that compares the keys of the pairs in the unordered_map
  auto comparator = [](const auto& a, const auto& b) {
    return a.first < b.first;
  };

  // Sort the elements of the unordered_map using the std::sort algorithm and the custom comparator
  std::sort(unordered.begin(), unordered.end(), comparator);

  // Iterate over the unordered_map and print its elements
  for (const auto& [key, value] : unordered) {
    std::cout << key << ": " << value << std::endl;
  }

  return 0;

}
