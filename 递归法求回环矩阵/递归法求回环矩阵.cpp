#include<iostream>
using namespace std;

/**
 * function:求解螺旋矩阵
 * first:首元素（即矩阵左上角元素）的值
 * i:首元素（即矩阵左上角元素）的下标
 * n:子矩阵长度
 * m:螺旋矩阵
 */
void spiralmatrix(int first,int i, int n, int** m) {
	if (n == 1) {//n为1时，该子矩阵就一个元素，即first
		m[i][i] = first;
	}
	else if (n == 2) {//n为2时，该子矩阵首元素为first的螺旋矩阵，直接赋值即可
		m[i][i] = first;
		m[i][i + 1] = first + 1;
		m[i + 1][i + 1] = first + 2;
		m[i + 1][i] = first + 3;
	}
	/** 
	 * 当n>2时，情况比较复杂，左上角的值等于first，左下角的值等于first+3*(n-1),
	 * 然后按列补全第i行和第i+n-1行，其中第i行和第i+n-1行所有元素其中第i行是依次增1，第i+n-1行依次减1
	 * 然后再按行补齐第i列和第i+n-1列，其中第i行和第i+n-1行所有元素其中第i列是依次增1，第i+n-1列依次减1（按照从下向上填充）
	 * 最后外圈补齐后，进入内圈（利用递归法即可），这步的关键是求出左上角的元素值、左上角元素行下标、子矩阵长度
	 */
	else {
		m[i][i] = first;
		m[i + n - 1][i] = 3 * (n - 1) + first;
		for (int j = i + 1; j <= i + n - 1; j++){
			m[i + n - 1][j] = m[i + n - 1][j - 1] - 1;
			m[i][j] = m[i][j - 1] + 1;
		}
		for (int j = i + n - 2; j > i; j--) {
			m[j][i] = m[j + 1][i] + 1;
			m[j][i + n - 1] = m[j + 1][i + n - 1] - 1;
		}
		spiralmatrix(first + 4 * (n - 1), i + 1, n - 2, m);
	}
}

int main() {
	int** m;
	int n;
	cout << "请输入矩阵的维数：";
	cin >> n;
	m = new int* [n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
	}
	spiralmatrix(1, 0, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << "\t";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		delete[] m[i];
	}
	delete[] m;
}