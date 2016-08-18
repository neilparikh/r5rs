#include <string>
#include <iostream>
#include <vector>

bool is_whitespace(char c) {
    return c == '\n' || c == ' ';
}

bool is_single_char_tok(char c) {
    return c == '(' || c == ')';
}

void push_and_clear_current_token(std::vector<std::string> & tokens,
                                  std::string & current_token) {
    if (!current_token.empty()) {
        tokens.push_back(current_token);
        current_token.clear();
    }
}

std::vector<std::string> input_to_tokens(std::string input) {
    using namespace std;

    vector<string> tokens; // tokens.reserve(100) ?
    string current_token;
    current_token.reserve(10); // magic number

    for (auto c : input) {
        if (is_whitespace(c)) {
            push_and_clear_current_token(tokens, current_token);
        } else if (is_single_char_tok(c)) {
            push_and_clear_current_token(tokens, current_token);
            tokens.push_back(string(1, c));
        } else {
            current_token.push_back(c);
        }
    }
    push_and_clear_current_token(tokens, current_token);

    return tokens;
}

int main() {
    using namespace std;
    string input;
    getline(cin, input, ';');

    vector<string> tokens = input_to_tokens(input);
    for (auto token : tokens)
        cout << token << endl;
}
