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
    // Class Variables
    static const size_t MaxCodeLength{4};

    string zeroPad(const string& word) const {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + string(zerosNeeded,'0');
    }
    
    string head(const string& word) const {
        return word.substr(0,1);   
    }

    string encodedDigits(const string& word) const {
        if (word.length() > 1) {
            return encodedDigit(word[1]);
        }
        
        return "";
    }

    string encodedDigit(char letter) const {
        if (letter == 'b') return "1";
        else if (letter == 'c') return "2";
        else
        return "";
    }
};

#endif
