#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void InsertSort(int* a, int n);
void InsertSort2(int* a, int n);
void ShellSort(int* a, int n);
void ShellSort2(int* a, int n);
void SelectSort(int* a, int n);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);
int Qsort1(int* a, int begin, int end);
int Qsort2(int* a, int begin, int end);
int Qsort3(int* a, int begin, int end);
void FastSort(int* a, int begin, int end);
void Msort(int* a, int* b, int begin, int end);
void MergeSort(int* a, int n);
void CountSort(int* a, int n);

void Printf(int* a,int n);
void Swap(int* a, int* b);
void ADjustdown(int* a,int n,int parent);
void Test();