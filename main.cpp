#include <iostream>
#include "tokenizer.h"

int main() {
    using namespace std;
    string input;
    getline(cin, input, '|');

    string_vector tokens = tokenize(input);
    for (auto token : tokens)
        cout << token << endl;
}
