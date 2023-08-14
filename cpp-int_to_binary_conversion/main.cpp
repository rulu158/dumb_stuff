#include <iostream>
#include <cmath>
#include <string>

std::string convert_int_to_binary(int num, int bits = 8);
std::string format_bits(std::string bits);
std::string invert_bits(std::string bits);

int main() {
    std::cout << "Number 0 in binary (max_bits=8): " << convert_int_to_binary(0) << std::endl;
    std::cout << "Number 256 in binary (max_bits=8): " << convert_int_to_binary(256) << std::endl;
    std::cout << "Number 2 in binary (max_bits=8): " << convert_int_to_binary(2) << std::endl;
    std::cout << "Number 4 in binary (max_bits=8): " << convert_int_to_binary(4) << std::endl;
    std::cout << "Number 8 in binary (max_bits=8): " << convert_int_to_binary(8) << std::endl;
    std::cout << "Number 5 in binary (max_bits=8): " << format_bits(convert_int_to_binary(5)) << std::endl;
    std::cout << "Number 256 in binary (9 bits): " << convert_int_to_binary(256, 9) << std::endl;
}

std::string convert_int_to_binary(int num, int max_bits) {
    if ((std::pow(2.0, max_bits) - 1) < num || max_bits < 1) {
        return "ERROR: max_bits is too small";
    }

    std::string num_in_bits {};
    for (int i {max_bits - 1}; i >= 0; --i) {
        if (num - std::pow(2.0, i) >= 0) {
            num_in_bits += "1";
	    num -= std::pow(2.0, i);
        } else {
            num_in_bits += "0";
        }
    }

    return num_in_bits;
}

std::string format_bits(std::string bits) {
    const int bits_per_group {4};

    std::string formated_bits {};
    std::string inverted_bits {invert_bits(bits)};

    for (size_t i {}; i < inverted_bits.length(); ++i) {
	std::string current_bit (1, inverted_bits[i]);
	formated_bits += current_bit;

        if ((i + 1) % bits_per_group == 0) {
	    formated_bits += " ";
	}
    }

    return invert_bits(formated_bits);
}

std::string invert_bits(std::string bits) {
    std::string inverted_bits {};

    for (size_t i {bits.length()}; i --> 0;) {
	std::string current_bit (1, bits[i]);
        inverted_bits += current_bit;
    }

    if (inverted_bits[0] == ' ') {
	inverted_bits = inverted_bits.substr(1);
    }

    return inverted_bits;
}
