#include "stdafx.h"
#include "CppUnitTest.h"
#include "Classes.h"
#include "Classes.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here

			double ** matrix = new double*[4];
			for (int i = 0; i < 4; i++)
			{
				matrix[i] = new double[7];
				for (int j = 0; j < 7; j++)
					matrix[i][j] = j;
			}
			Holder<double> ex = Holder<double>(4, 7);

			ex = matrix;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 7; j++)
					Assert::AreEqual((double)ex[i][j].key, (double)matrix[i][j]);
			}
		}

		TEST_METHOD(TestMethod1)
		{
			ex[1][0] = 0;
			Assert::AreEqual(ex[1][0].key, (double)0);
		}

	};
}