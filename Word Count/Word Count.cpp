#include <stdio.h>
#include <stdlib.h>

/**
 * 编写统计文件的字符数的程序，主要学习文件的概念
 * 和文件操作等内容。
 */
int main(int argc, char* argv[])
{
	/** 保存字符个数 **/
	char flag;
	scanf_s("%c", &flag, sizeof(flag));
	if (flag == 'c') {
		int count = 0;
		/** 保存文件名 **/
		char fname[80] = {'\0'};
		/** 文件指针 **/
		FILE* fp;

		printf("Please enter the file name:");
		scanf_s("%s", fname, sizeof(fname));
		errno_t err = 0;
		if ((err = fopen_s(&fp, fname, "r")) != 0) {
			printf("Open file failed!!\n");
			exit(1);
		}

		count = 0;
		while (fgetc(fp) != EOF)
			count++;

		fclose(fp);

		printf("There are %d characters in file %s.\n", count, fname);

	}
	else {
		int count = 0;
		int c = 0;
		/** 保存文件名 **/
		char fname[80] = { '\0' };

		/** 文件指针 **/
		FILE* fp;

		printf("Please enter the file name:");
		scanf_s("%s", fname, sizeof(fname));
		errno_t err = 0;
		if ((err = fopen_s(&fp, fname, "r")) != 0) {
			printf("Open file failed!!\n");
			exit(1);
		}

		count = 1;
		while ((c = fgetc(fp)) != EOF)
		{
			count++;
			if (c != 32 && c != 44&&c!=10)
				count--;
				
		}

		fclose(fp);

		printf("There are %d words in file %s.\n", count, fname);

		return 0;

	}

}


