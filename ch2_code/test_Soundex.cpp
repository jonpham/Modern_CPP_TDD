#include "gmock/gmock.h"    
#include "Soundex.h"

using namespace testing;
// Test Fixtures
// Each Test Fixture Class that derives from testing::Test is used for 
// a Specific TestCase which provides the Fixture Class Name

class SoundexEncoding: public Test {
public:
    Soundex soundex;
};


// Unit Tests
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) { 
    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadWithZerosToEnsureThreeDigits) {
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits) {
    ASSERT_THAT(soundex.encode("Ib"), Eq("I100")); 
    ASSERT_THAT(soundex.encode("Ic"), Eq("I200")); 
    ASSERT_THAT(soundex.encode("Id"), Eq("I300"));
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200")); 
}

TEST_F(SoundexEncoding, NegTestingIgnoreNonAlphabetics) {
    ASSERT_THAT(soundex.encode("A$"), Eq("A000"));
}
