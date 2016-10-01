#include <string>
#include <iostream>
#include <vector>
#include <cctype>

typedef std::vector<std::string> string_vector;

bool is_single_char_tok(char c) {
    return c == '(' || c == ')';
}

void push_and_clear_current_token(string_vector & tokens,
                                  std::string & current_token) {
    if (!current_token.empty()) {
        tokens.push_back(current_token);
        current_token.clear();
    }
}

string_vector tokenize(std::string input) {
    using namespace std;

    string_vector tokens; // tokens.reserve(100) ?
    string current_token;
    current_token.reserve(10); // magic number

    bool is_comment = false;
    bool is_string = false;

    for (auto c : input) {
        if (is_comment) {
            if (c == '\n') is_comment = false;
            continue;
        }

        if (is_string) {
            if (c != '\n') current_token.push_back(c);
            if (c == '"') {
                is_string = false;
                push_and_clear_current_token(tokens, current_token);
            }
            continue;
        }

        if (isspace(c)) {
            push_and_clear_current_token(tokens, current_token);
        } else if (is_single_char_tok(c)) {
            push_and_clear_current_token(tokens, current_token);
            tokens.push_back(string(1, c));
        } else if (c == ';') {
            push_and_clear_current_token(tokens, current_token);
            is_comment = true;
        } else if (c == '"') {
            push_and_clear_current_token(tokens, current_token);
            is_string = true;
            current_token.push_back(c);
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
    getline(cin, input, '|');

    string_vector tokens = tokenize(input);
    for (auto token : tokens)
        cout << token << endl;
}
