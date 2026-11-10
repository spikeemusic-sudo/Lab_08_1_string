#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../Lab_08_1_string/Lab_08_1_string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81str
{
    TEST_CLASS(UnitTest81str)
    {
    public:

        TEST_METHOD(TestInclude)
        {
            string str1 = "w_h_i_l_e";
            Assert::IsTrue(Include(str1));

            string str2 = "world_hello";
            Assert::IsFalse(Include(str2));
        }

        TEST_METHOD(TestChange)
        {
            string str = "abcwhilexyzwhile123";
            string dest = Change(str);

            // Виклик .c_str() усуває помилку C2338 при компіляції юніт-тесту
            Assert::AreEqual("abc**xyz**123", str.c_str());
            Assert::AreEqual("abc**xyz**123", dest.c_str());
        }
    };
}