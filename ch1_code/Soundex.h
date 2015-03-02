#ifndef Soundex_h
#define Soundex_h
#include <string>

using namespace std;

class Soundex
{
public:
    string encode(const string& word) const {
        auto encoded = head(word)+encodedDigits(word);
        
        return zeroPad(encoded);
    } 

private:
    string zeroPad(const string& word) const {
        auto zerosNeeded = 4 - word.length();
        return word + string(zerosNeeded,'0');
    }
    
    string head(const string& word) const {
        return word.substr(0,1);   
    }

    string encodedDigits(const string& word) const {
        if (word.length() > 1) {
            return "1";
        }
        
        return "";
    }

};

#endif
