#include <iostream>
#include <vector> // for use vector file
#include <unordered_map> // To store key value and mapping value
#include <set> //Parameter number to be prossed

using namespace std;

// Terminal and non-terminal symbols
enum class SymbolType {
    Terminal,
    NonTerminal
};

// Production rule
struct Production {
    char left;
    string right;
};

// Calculate FIRST set for a given symbol
set<char> calculateFirst(const char symbol, const vector<Production>& productions, const unordered_map<char, SymbolType>& symbols) {
    set<char> firstSet;

    // If the symbol is a terminal, its FIRST set is itself
    if (symbols.at(symbol) == SymbolType::Terminal) {
        firstSet.insert(symbol);
        return firstSet;
    }

    // Otherwise, find the productions for this symbol and calculate FIRST
    for (const Production& production : productions) {
        if (production.left == symbol) {
            char firstChar = production.right[0];
            if (symbols.at(firstChar) == SymbolType::Terminal) {
                firstSet.insert(firstChar);
            } else {
                set<char> firstSubset = calculateFirst(firstChar, productions, symbols);
                firstSet.insert(firstSubset.begin(), firstSubset.end());
            }
        }
    }

    return firstSet;
}

// Calculate FOLLOW set for a given non-terminal symbol
set<char> calculateFollow(const char symbol, const vector<Production>& productions, const unordered_map<char, SymbolType>& symbols) {
    set<char> followSet;

    // Add '$' to the FOLLOW set of the start symbol
    if (symbol == 'S') {
        followSet.insert('$');
    }

    // Find productions where the symbol appears and calculate FOLLOW
    for (const Production& production : productions) {
        const string& rightSide = production.right;
        size_t pos = rightSide.find(symbol);
        
        while (pos != string::npos) {
            if (pos + 1 < rightSide.size()) {
                char nextChar = rightSide[pos + 1];
                if (symbols.at(nextChar) == SymbolType::Terminal) {
                    followSet.insert(nextChar);
                } else {
                    set<char> firstOfNext = calculateFirst(nextChar, productions, symbols);
                    followSet.insert(firstOfNext.begin(), firstOfNext.end());

                    // If FIRST includes epsilon, also add FOLLOW of the left symbol
                    if (firstOfNext.find('@') != firstOfNext.end()) {
                        set<char> followOfLeft = calculateFollow(production.left, productions, symbols);
                        followSet.insert(followOfLeft.begin(), followOfLeft.end());
                    }
                }
            } else {
                // If the symbol is at the end, calculate FOLLOW of the left symbol
                set<char> followOfLeft = calculateFollow(production.left, productions, symbols);
                followSet.insert(followOfLeft.begin(), followOfLeft.end());
            }

            pos = rightSide.find(symbol, pos + 1);
        }
    }

    return followSet;
}

int main() {
    // Example grammar productions
    vector<Production> productions = {
        {'S', "aABc"},
        {'A', "b"},
        {'A', "@"}, // Epsilon production
        {'B', "d"}
    };

    // Mapping of symbols to their types
    unordered_map<char, SymbolType> symbols = {
        {'S', SymbolType::NonTerminal},
        {'A', SymbolType::NonTerminal},
        {'B', SymbolType::NonTerminal},
        {'a', SymbolType::Terminal},
        {'b', SymbolType::Terminal},
        {'c', SymbolType::Terminal},
        {'d', SymbolType::Terminal}
    };

    // Calculate FIRST and FOLLOW sets for each non-terminal
    for (char nonTerminal = 'S'; nonTerminal <= 'B'; ++nonTerminal) {
        cout << "FIRST(" << nonTerminal << "): ";
        set<char> first = calculateFirst(nonTerminal, productions, symbols);
        for (char terminal : first) {
            cout << terminal << " ";
        }
        cout << endl;

        cout << "FOLLOW(" << nonTerminal << "): ";
        set<char> follow = calculateFollow(nonTerminal, productions, symbols);
        for (char terminal : follow) {
            cout << terminal << " ";
        }
        cout << endl;
    }

    return 0;
}
