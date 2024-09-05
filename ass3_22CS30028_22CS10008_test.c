
/* Multi-line comment test */
// Single-line comment test

// Keywords test
auto enum restrict unsigned break extern return void
case float short volatile char for signed while
const goto sizeof _Bool continue if static _Complex
default inline struct _Imaginary do int switch
double long typedef else register union

// Identifier test
int main() {
    int x1;
    float var_2;
    char _char3;

    // Constant test
    int num = 12345;  // Integer constant
    float decimal = 6.022e23;  // Floating constant with exponent
    float small = .00012;  // Floating constant starting with a dot
    char letter = 'B';  // Character constant
    char newline = '\n';  // Escape sequence in character constant

    // String literal test
    char* greeting = "Hello, lexer!";
    char* esc_string = "Special characters: \t \n \\ \" \0";

    // Punctuator test
    int matrix[5][5];  // [ ] 
    int *ptr_x = &x1;  // & *
    num++;  // ++
    num--;  // --
    int y = num - 2;  // -
    int z = num * 3;  // *
    int div = num / 4;  // /
    int mod = num % 5;  // %
    int left_shift = num << 2;  // <<
    int right_shift = num >> 3;  // >>
    if (x1 > y && y < z) {}  // > < &&
    if (x1 >= z || z <= y) {}  // >= <= ||
    int ternary = (x1 != y) ? x1 : y;  // != ? :
    num *= 10;  // *=
    y /= 2;  // /=
    z += 3;  // +=
    div -= 1;  // -=
    mod %= 2;  // %=
    left_shift <<= 1;  // <<=
    right_shift >>= 1;  // >>=
    int bitwise_not = ~num;  // ~
    int logical_not = !num;  // !

    // More complex expressions test
    int compute = (x1 + y) - (z * div) / (mod % left_shift);

    // Ellipsis test
    void custom_func(char arg, ...);

    // Arrow operator test
    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 100;
    head->next = NULL;

    return 0;
}

// Edge case tests
#define PI 3.14  // Testing '#' punctuator
float pi_fraction = .314;    // Floating constant starting with dot
char* quote_string = "This \"string\" has quotes inside.";

