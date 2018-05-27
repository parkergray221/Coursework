#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int BigInt(int number)
{
    string s = to_string(number);
    size = string.size;
    for(int i = 0; i < size; i++){
        if (s[i] == '0'){
            cout << " @@@@@ "
                    "@@   @@"
                    "@@   @@"
                    "@@   @@"
                    "@@   @@"
                    "@@   @@"
                    " @@@@@ "
        } else if(s[i] == '1'){
            cout << "  @@   "
                    " @@@   "
                    "  @@   "
                    "  @@   "
                    "  @@   "
                    "  @@   "
                    "@@@@@@ "
        } else if(s[i] == '2'){
            cout << " @@@@  "
                    "@    @ "
                    "     @ "
                    "  @@@@ "
                    " @     "
                    "@      "
                    "@@@@@@ "
        }else if(s[i] == '3'){
            cout << " @@@@@ "
                    "@     @"
                    "      @"
                    " @@@@@@"
                    "      @"
                    "@     @"
                    " @@@@@@"
        }else if(s[i] == '4'){
            cout << "   @@@ "
                    "  @@ @@"
                    " @@  @@"
                    "@@@@@@@"
                    "     @@"
                    "     @@"
                    "     @@"
        }else if(s[i] == '5'){
            cout << " @@@@@@"
                    "@      "
                    "@      "
                    "@@@@@@ "
                    "      @"
                    "      @"
                    "@@@@@@"
        }else if(s{i] == '6'){
            cout << "  @@   "
                    " @@    "
                    "@@     "
                    "@@     "
                    " @@@@@ "
                    "@     @"
                    " @@@@@ "
        }else if(s[i] == '7'){
            cout << "@@@@@@@"
                    "     @@"
                    "    @@ "
                    "   @@  "
                    "  @@   "
                    " @@    "
                    "@@     "
        }else if(s[i] == '8'){
            cout << " @@@@@ "
                    "@@   @@"
                    "@@   @@"
                    "@@@@@@@"
                    "@@   @@"
                    "@@   @@"
                    " @@@@@ "
        }else if(s[i] == '9'){
            cout << " @@@@@ "
                    "@    @@"
                    "@    @@"
                    " @@@@@@"
                    "     @@"
                    "     @@"
                    "     @@"
        }
    }
    cout << endl;
}

int main(){
    int number = 12;
    BigInt(number);
}
