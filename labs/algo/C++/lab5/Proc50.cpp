#include "iostream"

void TimeToHMS(int T, int& H, int& M, int& S) {
	H = trunc(T / 3600);
	M = trunc(T / 60) - (H * 60);
	S = T - (M * 60) - (H * 3600);
}

void main() {
	int H, M, S;
	TimeToHMS(109, H, M, S);

	std::cout << H << " " << M << " " << S;
}