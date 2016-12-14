#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/*Petter Nordin Linus Vintervinge*/
void split_text(char str[]) {
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ')
			str[i] = '\n';
		i++;
	}

}

void case_letter(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		++i;
	}

}

void smallcase_letter(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
		++i;
	}
}

/*void remove_ch(char * p, char c)
{
if (NULL == p)
return;
char * pDest = p; // points to start of string
while (*p)
{
if (*p != c)
*pDest++ = *p;
p++;
}
*pDest = '\0';
}

*/

void remove_ch(char str[], char str2[], char ch) {
	int i = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] != ch) {
			str2[j] = str[i];
			j++;
			i++;
		}
		else
			i++;

	}

	str2[j] = '\0';
}

/*
void input_ch(char str[], char str2[], char ch) {
	int i = 0, j = 0;
	while (str[i] != '\0') {
		str2[j] = str[i];
		j++;
		i++;
		if (str[i] == ' ') {
			str2[j] = str[i];
			j++;
			str2[j] = ch;
			j++;
			i++;
		}
		else
			i++;

	}

	str2[j] = '\0';
}
*/
void input_ch(char str[], char str2[], char ch) {
	int i = 0, j = 0;
	str[strlen(str) - 1] = '\0';
	while (str[i] != '\0') {
		
		if (str[i] != ' ') {
			str2[j] = str[i];
			j++;
			i++;
		}
		else if (str[i] == ' ')
		{
			str2[j] = ch;
			j++;
			str2[j] = str[i];
			j++;
			i++;
		}
		else
		i++;

	}
	str2[j] = ch;
	j++;
	str2[j] = '\0';
}



void count_ch(char str[], int count[]) {
	int c = 0;

	while (str[c] != '\0') {
		if (str[c] >= 'a' && str[c] <= 'z')
			count[str[c] - 'a']++;
		c++;
	}
}





int main() {
	char str2[100];
	char ch;
	char str[100];
	int textmenu = 0;
	int c, count[128] = { 0 };
	// 128???

	while (textmenu != 8) {
		printf("Enter a number of choice in the textmenu:\n 1.Split text\n 2.Upper case to lower case\n 3.Lower case to upper case\n 4.Remove a character\n 5.Add a character\n 6.Replace a character\n 7.Statistics\n 8.Exit\n ");
		printf("Enter 1-8 from textmenu:\n");
		scanf("%d", &textmenu);
		getchar(); /*getchar() funktion är......*/

		switch (textmenu) {
		case 1:
			printf("You Entered 1.Split text\n");
			printf("Enter a string:");
			fgets(str, 100, stdin);
			split_text(str);
			printf("%s\n", str);
			break;
		case 2:
			printf("You Entered 2.Upper case to lower case\n");
			printf("Enter a string:");
			fgets(str, 100, stdin);
			case_letter(str);
			printf("%s\n", str);
			break;
		case 3:
			printf("You Entered 3.Lower case to upper case\n");
			printf("Enter a string:");
			fgets(str, 100, stdin);
			smallcase_letter(str);
			printf("%s\n", str);
			break;
		case 4:
			printf("You Entered 4.Remove a character\n");
			printf("Enter a string:");
			fgets(str, 100, stdin);
			printf("Enter char to remove:");
			ch = getchar();
			remove_ch(str, str2, ch);
			printf("%s\n", str2);
			break;
		case 5:
			printf("You Entered 5. Input a character\n");
			printf("Enter a string:");
			fgets(str, 100, stdin);
			printf("Enter char to input:");
			ch = getchar();
			input_ch(str, str2, ch);
			printf("%s\n", str2);
			break;
		case 6:
			//add horse here



			break;
		case 7:
			printf("You Entered 7. Statistics\n");
			printf("Enter a string:");
			fgets(str, 100, stdin);
			count_ch(str, count);
			for (c = 0; c < 26; c++)
				printf("%c \t  %d\n", c + 'a', count[c]);
			//printf("%s\n", str2);
			break;


			break;
		case 8:
			break;
		default:
			printf("");
		}
	}
}