#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <set>
#include <fstream>

using InvertedIndex = std::unordered_map<std::string, std::set<int>>;

// Build the inverted index from the content of the files
InvertedIndex buildIndex(const std::vector<std::string>& docs) {
    InvertedIndex index;
    for (int id = 0; id < (int)docs.size(); ++id) {
        std::istringstream iss(docs[id]);
        std::string word;
        while (iss >> word)
            index[word].insert(id);
    }
    return index;
}

// Intersection or multiples sets (AND Search)
std::set<int> searchAND(const InvertedIndex& index, const std::vector<std::string>& words) {
    std::set<int> res;
    if (words.empty()) return res;

    auto it = index.find(words[0]);
    if (it == index.end()) return res;
    res = it->second;

    for (size_t i = 1; i < words.size(); ++i) {
        auto it2 = index.find(words[i]);
        if (it2 == index.end()) {
            res.clear();
            break;
        }

        std::set<int> inter;
        for (int id : res)
            if (it2->second.count(id))
                inter.insert(id);
        res = std::move(inter);
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " archive1 archive2 ... word1 word2 ...\n";
        return 1;
    }

    // Detect Files and where search words starts
    // Check for the first value that does not have a file
    int split = 1;
    for (; split < argc; ++split) {
        std::ifstream test(argv[split]);
        if (!test.good()) break;
    }

    // Read Docs
    std::vector<std::string> docs;
    for (int i = 1; i < split; ++i) {
        std::ifstream file(argv[i]);
        if (!file) {
            std::cerr << "Could not open " << argv[i] << "\n";
            return 1;
        }
        std::ostringstream buffer;
        buffer << file.rdbuf();
        docs.push_back(buffer.str());
    }

    // words search
    std::vector<std::string> words;
    for (int i = split; i < argc; ++i)
        words.push_back(argv[i]);

    if (words.empty()) {
        std::cerr << "You must specify at least one search word\n";
        return 1;
    }

    // Construir índice y buscar
    auto index = buildIndex(docs);
    auto res = searchAND(index, words);

    std::cout << "Documents that contain all the words:\n";
    for (int id : res)
        std::cout << "- " << argv[1 + id] << "\n";

    return 0;
}