#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <algorithm>

// Generic template for any vector type
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i + 1 < vec.size())
            os << ", ";
    }
    os << "]";
    return os;
}

std::vector<std::string> tokenize(const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> tokens;
    std::string word;
    while (iss >> word) {
        // Lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        // Remove signs
        word.erase(std::remove_if(word.begin(), word.end(),
            [](unsigned char c){ return ispunct(c); }), word.end());
        tokens.push_back(word);
    }
    return tokens;
}

// Product between 2 vectors
double dot(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i)
        result += a[i] * b[i];
    return result;
}

// MMagnitude of the vector
double magnitude(const std::vector<double>& v) {
    double sum = 0.0;
    for (double x : v) sum += x * x;
    return std::sqrt(sum);
}

// Cosine similarity
double cosine_similarity(const std::vector<double>& a, const std::vector<double>& b) {
    return dot(a,b) / (magnitude(a) * magnitude(b) + 1e-9);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " archive1 archive2 ... phrase\n";
        return 1;
    }
    std::cout << std::endl;

    // Detect Files and where search words starts
    // Check for the first value that does not have a file
    int split = 1;
    std::vector<std::string> filenames;
    for (; split < argc; ++split) {
        auto filename = argv[split];
        std::ifstream test(filename);
        if (!test.good()) break;
        filenames.push_back(filename);
    }

    // Read Docs
    std::vector<std::string> docs;
    for (auto &fileName: filenames) {
        std::ifstream file(fileName);
        if (!file) {
            std::cerr << "Could not open " << fileName << "\n";
            return 1;
        }
        std::ostringstream buffer;
        buffer << file.rdbuf();
        docs.push_back(buffer.str());
    }

    std::cout << "Document files : " << filenames  << std::endl;

    // Search Phrase
    std::string query;
    bool firstWordInQuery = true;
    for (int i = split; i < argc; ++i) {
        query += std::string(firstWordInQuery ? ""  : " ")  + argv[i];
        firstWordInQuery = false;
    }
    
    // Build Vocabulary
    std::set<std::string> vocabSet;
    std::vector<std::vector<std::string>> tokenizedDocs;

    for (auto& doc : docs) {
        auto tokens = tokenize(doc);
        tokenizedDocs.push_back(tokens);
        vocabSet.insert(tokens.begin(), tokens.end());
        std::cout << "Tokenization: " << tokens << std::endl;
    }

    std::vector<std::string> vocab(vocabSet.begin(), vocabSet.end());
    std::map<std::string, int> vocabIndex;
    for (size_t i = 0; i < vocab.size(); ++i) { vocabIndex[vocab[i]] = i; }

    // Convert documents to TF vectors (frecuency)
    std::vector<std::vector<double>> docVectors;
    for (auto& tokens : tokenizedDocs) {
        std::vector<double> vec(vocab.size(), 0.0);
        for (auto& w : tokens)
            vec[vocabIndex[w]]++;
        docVectors.push_back(vec);
    }

    std::cout << "Documents TF: " << docVectors << std::endl;
    std::cout << "Full vocabulary: " << vocab << std::endl;
    
     // Calculate cosine similarity between the query and the documents
    std::cout << "\nPhrase to query: \"" << query << "\"\n\n";
    
    // Convert query to vector
    auto qTokens = tokenize(query);

    // Query to vocabulary embedding
    std::vector<double> qVec(vocab.size(), 0.0);
    for (auto& w : qTokens) { if (vocabIndex.count(w)) qVec[vocabIndex[w]]++; }
    std::cout << "Query to vocabulary Embedding " << qVec << std::endl;

    for (size_t i = 0; i < docs.size(); ++i) {
        double sim = cosine_similarity(qVec, docVectors[i]);
        std::cout << "Similitude with doc[" << i << "](" << filenames[i] << ")=" << sim << "\n";
    }

    // Show most similar doc
    std::vector<double> docEmbedding;
    auto bestIt = std::max_element(docVectors.begin(), docVectors.end(), [&](const std::vector<double>& a, const std::vector<double>& b) {
        return cosine_similarity(qVec, a) < cosine_similarity(qVec, b);
    });

    size_t bestIdx = std::distance(docVectors.begin(), bestIt);
    std::cout << "\nMost similar document[" << bestIdx << "](" << filenames[bestIdx] << ")=" << docVectors[bestIdx] << ") -> " << docs[bestIdx] << "\n";

    return 0;
}
