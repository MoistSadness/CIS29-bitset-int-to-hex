#include <iostream>
#include <string>
#include <bitset>

// Original Function
std::string Decimal2HexOG(int digit){
    std::string snumber = "";
    while (digit > 0){
        int mod = digit % 16;
        switch (mod)
        {
        case 0:
            snumber += '0';
            break;
        case 1:
            snumber += '1';
            break;
        case 2:
            snumber += '2';
            break;
        case 3:
            snumber += '3';
            break;
        case 4:
            snumber += '4';
            break;
        case 5:
            snumber += '5';
            break;
        case 6:
            snumber += '6';
            break;
        case 7:
            snumber += '7';
            break;
        case 8:
            snumber += '8';
            break;
        case 9:
            snumber += '9';
            break;
        case 10:
            snumber += 'A';
            break;
        case 11:
            snumber += 'B';
            break;
        case 12:
            snumber += 'C';
            break;
        case 13:
            snumber += 'D';
            break;
        case 14:
            snumber += 'E';
            break;
        case 15:
            snumber += 'F';
            break;
        default:
            snumber += '-';
        }
        digit /= 16;
    }
    reverse(snumber.begin(), snumber.end());
    return snumber;
}

std::string Decimal2Hex(int digit){
    std::string snumber = "";
    std::bitset<16> bset(digit);         // 16 bit bitset
    std::bitset<16> mask(15);        // Create a mask to isolate the final 4 bits/ hex value (00001111 or 15 or F)

    while (bset.to_ulong() > 0){
        std::cout << bset.to_ulong() << "\t- " << bset.to_string();
        auto masked = bset & mask;
        std::string s;

        if (masked.to_ulong() < 10) {       // if the int value is less than ten , then it corresponds to the correct hex value
            s = std::to_string(masked.to_ulong());
        } else{                 // otherwise, it is larger than 10 and needs to be converted into one a letter hex character 
            s = 'A' + (masked.to_ulong() - 10);
        }

        std::cout << " - " << masked.to_string() << " - " << s << std::endl;
        snumber.append(s);

        bset >>= 4;
    }

    std::reverse(snumber.begin(), snumber.end());       // Reverse string 
    return snumber;
}

int main(){
    //std::cout << "Hello" << std::endl;
    int digit1 = 69, digit2 = 420, digit3 = 911;
    std::string originalFunctionOut, newFunctionOut;

    std::cout << " * Digit 1 \t" << digit1 << std::endl;
    originalFunctionOut =  Decimal2HexOG(digit1);
    newFunctionOut= Decimal2Hex(digit1);
    std::cout << "Original function\t" << digit1 << " -> " << originalFunctionOut << std::endl;
    std::cout << "New function\t\t" << digit1 << " -> " << newFunctionOut << std::endl << std::endl;

    std::cout << " * Digit 2 \t" << digit2 << std::endl;
    originalFunctionOut =  Decimal2HexOG(digit2);
    newFunctionOut= Decimal2Hex(digit2);    
    std::cout << "Original function\t" << digit2 << " -> " << originalFunctionOut << std::endl;
    std::cout << "New function\t\t" << digit2 << " -> " << newFunctionOut << std::endl << std::endl;

    std::cout << " * Digit 3 \t" << digit3 << std::endl;
    originalFunctionOut =  Decimal2HexOG(digit3);
    newFunctionOut= Decimal2Hex(digit3);    
    std::cout << "Original function\t" << digit3 << " -> " << originalFunctionOut << std::endl;
    std::cout << "New function\t\t" << digit3 << " -> " << newFunctionOut << std::endl << std::endl;

    return 0;
}
