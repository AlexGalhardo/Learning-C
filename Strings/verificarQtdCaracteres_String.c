#include <stdio.h>

int main() {
    char *string = "aouihuiahsudasduihqmdoiqjnduiamsdoqnwuidamodkjwodkaposdj";
    int quantidade[26] = { 0 };
    for (; *string != '\0'; string++) {
        quantidade[*string - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        printf("%c => %d\n", i + 'a', quantidade[i]);
    }
    
    return 0;
}
