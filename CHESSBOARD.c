#include <stdio.h>
#include <string.h>

const char* determine_color(const char* s) {
    char col = s[0];            // first character (column, like 'a', 'b', ...)
    int row = s[1] - '0';       // second character (row, like '1', '2', ...)

    int col_num = col - 'a' + 1; // convert column to number (a=1, b=2, ...)

    // a1 is Black → so if (col_num + row) % 2 == 0 → Black
    if ((col_num + row) % 2 == 0)
        return "Black";
    else
        return "White";
}

int main() {
    char s[256];
    scanf("%s", s);
    const char* result = determine_color(s);
    printf("%s\n", result);
    return 0;
}

