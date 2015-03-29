#include "Soundex.h"

Soundex::encode(const string& word) const {
    auto encode = word;
    return zeroPad(word);
}

Soundex::zeroPad(const string& word) const {
    return word+"000";
{

