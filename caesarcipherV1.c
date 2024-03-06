# include <stdio.h>

void encrypt (char *text){
	while (*text){
		if(*text >= 'a' && *text <= 'z')
			*text = ((*text - 'a' + 3) % 26) + 'a';
		else if (*text >= 'A' && *text <= 'Z')
			*text = ((*text - 'A' + 3) % 26) + 'A';
		text++;
	}
}
void decrypt (char *text){
	while (*text){
		if(*text >= 'a' && *text <= 'z')
			*text = ((*text - 'a' - 3) % 26) + 'a';
		else if (*text >= 'A' && *text <= 'Z')
			*text = ((*text - 'A' - 3) % 26) + 'A';
		text++;
	}
}
int main(){
	char text[100];
	printf("Enter text: ");
	scanf("%[^\n]s", text);
	getchar();

	encrypt(text);
	printf("Encrypted text: %s \n", text);

	decrypt(text);
	printf("Decrypted text: %s \n", text);

	return 0;
}
