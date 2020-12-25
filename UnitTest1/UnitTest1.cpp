#include "CppUnitTest.h"
#include "..\АлгСтр, лабораторная 2, сем 3\Header.h"
#include "..\АлгСтр, лабораторная 2, сем 3\Prog.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		int* Array;
		TEST_METHOD_INITIALIZE(setUp) {
			Array = new int[10];
			for (int i = 0; i < 10; i++) {
				Array[i] = rand();
			}
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete[] Array;
		}

		TEST_METHOD(check_Sorted) {
			Assert::IsFalse(Sorted(Array, 10));
		}

		TEST_METHOD(check_Sorted_2) {
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			} 
			Assert::IsTrue(Sorted(Array, 10));
		} 
		
		TEST_METHOD(check_BinarySearch_notfound) {
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			}
			try {
				BinarySearch(Array, 21, 10);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Impossible to find", e.what());
			}
		}

		TEST_METHOD(check_BinarySearch_found) {
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			}
			Assert::AreEqual(BinarySearch(Array, 10, 5), 5);
		}

		TEST_METHOD(check_QuickSort) {
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			QuickSort(Array, 10);
			Assert::IsTrue(Sorted(Array, 10));
		}

		TEST_METHOD(check_QuickSort_2) {
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			Array[8] = 7;
			QuickSort(Array, 10);
			Assert::IsTrue(Sorted(Array, 10));
		}

		TEST_METHOD(check_InsertionSort) {
			for (int i = 9; i >= 0; i--) { 
				Array[i] = i; 
			} 
			InsertionSort(Array, 10); 
			Assert::IsTrue(Sorted(Array, 10)); 
		} 
		
		TEST_METHOD(check_InsertionSort_2) {
			for (int i = 9; i >= 0; i--) { 
				Array[i] = i; 
			} 
			Array[8] = 7; 
			InsertionSort(Array, 10); 
			Assert::IsTrue(Sorted(Array, 10)); 
		}

		TEST_METHOD(check_BogoSort) {
			for (int i = 9; i >= 0; i--) { 
				Array[i] = i; 
			}
			BogoSort(Array, 10);
			Assert::IsTrue(Sorted(Array, 10));
		} 
		
		TEST_METHOD(check_BogoSort_2) {
			for (int i = 0; i < 10; i++) {
				Array[9 - i] = i;
			}
			BogoSort(Array, 10);
			Assert::AreEqual(Array[0], 0);
		}
		
		TEST_METHOD(check_CountingSort) {
			char array_char[] = { '3', '0', '1', '2', '3', '4', '1', 'a' }; 
			CountingSort(array_char, 8); 
			Assert::IsTrue(Sorted(array_char, 7)); 
		} 
		
		TEST_METHOD(check_CountingSort_2) {
			char array_char[] = { '3', '0', '1', '2', '3', '4', '1', 'a' }; 
			CountingSort(array_char, 8); 
			Assert::AreEqual(array_char[0], '0'); 
		}
	};
}
