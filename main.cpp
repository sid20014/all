void q1{
    #include<iostream>
    #include<string>
    using namespace std;

    void state0(string w, int i);
    void state1(string w, int i);
    void state2(string w, int i);
    void state3(string w, int i);

    void state0(string w, int i){
        cout << "State 0\n";
        if(i == w.length()){
            cout << "String is Rejected.\n";
            return;
        }
        if(w[i] == '0') state0(w, i + 1);
        else if(w[i] == '1') state1(w, i + 1);
    }

    void state1(string w, int i){
        cout << "State 1\n";
        if(i == w.length()){
            cout << "String is Rejected.\n";
            return;
        }
        if(w[i] == '0') state0(w, i + 1);
        else if(w[i] == '1') state2(w, i + 1);
    }

    void state2(string w, int i){
        cout << "State 2\n";
        if(i == w.length()){
            cout << "String is Rejected.\n";
            return;
        }
        if(w[i] == '0') state0(w, i + 1);
        else if(w[i] == '1') state3(w, i + 1);
    }

    void state3(string w, int i){
        cout << "State 3 (Accepting State)\n";
        if(i == w.length()){
            cout << "String is Accepted.\n";
            return;
        }
        // After reaching state 3, we stay in state 3 for any input
        if(w[i] == '0') state3(w, i + 1);
        else if(w[i] == '1') state3(w, i + 1);
    }

    int main(){
        string w;
        cout << "Enter string: ";
        cin >> w;

        state0(w, 0);  // Start from state 0

        return 0;
}
}
void q2{
            #include<iostream>
    #include<string>
    using namespace std;

    void state0(string w, int i);
    void state1(string w, int i);
    void state2(string w, int i);
    void state3(string w, int i);
    void state4(string w, int i);

    void state0(string w, int i){
        cout << "State 0\n";
        if(i == w.length()){
            cout << "String is Rejected.\n";
            return;
        }
        if(w[i] == '0') state0(w, i + 1);
        else if(w[i] == '1') state1(w, i + 1);
    }

    void state1(string w, int i){
        cout << "State 1\n";
        if(i == w.length()){
            cout << "String is Rejected.\n";
            return;
        }
        if(w[i] == '0') state1(w, i + 1);
        else if(w[i] == '1') state2(w, i + 1);
    }

    void state2(string w, int i){
        cout << "State 2\n";
        if(i == w.length()){
            cout << "String is Accepted (Exactly 2 `1`s).\n";
            return;
        }
        if(w[i] == '0') state2(w, i + 1);
        else if(w[i] == '1') state3(w, i + 1);
    }

    void state3(string w, int i){
        cout << "State 3\n";
        if(i == w.length()){
            cout << "String is Accepted (Exactly 3 `1`s).\n";
            return;
        }
        if(w[i] == '0') state3(w, i + 1);
        else if(w[i] == '1') state4(w, i + 1);
    }

    void state4(string w, int i){
        cout << "State 4\n";
        if(i == w.length()){
            cout << "String is Rejected.\n";
            return;
        }
        // Stay in State 4 for any input
        if(w[i] == '0' || w[i] == '1') state4(w, i + 1);
    }

    int main(){
        string w;
        cout << "Enter string: ";
        cin >> w;

        state0(w, 0);  // Start at state 0

        return 0;
    }

}
void q3{
        #include <iostream>
    #include <string>
    using namespace std;

    void state0(string w, int i, char first, char second);
    void state1(string w, int i, char first, char second);
    void state2(string w, int i, char first, char second);
    void state3(string w, int i, char first, char second);
    void state4(string w);
    void stateReject(string w);

    void state0(string w, int i, char first, char second) {
        cout << "State 0\n";
        if (i >= w.length()) {
            stateReject(w);
            return;
        }
        state1(w, i + 1, w[i], second);  // Store first character
    }

    void state1(string w, int i, char first, char second) {
        cout << "State 1\n";
        if (i >= w.length()) {
            stateReject(w);
            return;
        }
        state2(w, i + 1, first, w[i]);  // Store second character
    }

    void state2(string w, int i, char first, char second) {
        cout << "State 2\n";
        if (i >= w.length()) {
            stateReject(w);
            return;
        }
        state3(w, i + 1, first, second);  // Process middle part of the string
    }

    void state3(string w, int i, char first, char second) {
        cout << "State 3\n";
        if (i >= w.length()) {
            // Check last two characters with the first two
            if (w[w.length() - 2] == first && w[w.length() - 1] == second) {
                state4(w);
            } else {
                stateReject(w);
            }
            return;
        }
        state3(w, i + 1, first, second);  // Continue processing the middle
    }

    void state4(string w) {
        cout << "State 4\n";
        cout << "String is Accepted.\n";
    }

    void stateReject(string w) {
        cout << "State Reject\n";
        cout << "String is Rejected.\n";
    }

    int main() {
        string w;
        cout << "Enter string: ";
        cin >> w;

        if (w.length() < 4) {
            cout << "State Reject\n";
            cout << "String is Rejected (Length < 4).\n";
            return 0;
        }

        state0(w, 0, '\0', '\0');  // Start at state 0

        return 0;
    }

}
void q4{
        #include <iostream>
    #include <string>
    using namespace std;

    void state0(string w, int i);
    void state1(string w, int i);
    void state2(string w);
    void stateReject();

    void state0(string w, int i) {
        cout << "State 0\n";
        if (i >= w.length()) {
            stateReject();
            return;
        }
        if (w[i] == 'a') {
            state1(w, i + 1);  // Move to State 1 if the first character is 'a'
        } else {
            stateReject();  // Reject if the first character is not 'a'
        }
    }

    void state1(string w, int i) {
        cout << "State 1\n";
        if (i >= w.length()) {
            stateReject();  // Reject if the string ends without a 'b'
            return;
        }
        if (w[i] == 'b' && i == w.length() - 1) {
            state2(w);  // Move to State 2 if 'b' is the last character
        } else {
            state1(w, i + 1);  // Stay in State 1 to process the middle characters
        }
    }

    void state2(string w) {
        cout << "State 2\n";
        cout << "String is Accepted.\n";
    }

    void stateReject() {
        cout << "State Reject\n";
        cout << "String is Rejected.\n";
    }

    int main() {
        string w;
        cout << "Enter string: ";
        cin >> w;

        if (w.length() < 2) {
            cout << "State Reject\n";
            cout << "String is Rejected (Length < 2).\n";
            return 0;
        }

        state0(w, 0);  // Start at state 0

        return 0;
    }

}
void q5{
        #include <iostream>
    #include <string>
    using namespace std;

    void q00(string w, int i);
    void q01(string w, int i);
    void q10(string w, int i);
    void q11(string w, int i);

    void q00(string w, int i) {
        cout << "State q00 (Even a's, Even b's)\n";
        if (i == w.length()) {
            cout << "String is Accepted.\n";
            return;
        }
        if (w[i] == 'a') {
            q10(w, i + 1);  // Move to q10 (Odd a's)
        } else if (w[i] == 'b') {
            q01(w, i + 1);  // Move to q01 (Odd b's)
        } else {
            cout << "Invalid character encountered. String is Rejected.\n";
        }
    }

    void q01(string w, int i) {
        cout << "State q01 (Even a's, Odd b's)\n";
        if (i == w.length()) {
            cout << "String is Rejected.\n";
            return;
        }
        if (w[i] == 'a') {
            q11(w, i + 1);  // Move to q11 (Odd a's, Odd b's)
        } else if (w[i] == 'b') {
            q00(w, i + 1);  // Move to q00 (Even a's, Even b's)
        } else {
            cout << "Invalid character encountered. String is Rejected.\n";
        }
    }

    void q10(string w, int i) {
        cout << "State q10 (Odd a's, Even b's)\n";
        if (i == w.length()) {
            cout << "String is Rejected.\n";
            return;
        }
        if (w[i] == 'a') {
            q00(w, i + 1);  // Move to q00 (Even a's, Even b's)
        } else if (w[i] == 'b') {
            q11(w, i + 1);  // Move to q11 (Odd a's, Odd b's)
        } else {
            cout << "Invalid character encountered. String is Rejected.\n";
        }
    }

    void q11(string w, int i) {
        cout << "State q11 (Odd a's, Odd b's)\n";
        if (i == w.length()) {
            cout << "String is Rejected.\n";
            return;
        }
        if (w[i] == 'a') {
            q01(w, i + 1);  // Move to q01 (Even a's, Odd b's)
        } else if (w[i] == 'b') {
            q10(w, i + 1);  // Move to q10 (Odd a's, Even b's)
        } else {
            cout << "Invalid character encountered. String is Rejected.\n";
        }
    }

    int main() {
        string w;
        cout << "Enter string (over {a, b}): ";
        cin >> w;

        if (w.empty()) {
            cout << "State q00\n";
            cout << "String is Accepted (Empty string is valid).\n";
            return 0;
        }

        q00(w, 0);  // Start at q00 (Even a's, Even b's)

        return 0;
    }

}
void q6{
        #include <iostream>
    #include <string>
    using namespace std;

    // FA for L1: a*b
    bool L1(string w) {
        int state = 0; // Start state
        for (char c : w) {
            if (state == 0 && c == 'a') state = 0; // Stay in state 0 for 'a'
            else if (state == 0 && c == 'b') state = 1; // Move to state 1 on 'b'
            else if (state == 1) return false; // Invalid transition
        }
        return state == 1; // Accept if in state 1
    }

    // FA for L2: ab*
    bool L2(string w) {
        int state = 0; // Start state
        for (char c : w) {
            if (state == 0 && c == 'a') state = 1; // Move to state 1 on 'a'
            else if (state == 1 && c == 'b') state = 1; // Stay in state 1 for 'b'
            else return false; // Invalid transition
        }
        return state == 1; // Accept if in state 1
    }

    // Union (L1 U L2)
    bool Union(string w) {
        return L1(w) || L2(w);
    }

    // Intersection (L1 ∩ L2)
    bool Intersection(string w) {
        return L1(w) && L2(w);
    }

    // Concatenation (L1L2)
    bool Concatenation(string w) {
        for (size_t i = 1; i < w.length(); ++i) {
            string prefix = w.substr(0, i);
            string suffix = w.substr(i);
            if (L1(prefix) && L2(suffix)) {
                return true; // If L1 accepts prefix and L2 accepts suffix
            }
        }
        return false;
    }

    int main() {
        string w;
        cout << "Enter a string: ";
        cin >> w;

        // Simulate Union
        if (Union(w)) {
            cout << "String is accepted by Union (L1 U L2).\n";
        } else {
            cout << "String is rejected by Union (L1 U L2).\n";
        }

        // Simulate Intersection
        if (Intersection(w)) {
            cout << "String is accepted by Intersection (L1 ∩ L2).\n";
        } else {
            cout << "String is rejected by Intersection (L1 ∩ L2).\n";
        }

        // Simulate Concatenation
        if (Concatenation(w)) {
            cout << "String is accepted by Concatenation (L1L2).\n";
        } else {
            cout << "String is rejected by Concatenation (L1L2).\n";
        }

        return 0;
    }

}
void q7{
        #include <iostream>
    #include <stack>
    #include <string>
    using namespace std;

    // PDA Simulation
    bool simulatePDA_anbn(string w) {
        stack<char> st;
        int state = 0; // Initial state

        for (char c : w) {
            if (state == 0) {
                if (c == 'a') {
                    st.push('A'); // Push 'A' for each 'a'
                } else if (c == 'b' && !st.empty()) {
                    st.pop(); // Pop for each 'b'
                } else {
                    return false; // Invalid symbol or unmatched 'b'
                }
            }
        }

        // Accept if stack is empty
        return st.empty();
    }

    int main() {
        string w;
        cout << "Enter string for L = {a^n b^n | n > 0}: ";
        cin >> w;

        if (simulatePDA_anbn(w)) {
            cout << "String is accepted.\n";
        } else {
            cout << "String is rejected.\n";
        }

        return 0;
    }

}
void q8{
        #include <iostream>
    #include <stack>
    #include <string>
    using namespace std;

    // PDA Simulation
    bool simulatePDA_wXwr(string w) {
        stack<char> st;
        int state = 0; // Initial state
        for (char c : w) {
            if (state == 0) {
                if (c == 'X') {
                    state = 1; // Transition to the second phase after 'X'
                } else {
                    st.push(c); // Push all characters of w onto the stack
                }
            } else if (state == 1) {
                if (!st.empty() && c == st.top()) {
                    st.pop(); // Pop and compare for w^R
                } else {
                    return false; // Mismatch or extra characters
                }
            }
        }

        // Accept if stack is empty
        return st.empty();
    }

    int main() {
        string w;
        cout << "Enter string for L = {wXw^R | w in {a, b}*}: ";
        cin >> w;

        if (simulatePDA_wXwr(w)) {
            cout << "String is accepted.\n";
        } else {
            cout << "String is rejected.\n";
        }

        return 0;
    }

}
void q9{
        #include <iostream>
#include <string>

using namespace std;

bool turing_machine(string input) {
    int a_count = 0, b_count = 0, c_count = 0;
    int i = 0;

    while (i < input.length()) {
        if (input[i] == 'a') {
            a_count++;
            i++;
        } else if (input[i] == 'b' && a_count > b_count) {
            b_count++;
            i++;
        } else if (input[i] == 'c' && b_count > c_count) {
            c_count++;
            i++;
        } else {
            return false; // Invalid input
        }
    }

    return a_count == b_count && b_count == c_count;
}

int main() {
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    if (turing_machine(input)) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}

}
void q10{
    #include <iostream>
 #include <string>
 using namespace std;
 string incrementBinary(string tape) {
    int head = tape.length() - 1; // Start at the rightmost bit (LSB)
    while (head >= 0) {
        if (tape[head] == '0') {
            // If the current bit is 0, change it to 1 and halt
            tape[head] = '1';
            return tape;
        } else if (tape[head] == '1') {
            // If the current bit is 1, change it to 0 and move left
            tape[head] = '0';
        } else {
            // Invalid character in the tape
            throw invalid_argument("Invalid binary number");
        }
        head--; // Move the head left
    }
    return "1" + tape;
 }
 int main() {
    string testCases[] = {"0", "1", "10", "11", "101", "111", "1000", ""};
    for (const string& test : testCases) {
        try {
cout << "Input: \"" << test << "\" -> Output: \"" << incrementBinary(test) << "\"" << endl;
 } catch (const invalid_argument& e) {
 cout << "Input: \"" << test << "\" -> Error: " << e.what() << endl;
 }
 }
 return 0;
 }}





