#include <stdio.h>

int main() {
	FILE* src = fopen("src.bin", "rb");
	FILE* des = fopen("des.bin", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	while (1) {
		// 파일로부터 데이터를 읽어들이는데, 총 1 * sizeof(buf)의 데이터 크기를 읽어들인다.
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		
		if (readCnt < sizeof(buf)) { // 확실하게 모든 것을 읽어들였다면 readCnt는 sizeof(buf)와 크기가 같지만 아니라면 작다.
			if (feof(src) != 0) { // 파일의 끝에 도달했는지 체크해주고,
				fwrite((void*)buf, 1, readCnt, des); // 비록 적은 수의 바이트가 읽혔더라도 이 역시 파일의 일부이니 복사한다.
				puts("파일복사 완료");
				break;
			}
			else
				puts("파일복사 실패");

			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des); // 읽어들인, 배열 buf에 저장된 데이터를 파일에 저장
	}

	fclose(src);
	fclose(des);
	return 0;
}

// 추가적으로 복사 프로그램은 다음 성격을 지닌다고 한다.

// 1. Read / Write를 동시에 진행해야 하며,
// 2. 파일의 끝에 도달했는지를 확인해야 한다.