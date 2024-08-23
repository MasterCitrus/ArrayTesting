#include "pch.h"
#include "CppUnitTest.h"
#include "Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<typename T> inline std::wstring ToString(const Array<T>& t)
{
	auto str = t.ToString();

	std::wstring ws(str.length() + 1, L' ');

	size_t size = 0;
	mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());
	ws.resize(size);
	return ws;
}

namespace ArrayUnitTest
{
	TEST_CLASS(ArrayTests)
	{
	public:
		//Test Find function
		TEST_METHOD(Find)
		{
			Array<int> test{ 1, 2, 3, 4, 5 };
			int actual = *test.Find(3);
			Assert::AreEqual(3, actual);
		}

		//Test Push Back function
		TEST_METHOD(PushBack)
		{
			Array<int> test{ 1, 2, 3, 4, 5 };
			test.PushBack(6);
			int actual = test.Back();
			Assert::AreEqual(6, actual);
			Assert::AreEqual(6, (int)test.Size());
		}

		//Check if Array clears
		TEST_METHOD(Clear)
		{
			Array<int> test{ 1, 2, 3, 4, 5 };
			test.Clear();
			bool actual = test.Empty();
			Assert::AreEqual(true, actual);
		}

		//Check if more capacity is allocated
		TEST_METHOD(Allocate)
		{
			Array<int> test{1, 2, 3, 4, 5};
			test.Allocate(5);
			int actual = test.Capacity();
			Assert::AreEqual(10, actual);
		}

		//check if capacity is deallocated
		TEST_METHOD(Deallocate)
		{
			Array<int> test{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			test.Deallocate(5);
			int actual = test.Capacity();
			Assert::AreEqual(5, actual);
		}

		//Check if item is inserted in position
		TEST_METHOD(Insert)
		{
			Array<int> test{ 1, 2, 3, 4, 5 };
			test.Insert(test.begin() + 3, 7);
			bool actualB;
			if (test.Find(7) != test.end()) actualB = true;
			else actualB = false;
			Assert::AreEqual(true, actualB);
			Assert::AreEqual(3, (int)(test.Find(7) - test.begin()));
			Assert::AreEqual(6, (int)test.Size());
		}

		//Check if last item is removed
		TEST_METHOD(PopBack)
		{
			Array<int> test{ 1, 2, 3, 4, 5 };
			test.PopBack();
			bool actual;
			if (test.Find(5) == test.end()) actual = false;
			else actual = true;
			Assert::AreEqual(false, actual);
		}

		//Check if item is removed
		TEST_METHOD(RemoveUnordered)
		{
			Array<int> test{ 1, 2, 3, 4, 5 };
			test.RemoveUnordered(test.Find(2));
			bool actual;
			if (test.Find(2) == test.end()) actual = true;
			else actual = false;
			Assert::AreEqual(true, actual);
		}
	};
}
