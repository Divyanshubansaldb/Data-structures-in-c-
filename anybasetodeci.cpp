//use stoll function
// CPP code for illustration
// of stoll() function.
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // converting decimal number.
    string dec_num = "9876543210";
    cout << "dec_num = " << stoll(dec_num, nullptr, 10) << "\n ";

    // converting hexadecimal number.
    string hex_num = "FFFFFF";
    cout << "hex_num = " << stoll(hex_num, nullptr, 16) << "\n";

    // converting binary number.
    string binary_num = "1111111";
    cout << "binary_num = " << stoll(binary_num, nullptr, 2) << "\n";

    return 0;
}

// to convert from number to string use to_string() function
//

/* itoa example */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char buffer[33];
    printf("Enter a number: ");
    scanf("%d", &i);
    itoa(i, buffer, 10);
    printf("decimal: %s\n", buffer);
    itoa(i, buffer, 16);
    printf("hexadecimal: %s\n", buffer);
    itoa(i, buffer, 2);
    printf("binary: %s\n", buffer);
    return 0;
}


////use ostream for conversion from decimal to string