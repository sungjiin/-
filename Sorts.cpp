// SelectedSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 선택 정렬, 삽입 정렬, 버블 정렬, 쉘 정렬 구현 및 시간 비교

#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

//출력
void PrintArr(int arr[], int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << ']';
	cout << '\n';
};

// 배열 값 스왑
void Swap(int arr[], int x, int y) {

	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;

}

// 랜덤 배열
void RandArr(int *arr, int size) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		int num = rand();
		int data = num % size;
		arr[i] = data;
	}
}

//정배열
void Sequence(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

//역배열
void reverseRecursive(int a[], int begin, int end) {
	if (begin < end)
	{
		Swap(a, begin, end);
		reverseRecursive(a, begin + 1, end - 1);
	}
}

// 배열 섞기
void Shuffle(int *arr, int size) {
	srand((int)time(NULL));
	for (int i = size - 1; i >= 0; i--) {
		int n = rand() % size;
		Swap(arr, i, n);
	}
}

// 선택 정렬
void Selection_Sort(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j])
				Swap(arr, i, j);
		}
	}
}

// 버블 정렬
void Bubble_Sort(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(arr, j, j + 1);
			}
		}
	}
}

//삽입 정렬
void Insert_Sort(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j - 1] > arr[j]) {
				Swap(arr, j - 1, j);
			}
			else break;
		}
	}
}

void Shell_Sort(int *arr, int size) {
	int i, j, h, v;
	//h는 최대 간격
	for (h = 0; h < size - 1; h = 3 * h + 1);
	//최대 간격을 3으로 나눈 몫을 간격으로 줄여감
	for (; h > 0; h /= 3) {
		for (i = h; i < size; i = i++) {
			v = arr[i];
			j = i;
			//간격마다 정렬
			while (j >= h && arr[j - h] > v) {
				arr[j] = arr[j - h];
				j -= h;
			}
			arr[j] = v;
		}
	}
}

void reverse(int *arr, int size) {
	int x = 99999;
	for (int i = 0; i < size; i++) {
		arr[i] = x;
		x--;
	}
}


//메인 함수
void main()
{
	int arr[1000];
	int length = sizeof(arr) / sizeof(int);


	//랜덤 배열 시간 비교
	RandArr(arr, length);
	clock_t begin_shell, end_shell;
	begin_shell = clock();
	cout << "Shell_Sort 랜덤 배열" << endl;
	Shell_Sort(arr, length);
	end_shell = clock();
	cout << "수행시간 : " << ((end_shell - begin_shell) / CLOCKS_PER_SEC) << endl << endl;

	RandArr(arr, length);
	clock_t begin_insert, end_insert;
	begin_insert = clock();
	cout << "Insert_Sort 랜덤 배열" << endl;
	Insert_Sort(arr, length);
	end_insert = clock();
	cout << "수행시간 : " << ((end_insert - begin_insert) / CLOCKS_PER_SEC) << endl << endl;


	RandArr(arr, length);
	clock_t begin_selection, end_selection;
	begin_selection = clock();
	cout << "Selection_Sort 랜덤 배열" << endl;
	Selection_Sort(arr, length);
	end_selection = clock();
	cout << "수행시간 : " << ((end_selection - begin_selection) / CLOCKS_PER_SEC) << endl << endl;

	RandArr(arr, length);
	clock_t begin_bubble, end_bubble;
	begin_bubble = clock();
	cout << "Bubble_Sort 랜덤 배열" << endl;
	Bubble_Sort(arr, length);
	end_bubble = clock();
	cout << "수행시간 : " << ((end_bubble - begin_bubble) / CLOCKS_PER_SEC) << endl << endl;


	//역배열 시간 비교
	reverse(arr, length);
	clock_t begin_shell, end_shell;
	begin_shell = clock();
	cout << "Shell_Sort 역배열" << endl;
	Shell_Sort(arr, length);
	end_shell = clock();
	cout << "수행시간 : " << ((end_shell - begin_shell) / CLOCKS_PER_SEC) << endl << endl;

	reverse(arr, length);
	clock_t begin_insert, end_insert;
	begin_insert = clock();
	cout << "Insert_Sort 역배열" << endl;
	Insert_Sort(arr, length);
	end_insert = clock();
	cout << "수행시간 : " << ((end_insert - begin_insert) / CLOCKS_PER_SEC) << endl << endl;

	reverse(arr, length);
	clock_t begin_selection, end_selection;
	begin_selection = clock();
	cout << "Selection_Sort 역배열" << endl;
	Selection_Sort(arr, length);
	end_selection = clock();
	cout << "수행시간 : " << ((end_selection - begin_selection) / CLOCKS_PER_SEC) << endl << endl;

	reverse(arr, length);
	clock_t begin_bubble, end_bubble;
	begin_bubble = clock();
	cout << "Bubble_Sort 역배열" << endl;
	Bubble_Sort(arr, length);
	end_bubble = clock();
	cout << "수행시간 : " << ((end_bubble - begin_bubble) / CLOCKS_PER_SEC) << endl << endl;


	//정배열 시간 비교
	Sequence(arr, length);
	clock_t begin_shell, end_shell;
	begin_shell = clock();
	cout << "Shell_Sort 정배열" << endl;
	Shell_Sort(arr, length);
	end_shell = clock();
	cout << "수행시간 : " << ((end_shell - begin_shell) / CLOCKS_PER_SEC) << endl << endl;

	Sequence(arr, length);
	clock_t begin_insert, end_insert;
	begin_insert = clock();
	cout << "Insert_Sort 정배열" << endl;
	Insert_Sort(arr, length);
	end_insert = clock();
	cout << "수행시간 : " << ((end_insert - begin_insert) / CLOCKS_PER_SEC) << endl << endl;

	Sequence(arr, length);
	clock_t begin_selection, end_selection;
	begin_selection = clock();
	cout << "Selection_Sort 정배열" << endl;
	Selection_Sort(arr, length);
	end_selection = clock();
	cout << "수행시간 : " << ((end_selection - begin_selection) / CLOCKS_PER_SEC) << endl << endl;

	Sequence(arr, length);
	clock_t begin_bubble, end_bubble;
	begin_bubble = clock();
	cout << "Bubble_Sort 정배열" << endl;
	Bubble_Sort(arr, length);
	end_bubble = clock();
	cout << "수행시간 : " << ((end_bubble - begin_bubble) / CLOCKS_PER_SEC) << endl << endl;

}
