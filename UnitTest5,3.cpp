#include "pch.h"
#include "CppUnitTest.h"
#include "../5,3/5,3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
    TEST_CLASS(UnitTest5)
    {
    public:

        // гілка |x| < 1 (ряд), x = 0: S = 1, exp(0) = 1 => p(0) = 1
        TEST_METHOD(TestSeriesBranch_Zero)
        {
            double t = p(0);
            Assert::AreEqual(1.0, t, 1e-9);
        }

        // гілка |x| < 1, x = 0.5: ряд для e^(-x) / e^x ≈ e^(-2x) = e^(-1)
        // (7 доданків ряду дають похибку ~1e-7)
        TEST_METHOD(TestSeriesBranch_Half)
        {
            double t = p(0.5);
            Assert::AreEqual(exp(-1.0), t, 1e-5);
        }

        // гілка |x| >= 1, x = 1
        TEST_METHOD(TestFormulaBranch_One)
        {
            double expected = (cos(1.0) + 1) / (sin(1.0) * sin(1.0) + exp(1.0));
            double t = p(1.0);
            Assert::AreEqual(expected, t, 1e-9);
        }

        // гілка |x| >= 1, від'ємне значення x = -2
        TEST_METHOD(TestFormulaBranch_NegativeTwo)
        {
            double expected = (cos(-2.0) + 1) / (sin(-2.0) * sin(-2.0) + exp(-2.0));
            double t = p(-2.0);
            Assert::AreEqual(expected, t, 1e-9);
        }
    };
}