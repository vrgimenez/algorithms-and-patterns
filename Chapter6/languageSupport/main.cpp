#include <iostream>
#include "JsonLanguageProvider.h"

int main() {
    JsonLanguageProvider langEs("lang/es.json");
    JsonLanguageProvider langEn("lang/en.json");
    JsonLanguageProvider langDe("lang/de.json");

    std::string raw = "{hello} John, {welcome} {home}!";

    std::cout << "English: " << langEn.translateTags(raw) << std::endl;
    std::cout << "Spanish: " << langEs.translateTags(raw) << std::endl;
    std::cout << "German: "  << langDe.translateTags(raw) << std::endl;
}