Extra Question 3
    #include <iostream>
using namespace std;

void state2(string, int);
void state3(string, int);
void state4(string, int);
void state5(string, int);
void state6(string, int);
void state7(string, int);
void state8(string, int);
void state9(string, int);
void state10(string, int);
void state11(string, int);
void state12(string, int);
void state13(string, int);
void state14(string, int);
void state15(string, int);

void state1(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state2(w, i + 1);
        else
            state9(w, i + 1);
    }
}

void state2(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state3(w, i + 1);
        else
            state6(w, i + 1);
    }
}

void state3(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state4(w, i + 1);
        else
            state3(w, i + 1);
    }
}

void state4(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
        {
        if (w[i] == 'a')
            state5(w, i + 1);
        else
            state3(w, i + 1);
    }
}

void state5(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state5(w, i + 1);
        else
            state3(w, i + 1);
    }
}

void state6(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state7(w, i + 1);
        else
            state6(w, i + 1);
    }
}

void state7(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state7(w, i + 1);
        else
            state8(w, i + 1);
    }
}

void state8(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state7(w, i + 1);
        else
            state6(w, i + 1);
    }
}

void state9(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state10(w, i + 1);
        else
            state13(w, i + 1);
    }
}

void state10(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state10(w, i + 1);
        else
            state11(w, i + 1);
    }
}

void state11(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state12(w, i + 1);
        else
            state11(w, i + 1);
    }
}

void state12(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state10(w, i + 1);
        else
            state11(w, i + 1);
    }
}

void state13(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state13(w, i + 1);
        else
            state14(w, i + 1);
    }
}

void state14(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state13(w, i + 1);
        else
            state15(w, i + 1);
    }
}

void state15(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state13(w, i + 1);
        else
            state15(w, i + 1);
    }
}

int main()
{
    string w;
    cout << "Enter the string that you want to test (a's and b's): ";
    cin >> w;
    state1(w, 0);
    return 0;
}
